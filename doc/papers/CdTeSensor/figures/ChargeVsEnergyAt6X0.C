void ChargeVsEnergyAt6X0()
{
//=========Macro generated from canvas: c/c
//=========  (Sat Dec  3 13:57:28 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",6,103,800,800);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLeftMargin(0.15);
   c->SetBottomMargin(0.12);
   c->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1008[3] = {
   50,
   100,
   200};
   Double_t Graph0_fy1008[3] = {
   3.1,
   5.8,
   9.6};
   Double_t Graph0_fex1008[3] = {
   0,
   0,
   0};
   Double_t Graph0_fey1008[3] = {
   1,
   1.6,
   3.1};
   TGraphErrors *gre = new TGraphErrors(3,Graph0_fx1008,Graph0_fy1008,Graph0_fex1008,Graph0_fey1008);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00cc00");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","",100,35,215);
   Graph_Graph1008->SetMinimum(0);
   Graph_Graph1008->SetMaximum(15);
   Graph_Graph1008->SetDirectory(0);
   Graph_Graph1008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1008->SetLineColor(ci);
   Graph_Graph1008->GetXaxis()->SetTitle("Electron Beam Energy [GeV]");
   Graph_Graph1008->GetXaxis()->SetLabelFont(42);
   Graph_Graph1008->GetXaxis()->SetLabelSize(0.045);
   Graph_Graph1008->GetXaxis()->SetTitleSize(0.045);
   Graph_Graph1008->GetXaxis()->SetTitleOffset(1.05);
   Graph_Graph1008->GetXaxis()->SetTitleFont(42);
   Graph_Graph1008->GetYaxis()->SetTitle("Integrated Charge [pC]");
   Graph_Graph1008->GetYaxis()->SetLabelFont(42);
   Graph_Graph1008->GetYaxis()->SetLabelSize(0.045);
   Graph_Graph1008->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1008->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1008->GetYaxis()->SetTitleFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1008);
   
   
   TF1 *pol11009 = new TF1("pol1","pol1",35,215);
   pol11009->SetFillColor(19);
   pol11009->SetFillStyle(0);
   pol11009->SetLineColor(2);
   pol11009->SetLineWidth(2);
   pol11009->SetChisquare(0.06984996);
   pol11009->SetNDF(1);
   pol11009->GetXaxis()->SetLabelFont(42);
   pol11009->GetXaxis()->SetLabelSize(0.035);
   pol11009->GetXaxis()->SetTitleSize(0.035);
   pol11009->GetXaxis()->SetTitleFont(42);
   pol11009->GetYaxis()->SetLabelFont(42);
   pol11009->GetYaxis()->SetLabelSize(0.035);
   pol11009->GetYaxis()->SetTitleSize(0.035);
   pol11009->GetYaxis()->SetTitleFont(42);
   pol11009->SetParameter(0,0.9099043);
   pol11009->SetParError(0,1.684547);
   pol11009->SetParLimits(0,0,0);
   pol11009->SetParameter(1,0.04554816);
   pol11009->SetParError(1,0.02003315);
   pol11009->SetParLimits(1,0,0);
   gre->GetListOfFunctions()->Add(pol11009);
   gre->Draw("ap");
   TLatex *   tex = new TLatex(0.3,0.93,"Absorber : 6 X_{0} W-Pb");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TPaveText *pt = new TPaveText(0.4422613,0.9345349,0.5577387,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("pol1");
   pt->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
