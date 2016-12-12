#define cdana2_cxx
#include "cdana2.h"
#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TMath.h>
#include <TRandom.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

void cdana2::Loop()
{


 gStyle->SetOptStat(0);
 gStyle->SetOptFit(1111);


//   In a ROOT session, you can do:
//      Root > .L cdana2.C
//      Root > cdana2 t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

TFile*myfile= new TFile("cdana_results.root","RECREATE");
Float_t xmax;
Float_t xmin;
Float_t width;
Float_t widthe;
Float_t mean;
Float_t meane;
Int_t ibin;
char *histname = new char[12];
Int_t nHistos = 12;
Int_t nHistos2 = 60;
TH1F *TimingX[nHistos];
TH1F *TimingY[nHistos];
TH1F *TimingR[nHistos];
TH1F *TimingE[nHistos];
TH1F *AmpvsX[nHistos2];
TH1F *AmpvsY[nHistos2];
TH1F *energy = new TH1F("energy","energy",100,0,800);
TH1F *xpos = new TH1F("xpos","xpos",100,-30,30);
TH1F *ypos = new TH1F("ypos","ypos",100,-30,30);
TH1F *timingvsx = new TH1F("timingvsx","timingvsx",nHistos,3,16);
TH1F *timingvsy = new TH1F("timingvsy","timingvsy",nHistos,-8,5);
TH1F *timingvsr = new TH1F("timingvsr","timingvsr",nHistos,0,12);
TH1F *timingvse = new TH1F("timingvse","timingvse",nHistos,0,0.78);
Int_t nxbins=nHistos;
//TH1F *ampvsx = new TH1F("ampvsx","ampvsx",nHistos2,-31.0,29.0);
 TH1F *ampvsx = new TH1F("ampvsx","ampvsx",nHistos2,-38.5, 21.5);
TH1F *ampvsy = new TH1F("ampvsy","ampvsy",nHistos2,-27.0,33.0);
Int_t nxbins2=nHistos2;

for(int i = 0; i < nHistos; i++)
 {
  sprintf(histname, "timingx_%d",i);  
  TimingX[i] = new TH1F(histname,"",100,-4.35,-4.0);
  sprintf(histname, "timingy_%d",i);  
  TimingY[i] = new TH1F(histname,"",100,-4.35,-4.0); 
  sprintf(histname, "timingr_%d",i);  
  TimingR[i] = new TH1F(histname,"",100,-4.35,-4.0);
  sprintf(histname, "timinge_%d",i);  
  TimingE[i] = new TH1F(histname,"",100,-4.35,-4.0);
 }
for(int i = 0; i < nHistos2; i++)
 {
  sprintf(histname, "ampvsx_%d",i);  
  AmpvsX[i] = new TH1F(histname,"",150,-0.030,1.0100);
  sprintf(histname, "ampvsy_%d",i);  
  AmpvsY[i] = new TH1F(histname,"",150,-0.030,1.0100);
 }
 TF1 *tgaus = new TF1("tgaus","gaus",-5.0,5.0);
 tgaus->SetParameters(1.0,1.0,1.0);
 tgaus->Draw();
 TF1 *tgaus2 = new TF1("tgaus2","gaus",-1000.0,1001.0);
 //tgaus2->SetParameters(1.0,10.0,10.0);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   cout << " #Events : " << nentries << endl; 
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //cout << (time_first-(time_ref2)/1.0)*0.2-0.0096*TDCx+0.011*TDCy-0.0379*(int(time_first+0.5)-time_first)+0.000106*max_first << endl;
      //cout << jentry << " " << TDCx << " " << max_first << endl;
      if (TDCy > -5.0 && TDCy < -2.0 && max_first > 400 && max_first < 650)
     {
      energy->Fill(max_first); 
      xpos->Fill(TDCx,max_first); 
       for (ibin=0; ibin<nxbins;ibin++)
	 {
	   //	   cout << TDCx << " " << (float)ibin+3.0 << endl;
	   if (TDCx>((float)ibin*1.0)+3.0 && TDCx<((float)ibin*1.0)+4.0)
	     {
               //cout << 1.0*ibin+3.0 << " " << (1.0*(int)(time_first+0.5)-time_first) << endl;
               TimingX[ibin]->Fill((time_first-(time_ref2)/1.0)*0.2-0.0096*TDCx+0.011*TDCy-0.0379*(1.0*(int)(time_first+0.5)-time_first)+0.000106*max_first);
	     };
	 };
     };
      //
      //
      if (TDCx > 7.0 && TDCx < 10.0 && max_first > 400 && max_first < 600)
     {
       ypos->Fill(TDCy,max_first); 
       for (ibin=0; ibin<nxbins;ibin++)
	 {
	   if (TDCy>((float)ibin*1.0)-8.0 && TDCy<((float)ibin*1.0)-7.0)
	     {
               //cout << 1.0*ibin+3.0 << " " << (1.0*(int)(time_first+0.5)-time_first) << endl;
               TimingY[ibin]->Fill((time_first-(time_ref2)/1.0)*0.2-0.0096*TDCx+0.011*TDCy-0.0379*(1.0*(int)(time_first+0.5)-time_first)+0.000106*max_first);
	     };
	 };
     };

      //
      //
      if (TDCx > 9.0 && TDCx < 13.0 && TDCy > -7.0 && TDCy < -3.0)
     {
       for (ibin=0; ibin<nxbins;ibin++)
	 {
	   if (max_first/(0.2*4096)>((float)ibin*0.06) && max_first/(0.2*4096)<((float)ibin*0.06)+0.06)
	     {
               TimingE[ibin]->Fill((time_first-(time_ref2)/1.0)*0.2-0.0096*TDCx+0.011*TDCy-0.0379*(1.0*(int)(time_first+0.5)-time_first)+0.000106*max_first);
	     };
	 };
     };
     //
     //
     if (max_first > 400 && max_first < 550)
     {
        for (ibin=0; ibin<nxbins;ibin++)
	 {
	   if ( sqrt((TDCx-12)*(TDCx-12) + (TDCy+4)*(TDCy+4)) >((float)ibin*1.0) &&  sqrt((TDCx-12)*(TDCx-12) + (TDCy+4)*(TDCy+4)) <((float)ibin*1.0)+1.0
 && TDCx>3 && TDCx<14 && TDCy>-7 && TDCy<4)
	     {
	       //cout <<  sqrt((TDCx-12)*(TDCx-12) + (TDCy+6)*(TDCy+6)) << " " << TDCx << " " << TDCy << endl;
               //cout << 1.0*ibin+3.0 << " " << (1.0*(int)(time_first+0.5)-time_first) << endl;
               TimingR[ibin]->Fill((time_first-(time_ref2)/1.0)*0.2-0.0096*TDCx+0.011*TDCy-0.0379*(1.0*(int)(time_first+0.5)-time_first)+0.000106*max_first);
	     };
	 };
     };
     if (TDCy>-6.0 && TDCy<1.0)
       //    if (TDCy>1.0 && TDCy<9.0)
     {
        for (ibin=0; ibin<nxbins2;ibin++)
	 {
	   //	   if (TDCx>(float)ibin*1.0-30.0 && TDCx<(float)ibin*1.0-29.0)
	   if (TDCx>(float)ibin*1.0-30.0 && TDCx<(float)ibin*1.0-29.0)
	     {
	       //cout <<  sqrt((TDCx-12)*(TDCx-12) + (TDCy+6)*(TDCy+6)) << " " << TDCx << " " << TDCy << endl;
               //cout << 1.0*ibin+3.0 << " " << (1.0*(int)(time_first+0.5)-time_first) << endl;
               //AmpvsX[ibin]->Fill(max_first/(0.2*4096)*0.316);
               AmpvsX[ibin]->Fill(max_first/(0.2*4096));
               //AmpvsX[ibin]->Fill(max_first/(0.2*4096));
	     };
	 };
     };
     //     if (TDCy>-6.0 && TDCy<1.0)
     if (TDCx>4.5 && TDCx<12.5)
     {
        for (ibin=0; ibin<nxbins2;ibin++)
	 {
	   //	   if (TDCx>(float)ibin*1.0-30.0 && TDCx<(float)ibin*1.0-29.0)
	   if (TDCy>(float)ibin*1.0-30.0 && TDCy<(float)ibin*1.0-29.0)
	     {
	       //cout <<  sqrt((TDCx-12)*(TDCx-12) + (TDCy+6)*(TDCy+6)) << " " << TDCx << " " << TDCy << endl;
               //cout << 1.0*ibin+3.0 << " " << (1.0*(int)(time_first+0.5)-time_first) << endl;
               //AmpvsX[ibin]->Fill(max_first/(0.2*4096)*0.316);
               AmpvsY[ibin]->Fill(max_first/(0.2*4096));
               //AmpvsX[ibin]->Fill(max_first/(0.2*4096));
	     };
	 };
     };

};

       for (ibin=0; ibin<nxbins;ibin++)
	 {
           width = 0;
	   TimingX[ibin]->Fit("tgaus","");
           width = tgaus->GetParameter(2);
           widthe = tgaus->GetParError(2);
           timingvsx->SetBinContent(ibin+1,width*1000.0);
           //cout << ibin << " " << width << endl;
           timingvsx->SetBinError(ibin+1,widthe*1000.0);
	   //
           width = 0;
	   TimingY[ibin]->Fit("tgaus","Q");
           width = tgaus->GetParameter(2);
           widthe = tgaus->GetParError(2);
           timingvsy->SetBinContent(ibin+1,width*1000.0);
           timingvsy->SetBinError(ibin+1,widthe*1000.0);
	   //          
           width = 0;
 	   TimingR[ibin]->Fit("tgaus","Q","",-4.25,-4.125);
           width = tgaus->GetParameter(2);
           widthe = tgaus->GetParError(2);
           timingvsr->SetBinContent(ibin+1,width*1000.0);
           timingvsr->SetBinError(ibin+1,widthe*1000.0);
	   //        
           width = 0;  
 	   TimingE[ibin]->Fit("tgaus","Q","",-4.3,-4.1);
           width = tgaus->GetParameter(2);
           widthe = tgaus->GetParError(2);
           timingvse->SetBinContent(ibin+1,width*1000.0);
           timingvse->SetBinError(ibin+1,widthe*1000.0);
         };
       for (ibin=0; ibin<nxbins2;ibin++)
	 {
	   Float_t mean=AmpvsX[ibin]->GetMean();
	   Float_t rms=AmpvsX[ibin]->GetRMS();
           Float_t maxbin= AmpvsX[ibin]->GetMaximumBin();
          //tgaus2->SetParameters(100.0,mean,rms);
           cout << AmpvsX[ibin]->GetMaximumBin() << endl;
           width = 0;
           Float_t max;
            Float_t min;
           if (mean<rms) 
	     {
	       min=0.01;
	       max=rms;
	     };
	   //           if (ibin<21) 
           if (ibin<0) 
	     {
	       min=0.01;
	       max=0.1;
	     };
           if (mean>rms) 
	     {
               min=mean-rms;
	       max=mean+2*rms;
	     };
	   AmpvsX[ibin]->Fit("tgaus2","Q","",min,max);
           mean = tgaus2->GetParameter(1);
           meane = tgaus2->GetParError(1);
           //meane = tgaus2->GetParameter(2);
           if (mean<0)
	     {
	       mean=0.0;
               meane=0.01;
	     }
	   //           if (maxbin>20)
           //if (maxbin>120)
           if (maxbin>149)
	     {
	       mean=1.0;
               meane=0.01;
	     }
           cout << mean << " -- " << maxbin << endl;

           ampvsx->SetBinContent(ibin+1,mean*(1.0/63.0957)*1000.0*(1/0.316));
           ampvsx->SetBinError(ibin+1,meane*(1.0/63.0957)*1000.0*(1/0.316));
	   //
	   //
	   //
	   Float_t meany=AmpvsY[ibin]->GetMean();
	   Float_t meanye;
	   Float_t rmsy=AmpvsY[ibin]->GetRMS();
           Float_t maxbiny= AmpvsY[ibin]->GetMaximumBin();
          //tgaus2->SetParameters(100.0,mean,rms);
           cout << ibin << " maxbin Y " << AmpvsY[ibin]->GetMaximumBin() << endl;
           width = 0;
           Float_t maxy;
           Float_t miny;
           if (meany<rmsy) 
	     {
	       miny=0.01;
	       maxy=rmsy;
	     };
           if (meany>rmsy) 
	     {
               miny=meany-rmsy;
	       maxy=meany+2*rmsy;
	     };
	   //           if (ibin<12 || ibin>40) 
           if (ibin<0) 
	     {
	       miny=0.01;
	       maxy=0.1;
	     };
	   AmpvsY[ibin]->Fit("tgaus2","Q","",miny,maxy);
           meany = tgaus2->GetParameter(1);
           meanye = tgaus2->GetParError(1);
           if (meany<0)
	     {
	       meany=0.0;
               meanye=0.01;
	     }
	   //           if (maxbin>20)
           //if (maxbiny>120)
	     if (maxbiny>149)
	     {
	       meany=800.0/(0.2*4096)*0.316;
               meanye=0.01;
	     }
           cout << meany << " -- " << maxbiny << endl;

           ampvsy->SetBinContent(ibin+1,meany*(1.0/63.0957)*1000.0*(1/0.316));
           ampvsy->SetBinError(ibin+1,meanye*(1.0/63.0957)*1000.0*(1/0.316));

         };

 timingvsx->SetAxisRange(0.0,50.0,"Y");
 timingvsy->SetAxisRange(0.0,50.0,"Y");
 timingvsr->SetAxisRange(0.0,50.0,"Y");
 timingvse->SetAxisRange(0.0,100.0,"Y");
 ampvsx->SetAxisRange(0.0,0.800,"Y");
 ampvsy->SetAxisRange(0.0,0.800,"Y");

 ampvsx->Draw();



	//>>h6007(200,-4.35,-4.0)","(time_first-(time_ref1+time_ref2)/2.0)*0.2>-5 && (time_first-(time_ref1+time_ref2)/2.0)*0.2<-3.15 && TDCx>8 && TDCx<11 && TDCy>-8.0 && TDCy<-7.0 && max_first>400 && max_first<680 && (int(time_first+0.5)-time_first)>-0.5 && (int(time_first+0.5)-time_first)<0.5");
	// h6007->Fit("gaus","","",-4.4,-3.9);

  myfile->Write();
  myfile->Close();


}
