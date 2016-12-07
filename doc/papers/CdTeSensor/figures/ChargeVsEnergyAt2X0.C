void ChargeVsEnergyAt2X0()
{
//=========Macro generated from canvas: c/c
//=========  (Wed Dec  7 19:33:49 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",2,77,800,800);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLeftMargin(0.17);
   c->SetBottomMargin(0.12);
   c->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1002[5] = {
   0,
   2,
   3.5,
   5,
   7};
   Double_t Graph0_fy1002[5] = {
   -100,
   0.076,
   0.104,
   0.161,
   0.243};
   Double_t Graph0_fex1002[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1002[5] = {
   0,
   0.062,
   0.07,
   0.094,
   0.118};
   TGraphErrors *gre = new TGraphErrors(5,Graph0_fx1002,Graph0_fy1002,Graph0_fex1002,Graph0_fey1002);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00cc00");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","",100,0,7.7);
   Graph_Graph1002->SetMinimum(0);
   Graph_Graph1002->SetMaximum(0.4);
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
   Graph_Graph1002->GetYaxis()->SetTitleOffset(1.5);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1003[5] = {
   0,
   2,
   3.5,
   5,
   7};
   Double_t Graph1_fy1003[5] = {
   -100,
   0.076,
   0.104,
   0.161,
   0.243};
   Double_t Graph1_fex1003[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph1_fey1003[5] = {
   0,
   0.006,
   0.003,
   0.005,
   0.008};
   gre = new TGraphErrors(5,Graph1_fx1003,Graph1_fy1003,Graph1_fex1003,Graph1_fey1003);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);
   gre->Draw("pe1");
   TLatex *   tex = new TLatex(0.35,0.93,"Absorber : 2 X_{0} Lead");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
