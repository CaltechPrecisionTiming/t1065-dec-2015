{
//=========Macro generated from canvas: c/c
//=========  (Thu Dec  1 17:18:11 2016) by ROOT version5.34/36
   TCanvas *c = new TCanvas("c", "c",2,51,800,800);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLogx();
   c->SetLeftMargin(0.18);
   c->SetBottomMargin(0.15);
   c->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(7);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetPoint(0,2,113);
   gre->SetPointError(0,0,13);
   gre->SetPoint(1,3.5,99);
   gre->SetPointError(1,0,7);
   gre->SetPoint(2,5,92);
   gre->SetPointError(2,0,5);
   gre->SetPoint(3,7,86);
   gre->SetPointError(3,0,7);
   gre->SetPoint(4,50,56);
   gre->SetPointError(4,0,8);
   gre->SetPoint(5,100,45);
   gre->SetPointError(5,0,4);
   gre->SetPoint(6,200,47);
   gre->SetPointError(6,0,4);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,1.8,219.8);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(150);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("Electron Beam Energy [GeV]");
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.045);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("Time Resolution [ps]");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.4);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1);
   
   gre->Draw("ap");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
