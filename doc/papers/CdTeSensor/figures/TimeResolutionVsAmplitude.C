{
//=========Macro generated from canvas: cv/cv
//=========  (Fri Nov 25 23:48:17 2016) by ROOT version5.34/36
   TCanvas *cv = new TCanvas("cv", "cv",77,128,800,800);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   cv->Range(-160,-12.30769,906.6667,90.25641);
   cv->SetFillColor(0);
   cv->SetBorderMode(0);
   cv->SetBorderSize(2);
   cv->SetLeftMargin(0.15);
   cv->SetBottomMargin(0.12);
   cv->SetFrameBorderMode(0);
   cv->SetFrameBorderMode(0);
   
   TH1F *timingvse = new TH1F("timingvse","timingvse",12,0,800);
   timingvse->SetBinContent(1,518.2812);
   timingvse->SetBinContent(2,57.80939);
   timingvse->SetBinContent(3,47.20327);
   timingvse->SetBinContent(4,39.1104);
   timingvse->SetBinContent(5,35.96698);
   timingvse->SetBinContent(6,28.65915);
   timingvse->SetBinContent(7,28.7209);
   timingvse->SetBinContent(8,29.25061);
   timingvse->SetBinContent(9,25.09794);
   timingvse->SetBinContent(10,23.79711);
   timingvse->SetBinContent(11,22.6829);
   timingvse->SetBinContent(12,23.65276);
   timingvse->SetBinError(1,355.065);
   timingvse->SetBinError(2,9.027612);
   timingvse->SetBinError(3,5.206705);
   timingvse->SetBinError(4,2.104017);
   timingvse->SetBinError(5,1.675571);
   timingvse->SetBinError(6,1.028382);
   timingvse->SetBinError(7,0.8069513);
   timingvse->SetBinError(8,0.8366823);
   timingvse->SetBinError(9,0.8407874);
   timingvse->SetBinError(10,1.182037);
   timingvse->SetBinError(11,2.359756);
   timingvse->SetBinError(12,2.871447);
   timingvse->SetMinimum(0);
   timingvse->SetMaximum(80);
   timingvse->SetEntries(12);
   timingvse->SetLineWidth(2);
   timingvse->SetMarkerStyle(20);
   timingvse->GetXaxis()->SetTitle("Signal Amplitude [mV]");
   timingvse->GetXaxis()->SetTitleSize(0.05);
   timingvse->GetYaxis()->SetTitle("Time Resolution [ps]");
   timingvse->GetYaxis()->SetTitleSize(0.05);
   timingvse->GetYaxis()->SetTitleOffset(1.25);
   timingvse->Draw("");
   cv->Modified();
   cv->cd();
   cv->SetSelected(cv);
}
