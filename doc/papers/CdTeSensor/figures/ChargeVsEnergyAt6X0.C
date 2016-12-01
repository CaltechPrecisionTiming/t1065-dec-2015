{
//=========Macro generated from canvas: c/c
//=========  (Thu Dec  1 17:02:24 2016) by ROOT version5.34/36
   TCanvas *c = new TCanvas("c", "c",4,77,800,800);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLeftMargin(0.15);
   c->SetBottomMargin(0.12);
   c->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(3);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00cc00");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetPoint(0,50,3.1);
   gre->SetPointError(0,0,1);
   gre->SetPoint(1,100,5.8);
   gre->SetPointError(1,0,1.6);
   gre->SetPoint(2,200,9.6);
   gre->SetPointError(2,0,3.1);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,35,215);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(15);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("Electron Beam Energy [GeV]");
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.045);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.05);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("Integrated Charge [pC]");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1);
   
   
   TF1 *pol1 = new TF1("pol1","pol1",35,215);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(2);
   pol1->SetChisquare(0.06984996);
   pol1->SetNDF(1);
   pol1->GetXaxis()->SetLabelFont(42);
   pol1->GetXaxis()->SetLabelSize(0.035);
   pol1->GetXaxis()->SetTitleSize(0.035);
   pol1->GetXaxis()->SetTitleFont(42);
   pol1->GetYaxis()->SetLabelFont(42);
   pol1->GetYaxis()->SetLabelSize(0.035);
   pol1->GetYaxis()->SetTitleSize(0.035);
   pol1->GetYaxis()->SetTitleFont(42);
   pol1->SetParameter(0,0.9099043);
   pol1->SetParError(0,1.684547);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.04554816);
   pol1->SetParError(1,0.02003315);
   pol1->SetParLimits(1,0,0);
   gre->GetListOfFunctions()->Add(pol1);
   gre->Draw("ap");
   TLatex *   tex = new TLatex(0.35,0.93,"Absorber : 6 X_{0} Tungsten");
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
