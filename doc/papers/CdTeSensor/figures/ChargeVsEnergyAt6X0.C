void ChargeVsEnergyAt6X0()
{
//=========Macro generated from canvas: c/c
//=========  (Tue Dec  6 17:50:10 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",2,51,800,800);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLeftMargin(0.15);
   c->SetBottomMargin(0.12);
   c->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1002[3] = {
   50,
   100,
   200};
   Double_t Graph0_fy1002[3] = {
   3.6,
   6.8,
   11.5};
   Double_t Graph0_fex1002[3] = {
   0,
   0,
   0};
   Double_t Graph0_fey1002[3] = {
   0.6,
   1.2,
   2.2};
   TGraphErrors *gre = new TGraphErrors(3,Graph0_fx1002,Graph0_fy1002,Graph0_fex1002,Graph0_fey1002);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00cc00");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","",100,35,215);
   Graph_Graph1002->SetMinimum(0);
   Graph_Graph1002->SetMaximum(15);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetTitle("Electron Beam Energy [GeV]");
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.045);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.045);
   Graph_Graph1002->GetXaxis()->SetTitleOffset(1.05);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetTitle("Integrated Charge [pC]");
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.045);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1002->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   gre->Draw("ap");
   TLatex *   tex = new TLatex(0.3,0.93,"Absorber : 6 X_{0} W-Pb");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
