void 50GeV_charge()
{
//=========Macro generated from canvas: c/c
//=========  (Tue Dec  6 16:41:44 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",2,51,600,600);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLeftMargin(0.17);
   c->SetRightMargin(0.05);
   c->SetFrameBorderMode(0);
   
   TH1F *histIntCharge17 = new TH1F("histIntCharge17","",25,0,7);
   histIntCharge17->SetBinContent(3,1);
   histIntCharge17->SetBinContent(4,2);
   histIntCharge17->SetBinContent(5,1);
   histIntCharge17->SetBinContent(6,4);
   histIntCharge17->SetBinContent(7,2);
   histIntCharge17->SetBinContent(8,3);
   histIntCharge17->SetBinContent(9,4);
   histIntCharge17->SetBinContent(10,5);
   histIntCharge17->SetBinContent(11,8);
   histIntCharge17->SetBinContent(12,11);
   histIntCharge17->SetBinContent(13,12);
   histIntCharge17->SetBinContent(14,16);
   histIntCharge17->SetBinContent(15,10);
   histIntCharge17->SetBinContent(16,11);
   histIntCharge17->SetBinContent(17,7);
   histIntCharge17->SetBinContent(18,1);
   histIntCharge17->SetBinContent(19,2);
   histIntCharge17->SetMaximum(19.2);
   histIntCharge17->SetEntries(100);
   histIntCharge17->SetStats(0);
   
   TF1 *gaus17 = new TF1("gaus","gaus",2.5,6);
   gaus17->SetFillColor(19);
   gaus17->SetFillStyle(0);
   gaus17->SetLineColor(2);
   gaus17->SetLineWidth(2);
   gaus17->SetChisquare(4.579787);
   gaus17->SetNDF(7);
   gaus17->GetXaxis()->SetLabelFont(42);
   gaus17->GetXaxis()->SetLabelSize(0.035);
   gaus17->GetXaxis()->SetTitleSize(0.035);
   gaus17->GetXaxis()->SetTitleFont(42);
   gaus17->GetYaxis()->SetLabelFont(42);
   gaus17->GetYaxis()->SetLabelSize(0.035);
   gaus17->GetYaxis()->SetTitleSize(0.035);
   gaus17->GetYaxis()->SetTitleFont(42);
   gaus17->SetParameter(0,14.19277);
   gaus17->SetParError(0,2.042254);
   gaus17->SetParLimits(0,0,0);
   gaus17->SetParameter(1,3.647237);
   gaus17->SetParError(1,0.09083273);
   gaus17->SetParLimits(1,0,0);
   gaus17->SetParameter(2,0.6454106);
   gaus17->SetParError(2,0.07480717);
   gaus17->SetParLimits(2,0,6.065914);
   histIntCharge17->GetListOfFunctions()->Add(gaus17);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   histIntCharge17->SetLineColor(ci);
   histIntCharge17->GetXaxis()->SetTitle("Integrated Charge [pC]");
   histIntCharge17->GetXaxis()->SetRange(1,26);
   histIntCharge17->GetXaxis()->SetLabelFont(42);
   histIntCharge17->GetXaxis()->SetLabelSize(0.045);
   histIntCharge17->GetXaxis()->SetTitleSize(0.045);
   histIntCharge17->GetXaxis()->SetTitleFont(42);
   histIntCharge17->GetYaxis()->SetTitle("Number of Events");
   histIntCharge17->GetYaxis()->SetLabelFont(42);
   histIntCharge17->GetYaxis()->SetLabelOffset(0.015);
   histIntCharge17->GetYaxis()->SetLabelSize(0.045);
   histIntCharge17->GetYaxis()->SetTitleSize(0.05);
   histIntCharge17->GetYaxis()->SetTitleOffset(1.7);
   histIntCharge17->GetYaxis()->SetTitleFont(42);
   histIntCharge17->GetZaxis()->SetLabelFont(42);
   histIntCharge17->GetZaxis()->SetLabelSize(0.035);
   histIntCharge17->GetZaxis()->SetTitleSize(0.035);
   histIntCharge17->GetZaxis()->SetTitleFont(42);
   histIntCharge17->Draw("");
   TLatex *   tex = new TLatex(0.45,0.85,"Mean = 3.6 pC");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.45,0.8,"#sigma = 0.6 pC");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.13,0.93,"50 GeV Electrons, 6 X_{0} Tungsten Absorber");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TPaveText *pt = new TPaveText(0.4337919,0.94,0.5662081,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("gaus");
   pt->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
