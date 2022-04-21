// Cretaed for the MOLLER Optics study by Vassu Doomra Date: April 17, 2022


#include "TH2D.h"

const int nFiles = 5;
const int nPlots = 14;
const char* filename[nFiles] = { "Cfoil_elastic_p1.root", "Cfoil_elastic_p2.root","Cfoil_elastic_p3.root", "Cfoil_elastic_p4.root","Cfoil_elastic_p5.root"};
const char* passNames[nFiles] = {"pass1","pass2","pass3","pass4","pass5"};
const int color[nFiles] = {kRed,kBlue,kGreen,kMagenta,kBlack};
const char* plotName[nPlots] = { "main_xy","sieve_xy","gem1_xy","gem2_xy","gem3_xy","gem4_xy","gem1_r","gem1_r'","gem1_phi","gem1_phi'",
                           "theta_tg_vs_r_gem1","theta_tg_vs_phi_gem1","theta_tg_vs_r'_gem1","theta_tg_vs_phi'_gem1" };

TCanvas* c[nPlots];
TCanvas* c1;

TH1D* gr[nFiles] = {NULL};    // r distribution at gem1 plane
TH1D* grp[nFiles] = {NULL};   // r' distribution at gem1 plane
TH1D* gphi[nFiles] = {NULL};  // phi distribution at gem1 plane
TH1D* gphip[nFiles] = {NULL}; // phi' distribution at gem1 plane

TH2D* gxy1[nFiles] = {NULL};  // xy distribution at gem1 plane
TH2D* gxy2[nFiles] = {NULL};  // xy distribution at gem2 plane
TH2D* gxy3[nFiles] = {NULL};  // xy distribution at gem3 plane
TH2D* gxy4[nFiles] = {NULL};  // xy distribution at gem3 plane

TH2D* Etheta[nFiles] = {NULL};  // E vs theta_tg
TH2D* Etheta_weighted[nFiles] = {NULL};  // E vs theta_tg
TH2D* sievexy[nFiles] = {NULL}; // xy distribution at the sieve plane
TH2D* mainxy[nFiles] = {NULL};  // xy distribution at the main detector plane

TH2D* thetar[nFiles] = {NULL};  // theta_tg vs r at gem1
TH2D* thetarp[nFiles] = {NULL};  // theta_tg vs r' at gem1
TH2D* thetaphi[nFiles] = {NULL}; // theta_tg vs phi at gem1
TH2D* thetaphip[nFiles] = {NULL}; // theta_tg vs phi' at gem1


const double pi = acos(-1);

void plots(){

  for(int k=0; k<nPlots; k++){

    c[k] = new TCanvas(Form("%s",plotName[k])); c[k]->Divide(2,3);}

     c1 = new TCanvas("E_vs_theta"); c1->Divide(1,2);

  for(int i=0; i<nFiles; i++){

    TFile* fin = new TFile(Form("%s",filename[i]),"READ");

    TTree* T = (TTree*)fin->Get("newT");

    int nEntries = T->GetEntries();
 
    double main_x, main_y, sieve_x, sieve_y, sieve_r;
    double gem1_x, gem1_y, gem2_x, gem2_y, gem3_x, gem3_y, gem4_x, gem4_y;
    double gem1_r, gem1_rp, gem1_phi, gem1_phip, gem1_px, gem1_py, gem1_pz;
    double tg_th; double tg_p; double rate;

    T->SetBranchAddress("main_x",&main_x);
    T->SetBranchAddress("main_y",&main_y);
    T->SetBranchAddress("gem1_r",&gem1_r);
    T->SetBranchAddress("gem1_ph",&gem1_phi);
    T->SetBranchAddress("gem1_x",&gem1_x);
    T->SetBranchAddress("gem1_y",&gem1_y);
    T->SetBranchAddress("gem2_x",&gem2_x);
    T->SetBranchAddress("gem2_y",&gem2_y);
    T->SetBranchAddress("gem3_x",&gem3_x);
    T->SetBranchAddress("gem3_y",&gem3_y);
    T->SetBranchAddress("gem4_x",&gem4_x);
    T->SetBranchAddress("gem4_y",&gem4_y);
    T->SetBranchAddress("gem1_px",&gem1_px);
    T->SetBranchAddress("gem1_py",&gem1_py);
    T->SetBranchAddress("gem1_pz",&gem1_pz);
    T->SetBranchAddress("sieve_x",&sieve_x);
    T->SetBranchAddress("sieve_y",&sieve_y);
    T->SetBranchAddress("tg_th",&tg_th);
    T->SetBranchAddress("tg_p",&tg_p);
    T->SetBranchAddress("rate",&rate);
    T->SetBranchAddress("sieve_r",&sieve_r);
   

    gr[i] = new TH1D(Form("gem1_r_%s",passNames[i]),"gem1_r_distribution;r[mm];Counts",100,500,1300);
    grp[i] = new TH1D(Form("gem1_r'_%s",passNames[i]),"gem1_r_prime_distribution;r';Counts",100,0,0.1);
    gphi[i] = new TH1D(Form("gem1_phi_%s",passNames[i]),"gem1_phi_distribution;#phi(rad);Counts",100,-pi,pi);
    gphip[i] = new TH1D(Form("gem1_phi'_%s",passNames[i]),"gem1_phi_prime_distribution;#phi';Counts",100,-0.1,0.1);
    Etheta[i] = new TH2D(Form("Etheta_%s",passNames[i]),"E' vs #theta;#theta_{tg};E(MeV)",50,0,1.8,100,0,12);
    Etheta_weighted[i] = new TH2D(Form("Etheta_weighted_%s",passNames[i]),"E' vs #theta weighted;#theta_{tg};E(MeV)",50,0,1.8,100,0,12);
    sievexy[i] = new TH2D(Form("sieve_xy_%s",passNames[i]),"sieve_xy_distribution;x[mm];y[mm]",500,-100,100,500,-100,100);
    mainxy[i] = new TH2D(Form("main_xy_%s",passNames[i]),"main_xy_distribution;x[mm];y[mm]",1000,-1500,1500,1000,-1500,1500);
    gxy1[i] = new TH2D(Form("gem1_xy_%s",passNames[i]),"gem1_xy_distribution;x[mm];y[mm]",1000,-1500,1500,1000,-1500,1500);
    gxy2[i] = new TH2D(Form("gem2_xy_%s",passNames[i]),"gem2_xy_distribution;x[mm];y[mm]",1000,-1500,1500,1000,-1500,1500);
    gxy3[i] = new TH2D(Form("gem3_xy_%s",passNames[i]),"gem3_xy_distribution;x[mm];y[mm]",1000,-1500,1500,1000,-1500,1500);
    gxy4[i] = new TH2D(Form("gem4_xy_%s",passNames[i]),"gem4_xy_distribution;x[mm];y[mm]",1000,-1500,1500,1000,-1500,1500);
    thetar[i] = new TH2D(Form("theta_r_gem1_%s",passNames[i]),"theta_r_gem1_distribution;r[mm];#theta_{tg}",100, 500, 1300, 50, 0, 1.8);
    thetarp[i] = new TH2D(Form("theta_r'_gem1_%s",passNames[i]),"theta_r_prime_gem1_distribution;r';#theta_{tg}",100, 0, 0.1, 50, 0, 1.8);
    thetaphi[i] = new TH2D(Form("theta_phi_gem1_%s",passNames[i]),"theta_phi_gem1_distribution;#phi;#theta_{tg}",100, -pi, pi, 50, 0, 1.8);
    thetaphip[i] = new TH2D(Form("theta_phi'_gem1_%s",passNames[i]),"theta_phi_prime_gem1_distribution;#phi';#theta_{tg}",100, -0.1, 0.1, 50, 0, 1.8);

    for(int j=0; j<nEntries; j++){  

      T->GetEntry(j);

      if(sieve_r < 26.5) continue;
   
      double rprime = (gem1_x*gem1_px + gem1_y*gem1_py)/(gem1_r*gem1_pz);
      double phip = (-gem1_y*gem1_px + gem1_x*gem1_py)/(gem1_r*gem1_pz); 

      gr[i]->Fill(gem1_r,rate);  grp[i]->Fill(rprime,rate); gphi[i]->Fill(gem1_phi,rate); gphip[i]->Fill(phip,rate); 
      Etheta[i]->Fill(tg_th*(180/pi),tg_p/1000);  Etheta_weighted[i]->Fill(tg_th*(180/pi),tg_p/1000,rate); 
      sievexy[i]->Fill(sieve_x,sieve_y,rate);   mainxy[i]->Fill(main_x,main_y,rate);
      gxy1[i]->Fill(gem1_x,gem1_y,rate);  gxy2[i]->Fill(gem2_x,gem2_y,rate);  gxy3[i]->Fill(gem3_x,gem3_y,rate);  gxy4[i]->Fill(gem4_x,gem4_y,rate);
      thetar[i]->Fill(gem1_r,tg_th*(180/pi)); thetaphi[i]->Fill(gem1_phi,tg_th*(180/pi));
      thetarp[i]->Fill(rprime,tg_th*(180/pi)); thetaphip[i]->Fill(phip,tg_th*(180/pi));

    }

      c[0]->cd(i+1); mainxy[i]->Draw("colz"); 
      TLatex* t1 = new TLatex();
      t1->SetTextAlign(11);
      t1->SetTextSize(0.04);
      t1->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i]));
         

      c[1]->cd(i+1); sievexy[i]->Draw("colz"); 
      TLatex* t2 = new TLatex();
      t2->SetTextAlign(11);
      t2->SetTextSize(0.04);
      t2->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i]));

      c[2]->cd(i+1); gxy1[i]->Draw("colz"); 
      TLatex* t3 = new TLatex();
      t3->SetTextAlign(11);
      t3->SetTextSize(0.04);
      t3->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i])); 

      c[3]->cd(i+1); gxy2[i]->Draw("colz"); 
      TLatex* t4 = new TLatex();
      t4->SetTextAlign(11);
      t4->SetTextSize(0.04);
      t4->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i]));

      c[4]->cd(i+1); gxy3[i]->Draw("colz"); 
      TLatex* t5 = new TLatex();
      t5->SetTextAlign(11);
      t5->SetTextSize(0.04);
      t5->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i])); 
  
      c[5]->cd(i+1); gxy4[i]->Draw("colz"); 
      TLatex* t6 = new TLatex();
      t6->SetTextAlign(11);
      t6->SetTextSize(0.04);
      t6->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i]));

      c[6]->cd(i+1); gr[i]->Draw("hist"); 
      TLatex* t7 = new TLatex();
      t7->SetTextAlign(11);
      t7->SetTextSize(0.04);
      t7->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i])); 

      c[7]->cd(i+1); grp[i]->Draw("hist"); 
      TLatex* t8 = new TLatex();
      t8->SetTextAlign(11);
      t8->SetTextSize(0.04);
      t8->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i])); 

      c[8]->cd(i+1); gphi[i]->Draw("hist"); 
      TLatex* t9 = new TLatex();
      t9->SetTextAlign(11);
      t9->SetTextSize(0.04);
      t9->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i])); 
  
      c[9]->cd(i+1); gphip[i]->Draw("hist"); 
      TLatex* t10 = new TLatex();
      t10->SetTextAlign(11);
      t10->SetTextSize(0.04);
      t10->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i])); 

      c[10]->cd(i+1); thetar[i]->Draw("colz"); 
      TLatex* t11 = new TLatex();
      t11->SetTextAlign(11);
      t11->SetTextSize(0.04);
      t11->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i]));

      c[11]->cd(i+1); thetaphi[i]->Draw("colz"); 
      TLatex* t12 = new TLatex();
      t12->SetTextAlign(11);
      t12->SetTextSize(0.04);
      t12->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i]));  

      c[12]->cd(i+1); thetarp[i]->Draw("colz"); 
      TLatex* t13 = new TLatex();
      t13->SetTextAlign(11);
      t13->SetTextSize(0.04);
      t13->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i])); 
  
      c[13]->cd(i+1); thetaphip[i]->Draw("colz"); 
      TLatex* t14 = new TLatex();
      t14->SetTextAlign(11);
      t14->SetTextSize(0.04);
      t14->DrawLatexNDC(0.19,0.85,Form("%s",passNames[i]));

      c1->cd(1); if(i==0) Etheta[i]->Draw("p");
      else Etheta[i]->Draw("same p");
      Etheta[i]->SetMarkerColor(color[i]);


      c1->cd(2); if(i==0) Etheta_weighted[i]->Draw("p");
      else Etheta_weighted[i]->Draw("same p");
      Etheta_weighted[i]->SetMarkerColor(color[i]); 

  }

  TFile* fout = new TFile("initial_plots.root","RECREATE");
  fout->cd();

  for(int i=0; i<nPlots; i++){

    c[i]->Write(); }

  fout->Close();

}

     
