#ifdef __MAKECINT__
#pragma link C++ class vector<vector<float> >+;
#endif

#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TF1.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TVirtualFitter.h"
#include "TPaveText.h"
#include "TProfile.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TColor.h"
#include "TGraphErrors.h"
#include "TLatex.h"
#include "TGaxis.h"
#include "TPad.h"
#include <math.h> 

void MakeAmplitudePlot(std::string filename, std::string outname, float electronIDcut) {
  // Get the tree


  TFile *inputfile = new TFile(filename.c_str(),"READ");
  TTree *tree = (TTree*)inputfile->Get("pulse");

  // get the variables from the ntuple
  Float_t amp[36];
  Float_t integral[36];
  Float_t gauspeak[36];

  tree->SetBranchStatus("*",0);
  tree->SetBranchStatus("amp",1);
  tree->SetBranchStatus("int",1);
  tree->SetBranchStatus("gauspeak",1);

  tree->SetBranchAddress("amp",&amp);
  tree->SetBranchAddress("int",&integral);
  tree->SetBranchAddress("gauspeak",&gauspeak);

  //create histograms
  const int nBinsX = 25;
  const float Xrange = 20*nBinsX;

  TProfile * DeltaT_vs_Charge = new TProfile("DeltaT_vs_Charge", "DeltaT_vs_Charge", nBinsX, 0, Xrange, 2, 4);
  TH2F *DeltaT_vs_Charge_Corrected = new TH2F("DeltaT_vs_Charge_Corrected","; X; Y", nBinsX, 0, Xrange, 120, -2, 2);
  TH1F *Charge = new TH1F("Charge","Charge", nBinsX, 0, Xrange);
  TH1F *DeltaT = new TH1F("DeltaT","DeltaT", 200, -1.,1.);

  //read all entries and fill the histograms
  Long64_t nentries = tree->GetEntries();
  std::cout<<"Number of events in Physics Sample: "<<nentries<<std::endl;  

  for (Long64_t iEntry=0;iEntry<nentries;iEntry++) {
    
    tree->GetEntry(iEntry);    

    if ( iEntry%1000 == 0 ) std::cout << "event: " << iEntry << std::endl;
    
    // select electron showers and reject saturated events
    if(amp[18] > electronIDcut && amp[21]<0.48 && amp[18]<0.48 )
      {
	DeltaT_vs_Charge->Fill(10*integral[21], gauspeak[18]-gauspeak[21]);
	Charge->Fill(10*integral[21]);
      }
  }

  // select maximum range in charge where the time walk correction is extracted
  float maxX = 0;
  for(int i=1; i<Charge->GetNbinsX(); i++)
    if(Charge->GetBinContent(i)<10) 
      {
	maxX = Charge->GetBinLowEdge(i);
	break;
      }

  // extract the time walk correction
  TF1* fslopecorr = new TF1("fslopecorr","pol2", 0, maxX);
  DeltaT_vs_Charge->Fit("fslopecorr","Q","", 0, maxX);
  
  // get the correction parameters
  float a = fslopecorr->GetParameter(0);
  float b = fslopecorr->GetParameter(1);
  float c = fslopecorr->GetParameter(2);
  
  
  // apply the slope correction
  for (Long64_t iEntry=0;iEntry<nentries;iEntry++) 
    {      
      tree->GetEntry(iEntry);  
      
      if ( iEntry%1000 == 0 ) std::cout << "event: " << iEntry << std::endl;

      // select electron showers and reject saturated events, applying the slope correction      
      if(amp[18] > electronIDcut && amp[21]<0.48 && amp[18]<0.48 )
	{
	  float x = 10*integral[21];
	  DeltaT_vs_Charge_Corrected->Fill(10*integral[21], gauspeak[18]-gauspeak[21] - (a + b*x + c*x*x));
	  DeltaT->Fill(gauspeak[18]-gauspeak[21] - (a + b*x + c*x*x));
	}
   }
  
  // make the sigmaT vs integral plot

  float res[nBinsX]    = {0.}; 
  float charge[nBinsX] = {0.};
  float errorX[nBinsX] = {0.}; 
  float errorY[nBinsX] = {0.};

  for(int i = 0; i < DeltaT_vs_Charge_Corrected->GetNbinsX(); i++)
    {
      TH1F* fHprojy = (TH1F*)DeltaT_vs_Charge_Corrected->ProjectionY("fHprojy", i, i+1);
      

      TF1* fgaus = new TF1("fgaus","gaus", fHprojy->GetMean() - 2*fHprojy->GetRMS(), fHprojy->GetMean() + 2*fHprojy->GetRMS());
      fHprojy->Fit("fgaus","Q","", fHprojy->GetMean() - 2*fHprojy->GetRMS(), fHprojy->GetMean() + 2*fHprojy->GetRMS());
      
      TF1* fgaus2 = new TF1("fgaus2","gaus", fgaus->GetParameter(1) -  2*fgaus->GetParameter(2), fgaus->GetParameter(1) +  2*fgaus->GetParameter(2) );
      fHprojy->Fit("fgaus2","Q","", fgaus->GetParameter(1) -  2*fgaus->GetParameter(2), fgaus->GetParameter(1) +  2*fgaus->GetParameter(2) );

      TCanvas *cv = new TCanvas("cv","cv", 600, 600);
      
      fHprojy->Draw();
      cv->SaveAs(Form("plots/fHprojy_%d.pdf",i));
      
      res[i]    = fgaus2->GetParameter(2);
      charge[i] = DeltaT_vs_Charge_Corrected->GetXaxis()->GetBinCenter(i+1);
      errorX[i] = 0.0;
      errorY[i] = fgaus2->GetParError(2);

      if(fHprojy->GetEntries() < 10 ) { res[i] = -1.; errorY[i] = 0; }
      
   }
  
  TGraphErrors* gr = new TGraphErrors( nBinsX, charge, res, errorX, errorY );
  gr->SetTitle("");
  gr->SetMarkerStyle(8);
  gr->GetXaxis()->SetTitle("Charge [pC]");
  gr->GetXaxis()->SetTitleSize(0.045);
  gr->GetXaxis()->SetLabelSize(0.045);
  gr->GetXaxis()->SetTitleOffset(1.0);
  gr->GetYaxis()->SetTitle("#sigma_{T} [nsec]");
  gr->GetYaxis()->SetTitleOffset(1.02);
  gr->GetYaxis()->SetTitleSize(0.045);
  gr->GetYaxis()->SetLabelSize(0.045);
  gr->GetXaxis()->SetRangeUser(0.0, 700);
  gr->GetYaxis()->SetRangeUser(0, 70);

  gr->Draw("ACP");

  DeltaT_vs_Charge->SaveAs(Form("%s_DeltaT_vs_Charge.root", outname.c_str()));
  DeltaT_vs_Charge_Corrected->SaveAs(Form("%s_DeltaT_vs_Charge_Corrected.root", outname.c_str()));
  gr->SaveAs(Form("%s_SigmaT_vs_Charge.root", outname.c_str()));
  DeltaT->SaveAs(Form("%s_DeltaT.root", outname.c_str()));
}

int main(int argc, char **argv)
{
  
  MakeAmplitudePlot(argv[1], argv[2], atof(argv[3]));
}
