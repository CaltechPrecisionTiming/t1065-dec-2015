{
//=========Macro generated from canvas: T9Amp/T9Amp
//=========  (Mon Dec 12 19:56:43 2016) by ROOT version5.34/36
   TCanvas *T9Amp = new TCanvas("T9Amp", "T9Amp",2,51,600,600);
   gStyle->SetOptStat(0);
   T9Amp->Range(0,0,1,1);
   T9Amp->SetFillColor(0);
   T9Amp->SetBorderMode(0);
   T9Amp->SetBorderSize(2);
   T9Amp->SetLeftMargin(0.17);
   T9Amp->SetBottomMargin(0.12);
   T9Amp->SetRightMargin(0.05);
   T9Amp->SetFrameBorderMode(0);
   
   TH1F *h101 = new TH1F("h101","",20,0,0.4);
   h101->SetBinContent(1,43);
   h101->SetBinContent(2,44);
   h101->SetBinContent(3,47);
   h101->SetBinContent(4,77);
   h101->SetBinContent(5,78);
   h101->SetBinContent(6,58);
   h101->SetBinContent(7,42);
   h101->SetBinContent(8,27);
   h101->SetBinContent(9,19);
   h101->SetBinContent(10,12);
   h101->SetBinContent(11,10);
   h101->SetBinContent(12,4);
   h101->SetBinContent(13,5);
   h101->SetBinContent(14,1);
   h101->SetBinContent(17,1);
   h101->SetBinContent(21,1);
   h101->SetEntries(469);
   h101->SetStats(0);
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","gaus",0.04,0.4);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(2);
   PrevFitTMP->SetChisquare(14.66032);
   PrevFitTMP->SetNDF(10);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,64.26407);
   PrevFitTMP->SetParError(0,4.252243);
   PrevFitTMP->SetParLimits(0,0,0);
   PrevFitTMP->SetParameter(1,0.0779114);
   PrevFitTMP->SetParError(1,0.008610058);
   PrevFitTMP->SetParLimits(1,0,0);
   PrevFitTMP->SetParameter(2,0.0624377);
   PrevFitTMP->SetParError(2,0.006672714);
   PrevFitTMP->SetParLimits(2,0,0.4782353);
   h101->GetListOfFunctions()->Add(PrevFitTMP);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h101->SetLineColor(ci);
   h101->GetXaxis()->SetTitle("Integrated Charge [pC]");
   h101->GetXaxis()->SetRange(1,40);
   h101->GetXaxis()->SetLabelFont(42);
   h101->GetXaxis()->SetLabelSize(0.045);
   h101->GetXaxis()->SetTitleSize(0.045);
   h101->GetXaxis()->SetTitleOffset(1.2);
   h101->GetXaxis()->SetTitleFont(42);
   h101->GetYaxis()->SetTitle("Number of Events");
   h101->GetYaxis()->SetLabelFont(42);
   h101->GetYaxis()->SetLabelOffset(0.015);
   h101->GetYaxis()->SetLabelSize(0.045);
   h101->GetYaxis()->SetTitleSize(0.05);
   h101->GetYaxis()->SetTitleOffset(1.7);
   h101->GetYaxis()->SetTitleFont(42);
   h101->GetZaxis()->SetLabelFont(42);
   h101->GetZaxis()->SetLabelSize(0.035);
   h101->GetZaxis()->SetTitleSize(0.035);
   h101->GetZaxis()->SetTitleOffset(1.3);
   h101->GetZaxis()->SetTitleFont(42);
   h101->Draw("");
   TLatex *   tex = new TLatex(0.55,0.85,"Mean = 0.08 pC");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.55,0.8,"#sigma = 0.06 pC");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.18,0.93,"2 GeV Electrons, 2 X_{0} Pb Absorber");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
 
   T9Amp->Modified();
   T9Amp->cd();
   T9Amp->SetSelected(T9Amp);
}
