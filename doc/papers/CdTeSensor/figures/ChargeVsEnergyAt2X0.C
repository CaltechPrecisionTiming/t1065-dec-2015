{
//=========Macro generated from canvas: c/c
//=========  (Thu Dec  1 17:02:25 2016) by ROOT version5.34/36
   TCanvas *c = new TCanvas("c", "c",2,77,800,800);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLeftMargin(0.15);
   c->SetBottomMargin(0.12);
   c->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00cc00");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);
   gre->SetMarkerStyle(20);
   gre->SetPoint(0,2,0.16);
   gre->SetPointError(0,0,0.08);
   gre->SetPoint(1,3.5,0.26);
   gre->SetPointError(1,0,0.15);
   gre->SetPoint(2,5,0.26);
   gre->SetPointError(2,0,0.17);
   gre->SetPoint(3,7,0.4);
   gre->SetPointError(3,0,0.2);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","",100,1.5,7.5);
   Graph_Graph2->SetMinimum(0);
   Graph_Graph2->SetMaximum(0.75);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetTitle("Electron Beam Energy [GeV]");
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.045);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.045);
   Graph_Graph2->GetXaxis()->SetTitleOffset(1.05);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetTitle("Integrated Charge [pC]");
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.045);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph2);
   
   gre->Draw("ap");
   
   gre = new TGraphErrors(4);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);
   gre->SetPoint(0,2,0.16);
   gre->SetPointError(0,0,0.008);
   gre->SetPoint(1,3.5,0.26);
   gre->SetPointError(1,0,0.015);
   gre->SetPoint(2,5,0.26);
   gre->SetPointError(2,0,0.03);
   gre->SetPoint(3,7,0.4);
   gre->SetPointError(3,0,0.026);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,1.5,7.5);
   Graph_Graph3->SetMinimum(0.1246);
   Graph_Graph3->SetMaximum(0.4534);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3->SetLineColor(ci);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph3);
   
   
   TF1 *pol1 = new TF1("pol1","pol1",1.5,7.5);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(2);
   pol1->SetChisquare(5.376196);
   pol1->SetNDF(2);
   pol1->GetXaxis()->SetLabelFont(42);
   pol1->GetXaxis()->SetLabelSize(0.035);
   pol1->GetXaxis()->SetTitleSize(0.035);
   pol1->GetXaxis()->SetTitleFont(42);
   pol1->GetYaxis()->SetLabelFont(42);
   pol1->GetYaxis()->SetLabelSize(0.035);
   pol1->GetYaxis()->SetTitleSize(0.035);
   pol1->GetYaxis()->SetTitleFont(42);
   pol1->SetParameter(0,0.06847663);
   pol1->SetParError(0,0.0148229);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.04758728);
   pol1->SetParError(1,0.00478767);
   pol1->SetParLimits(1,0,0);
   gre->GetListOfFunctions()->Add(pol1);
   gre->Draw("pe1");
   TLatex *   tex = new TLatex(0.35,0.93,"Absorber : 2 X_{0} Lead");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TPaveText *pt = new TPaveText(0.442381,0.9346907,0.557619,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("pol1");
   pt->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
