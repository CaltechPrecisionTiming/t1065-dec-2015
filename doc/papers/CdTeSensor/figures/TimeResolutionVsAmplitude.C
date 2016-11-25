{
//=========Macro generated from canvas: cv/cv
//=========  (Sat Nov 26 00:21:57 2016) by ROOT version5.34/36
   TCanvas *cv = new TCanvas("cv", "cv",4,77,800,800);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   cv->Range(-0.156,-12.30769,0.884,90.25641);
   cv->SetFillColor(0);
   cv->SetBorderMode(0);
   cv->SetBorderSize(2);
   cv->SetLeftMargin(0.15);
   cv->SetBottomMargin(0.12);
   cv->SetFrameBorderMode(0);
   cv->SetFrameBorderMode(0);
   
   TH1F *timingvse = new TH1F("timingvse","timingvse",12,0,0.78);
   timingvse->SetBinContent(1,518.2812);
   timingvse->SetBinContent(2,56.51033);
   timingvse->SetBinContent(3,47.56258);
   timingvse->SetBinContent(4,39.64721);
   timingvse->SetBinContent(5,36.63596);
   timingvse->SetBinContent(6,29.05895);
   timingvse->SetBinContent(7,29.01033);
   timingvse->SetBinContent(8,28.29053);
   timingvse->SetBinContent(9,25.14445);
   timingvse->SetBinContent(10,22.98854);
   timingvse->SetBinContent(11,23.35522);
   timingvse->SetBinContent(12,26.35634);
   timingvse->SetBinError(1,359.1924);
   timingvse->SetBinError(2,8.686874);
   timingvse->SetBinError(3,5.346611);
   timingvse->SetBinError(4,2.338792);
   timingvse->SetBinError(5,1.731067);
   timingvse->SetBinError(6,1.037835);
   timingvse->SetBinError(7,0.8437037);
   timingvse->SetBinError(8,0.8165895);
   timingvse->SetBinError(9,0.7912843);
   timingvse->SetBinError(10,1.027598);
   timingvse->SetBinError(11,2.40417);
   timingvse->SetBinError(12,4.261623);
   timingvse->SetMinimum(0);
   timingvse->SetMaximum(80);
   timingvse->SetEntries(12);
   timingvse->SetLineWidth(2);
   timingvse->SetMarkerStyle(20);
   timingvse->GetXaxis()->SetTitle("Signal Amplitude [V]");
   timingvse->GetXaxis()->SetTitleSize(0.05);
   timingvse->GetYaxis()->SetTitle("Time Resolution [ps]");
   timingvse->GetYaxis()->SetTitleSize(0.05);
   timingvse->GetYaxis()->SetTitleOffset(1.25);
   timingvse->Draw("");
   cv->Modified();
   cv->cd();
   cv->SetSelected(cv);
}
