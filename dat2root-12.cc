#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>
#include <TRandom.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TPostScript.h>
#include <TAxis.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TLegend.h>
#include <TF1.h>
#include <TLine.h>
#include <TStyle.h>
#include <TProfile.h>
#include <TMapFile.h>
#include <TPaveStats.h>


#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


int graphic_init();

TStyle* style;


int 
main(int argc, char **argv){

  double off_mean[4][9][1024];

  FILE* fp1;
  char stitle[200];
  int dummy;

  for( int i = 0; i < 4; i++){
    sprintf( stitle, "v1740_bd0_group_%d_offset.txt", i);

    fp1 = fopen( stitle, "r");
    printf("offset data : %s\n", stitle);

    for( int k = 0; k < 1024; k++)      
      for( int j = 0; j < 9; j++){      
	dummy = fscanf( fp1, "%lf ", &off_mean[i][j][k]);       
	if( k < 2 && 0)
	  printf("%5d  %8.4f\n", j, off_mean[i][j][k]);
      }
  
    fclose(fp1);
  }

  char   title[200];  
  sprintf( title, "%s-gr%s.root", argv[1], argv[2]);

  TFile* file = new TFile( title, "RECREATE", "CAEN V1742");
  TTree* tree = new TTree("pulse", "Wave Form");

  int event;
  ushort   b_c[9][1024], tc[4]; 

  tree->Branch("event", &event, "event/I");
  tree->Branch("tc",   tc, "tc[4]/s");
  tree->Branch("b_c",  b_c, "b_c[9216]/s");
  //  tree->Branch("b_c",  b_c, "b_c[8192]/s");

  uint   event_header;
  uint   temp[3];
  ushort samples[8][1024];

  // loop over root files
  sprintf( title, "/kdrive/data1/caen/2015-11/11-25/%s.dat", argv[1]);

  FILE* fpin = fopen( title, "r");


  for( int eventn = 0; eventn < atoi(argv[3]); eventn++){
    // printf("---- loop  %5d\n", loop);
    event = eventn;

    dummy = fread( &event_header, sizeof(uint), 1, fpin);  
    dummy = fread( &event_header, sizeof(uint), 1, fpin);  
    dummy = fread( &event_header, sizeof(uint), 1, fpin);  
    dummy = fread( &event_header, sizeof(uint), 1, fpin);  

    for( int group = 0; group < 4; group++){
      dummy = fread( &event_header, sizeof(uint), 1, fpin);  

      ushort tcn = (event_header >> 20) & 0xfff;
      tc[group] = tcn;

      int nsample = (event_header & 0xfff)/3;

      for(int i = 0; i < nsample; i++){
	dummy = fread( &temp, sizeof(uint), 3, fpin);  
	samples[0][i] =  temp[0] & 0xfff;
	samples[1][i] = (temp[0] >> 12) & 0xfff;
	samples[2][i] = (temp[0] >> 24) | ((temp[1] & 0xf) << 8);
	samples[3][i] = (temp[1] >>  4) & 0xfff;
	samples[4][i] = (temp[1] >> 16) & 0xfff;
	samples[5][i] = (temp[1] >> 28) | ((temp[2] & 0xff) << 4);
	samples[6][i] = (temp[2] >>  8) & 0xfff;
	samples[7][i] =  temp[2] >> 20;	
      }

      for(int j = 0; j < nsample/8; j++){
	fread( &temp, sizeof(uint), 3, fpin);  
	samples[8][j*8+0] =  temp[0] & 0xfff;
	samples[8][j*8+1] = (temp[0] >> 12) & 0xfff;
	samples[8][j*8+2] = (temp[0] >> 24) | ((temp[1] & 0xf) << 8);
	samples[8][j*8+3] = (temp[1] >>  4) & 0xfff;
	samples[8][j*8+4] = (temp[1] >> 16) & 0xfff;
	samples[8][j*8+5] = (temp[1] >> 28) | ((temp[2] & 0xff) << 4);
	samples[8][j*8+6] = (temp[2] >>  8) & 0xfff;
	samples[8][j*8+7] =  temp[2] >> 20;
      }

      if( group == atoi(argv[2])) 
	for(int i = 0; i < 9; i++)
	  for(int j = 0; j < 1024; j++)
	    b_c[i][j] = samples[i][j];
      
      double amplitude[8][1024];
      for( int i = 0; i < 8; i++)
	for( int j = 0; j < 1024; j++){
	  amplitude[i][j] = (double)samples[i][j] - off_mean[group][i][(j+tcn)%1024];  
	  // samples[i][j] -= off_mean[group][i][(j+tcn)%1024];  
	  amplitude[i][j] += 235;
	}

      dummy = fread( &event_header, sizeof(uint), 1, fpin);  
    }
    tree->Fill();
  }

  fclose(fpin);

  file->Write();
  file->Close();

  return 0;
  printf("dummy = %d\n", dummy);
}



int
graphic_init( void){

  style = new TStyle("style", "style");
  
  style->SetLabelFont(132,"X");
  style->SetLabelFont(132,"Y");
  style->SetTitleFont(132,"X");
  style->SetTitleFont(132,"Y");
  style->SetTitleFont(132,"");
  style->SetTitleFontSize( 0.07);
  style->SetStatFont(132);
  style->GetAttDate()->SetTextFont(132);

  style->SetStatW(0.20);
  style->SetStatH(0.23);

  style->SetFuncColor(2);
  style->SetFuncWidth(2);
  style->SetLineWidth(2);
  
  style->SetOptFile(0);
  style->SetOptTitle(1);

  style->SetFrameBorderMode(0);
  style->SetCanvasBorderMode(0);
  style->SetPadBorderMode(0);
  style->SetTitleStyle(4000);
  style->SetPadColor(0);
  style->SetCanvasColor(0);

  style->SetTitleFillColor(0);

  style->SetTitleBorderSize(0);
  //  style->SetTitleX(0.3);
  //  style->SetTitleY(0.06);
  style->SetStatColor(0);
  style->SetStatBorderSize(1);

  style->SetOptStat("emri");
  // style->SetOptStat(1);
  style->SetOptFit(1);
  style->SetTitleOffset( 1.0,"Y");

  style->SetMarkerStyle(20);
  style->SetMarkerSize( 0.3);
  style->SetMarkerColor(4);

  // style->SetOptDate(21);

  //  style->SetPadGridX(1);
  //  style->SetPadGridY(1);


  style->cd();

  return 0;
}
