{
//=========Macro generated from canvas: cv/cv
//=========  (Fri Nov 25 23:42:11 2016) by ROOT version5.34/36
   TCanvas *cv = new TCanvas("cv", "cv",77,128,800,800);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   cv->Range(-10.6,-6.923077,6.733333,50.76923);
   cv->SetFillColor(0);
   cv->SetBorderMode(0);
   cv->SetBorderSize(2);
   cv->SetLeftMargin(0.15);
   cv->SetBottomMargin(0.12);
   cv->SetFrameBorderMode(0);
   cv->SetFrameBorderMode(0);
   
   TH1F *timingvsy = new TH1F("timingvsy","timingvsy",12,-8,5);
   timingvsy->SetBinContent(1,47.92256);
   timingvsy->SetBinContent(2,22.25436);
   timingvsy->SetBinContent(3,25.26394);
   timingvsy->SetBinContent(4,22.97531);
   timingvsy->SetBinContent(5,22.03218);
   timingvsy->SetBinContent(6,25.17796);
   timingvsy->SetBinContent(7,25.39343);
   timingvsy->SetBinContent(8,27.47335);
   timingvsy->SetBinContent(9,28.54737);
   timingvsy->SetBinContent(10,29.12921);
   timingvsy->SetBinContent(11,53.29613);
   timingvsy->SetBinContent(12,105.2693);
   timingvsy->SetBinError(1,18.27903);
   timingvsy->SetBinError(2,1.837767);
   timingvsy->SetBinError(3,1.593483);
   timingvsy->SetBinError(4,1.024877);
   timingvsy->SetBinError(5,1.196925);
   timingvsy->SetBinError(6,1.131317);
   timingvsy->SetBinError(7,1.251243);
   timingvsy->SetBinError(8,1.653566);
   timingvsy->SetBinError(9,1.744424);
   timingvsy->SetBinError(10,2.296194);
   timingvsy->SetBinError(11,22.38183);
   timingvsy->SetBinError(12,107.9643);
   timingvsy->SetMinimum(0);
   timingvsy->SetMaximum(45);
   timingvsy->SetEntries(12);
   timingvsy->SetLineWidth(2);
   timingvsy->SetMarkerStyle(20);
   timingvsy->GetXaxis()->SetTitle("Horizontal Beam Position [mm]");
   timingvsy->GetXaxis()->SetTitleSize(0.05);
   timingvsy->GetYaxis()->SetTitle("Time Resolution [ps]");
   timingvsy->GetYaxis()->SetTitleSize(0.05);
   timingvsy->GetYaxis()->SetTitleOffset(1.25);
   timingvsy->Draw("");
   cv->Modified();
   cv->cd();
   cv->SetSelected(cv);
}
