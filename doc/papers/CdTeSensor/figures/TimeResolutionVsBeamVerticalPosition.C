{
//=========Macro generated from canvas: cv/cv
//=========  (Fri Nov 25 23:43:05 2016) by ROOT version5.34/36
   TCanvas *cv = new TCanvas("cv", "cv",77,128,800,800);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   cv->Range(0.3999999,-6.923077,17.73333,50.76923);
   cv->SetFillColor(0);
   cv->SetBorderMode(0);
   cv->SetBorderSize(2);
   cv->SetLeftMargin(0.15);
   cv->SetBottomMargin(0.12);
   cv->SetFrameBorderMode(0);
   cv->SetFrameBorderMode(0);
   
   TH1F *timingvsx = new TH1F("timingvsx","timingvsx",12,3,16);
   timingvsx->SetBinContent(1,63.4715);
   timingvsx->SetBinContent(2,28.95814);
   timingvsx->SetBinContent(3,26.31269);
   timingvsx->SetBinContent(4,24.83383);
   timingvsx->SetBinContent(5,25.7991);
   timingvsx->SetBinContent(6,24.59269);
   timingvsx->SetBinContent(7,23.15479);
   timingvsx->SetBinContent(8,21.5948);
   timingvsx->SetBinContent(9,21.30971);
   timingvsx->SetBinContent(10,25.44531);
   timingvsx->SetBinContent(11,21.03255);
   timingvsx->SetBinContent(12,342.5689);
   timingvsx->SetBinError(1,41.29973);
   timingvsx->SetBinError(2,6.052334);
   timingvsx->SetBinError(3,2.055096);
   timingvsx->SetBinError(4,1.387946);
   timingvsx->SetBinError(5,1.279149);
   timingvsx->SetBinError(6,1.129248);
   timingvsx->SetBinError(7,0.9633864);
   timingvsx->SetBinError(8,0.9266089);
   timingvsx->SetBinError(9,1.136563);
   timingvsx->SetBinError(10,2.084543);
   timingvsx->SetBinError(11,3.145861);
   timingvsx->SetBinError(12,192.9523);
   timingvsx->SetMinimum(0);
   timingvsx->SetMaximum(45);
   timingvsx->SetEntries(12);
   timingvsx->SetLineWidth(2);
   timingvsx->SetMarkerStyle(20);
   timingvsx->GetXaxis()->SetTitle("Vertical Beam Position [mm]");
   timingvsx->GetXaxis()->SetTitleSize(0.04);
   timingvsx->GetXaxis()->SetLabelSize(0.04);
   timingvsx->GetXaxis()->SetTitleOffset(1.2);
   timingvsx->GetYaxis()->SetTitle("Time Resolution [ps]");
   timingvsx->GetYaxis()->SetTitleSize(0.04);
   timingvsx->GetYaxis()->SetTitleOffset(1.35);
   timingvsx->GetYaxis()->SetLabelSize(0.04);
   timingvsx->Draw("");
   cv->Modified();
   cv->cd();
   cv->SetSelected(cv);
}
