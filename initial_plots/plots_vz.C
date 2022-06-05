
const int nFiles = 4;
const int nPlots = 8;
const int n = 2;     

const char* type[n] = {"with_sieve", "without_sieve"};
const char* filename[nFiles] = { "slim_output/Cfoil_optics1US_p3.root", "slim_output/Cfoil_optics1DS_p3.root", "slim_output/Cfoil_optics2US_p3.root", "slim_output/Cfoil_optics2DS_p3.root"};
const char* filename_nosieve[nFiles] = { "slim_output_nosieve/optics1US_p3_nosieve.root", "slim_output_nosieve/optics1DS_p3_nosieve.root", "slim_output_nosieve/optics2US_p3_nosieve.root",
                                         "slim_output_nosieve/optics2DS_p3_nosieve.root"};
const char* locations[nFiles] = {"optics1US","optics1DS","optics2US","optics2DS"};

const char* plotName[nPlots] = {"vz_vs_gem_r", "vz_vs_gem_rp", "vz_vs_gem_ph", "vz_vs_gem_php", "vz_vs_tg_th", "vz_vs_tg_ph", "vz_vs_tg_p", "sieve_r_vs_tg_th"};

TH2D* vz_gem_r[n][nFiles] = {NULL};
TH2D* vz_gem_rp[n][nFiles] = {NULL};
TH2D* vz_gem_ph[n][nFiles] = {NULL};
TH2D* vz_gem_php[n][nFiles] = {NULL};
TH2D* vz_tg_th[n][nFiles] = {NULL};
TH2D* vz_tg_ph[n][nFiles] = {NULL};
TH2D* vz_tg_p[n][nFiles] = {NULL};
TH2D* sieve_r_tg_th[n][nFiles] = {NULL};
TCanvas* c[nFiles][nPlots];

double pi = acos(-1);

void plots_vz(){

  for(int m=0; m<nFiles; m++){

   for(int k=0; k<nPlots; k++){

     c[m][k] = new TCanvas(Form("%s_%s",locations[m],plotName[k])); c[m][k]->Divide(2,1);} }

     for(int i=0; i<nFiles; i++){

      TFile* fin = new TFile(Form("%s",filename[i]),"READ");
      TFile* fin_nosieve = new TFile(Form("%s",filename_nosieve[i]),"READ");

      TTree* T1 = (TTree*)fin->Get("newT");   TTree* T2 = (TTree*)fin_nosieve->Get("newT");

      int nEntries1 = T1->GetEntries();  int nEntries2 = T2->GetEntries(); 
 
      double sieve_r1, gem1_x1, gem1_y1;
    double gem1_r1, gem1_rp1, gem1_phi1, gem1_phip1, gem1_px1, gem1_py1, gem1_pz1;
    double tg_th1, tg_ph1, tg_p1, tg_vz1; double rate1;

    double sieve_r2, gem1_x2, gem1_y2;
    double gem1_r2, gem1_rp2, gem1_phi2, gem1_phip2, gem1_px2, gem1_py2, gem1_pz2;
    double tg_th2, tg_ph2, tg_p2, tg_vz2; double rate2;


    T1->SetBranchAddress("gem1_r",&gem1_r1);    T2->SetBranchAddress("gem1_r",&gem1_r2);
    T1->SetBranchAddress("gem1_x",&gem1_x1);    T2->SetBranchAddress("gem1_x",&gem1_x2);
    T1->SetBranchAddress("gem1_y",&gem1_y1);    T2->SetBranchAddress("gem1_y",&gem1_y2);
    T1->SetBranchAddress("gem1_ph",&gem1_phi1); T2->SetBranchAddress("gem1_ph",&gem1_phi2);
    T1->SetBranchAddress("gem1_px",&gem1_px1);  T2->SetBranchAddress("gem1_px",&gem1_px2);
    T1->SetBranchAddress("gem1_py",&gem1_py1);  T2->SetBranchAddress("gem1_py",&gem1_py2);
    T1->SetBranchAddress("gem1_pz",&gem1_pz1);  T2->SetBranchAddress("gem1_pz",&gem1_pz2);
    T1->SetBranchAddress("tg_th",&tg_th1);      T2->SetBranchAddress("tg_th",&tg_th2);
    T1->SetBranchAddress("tg_ph",&tg_ph1);      T2->SetBranchAddress("tg_ph",&tg_ph2);
    T1->SetBranchAddress("tg_p",&tg_p1);        T2->SetBranchAddress("tg_p",&tg_p2);
    T1->SetBranchAddress("tg_vz",&tg_vz1);       T2->SetBranchAddress("tg_vz",&tg_vz2);
    T1->SetBranchAddress("rate",&rate1);        T2->SetBranchAddress("rate",&rate2);
    T1->SetBranchAddress("sieve_r",&sieve_r1);  T2->SetBranchAddress("sieve_r",&sieve_r2);

   
    for(int l=0; l<n; l++){

      vz_gem_r[l][i] = new TH2D(Form("vz_gem_r_%s_%s",type[l],locations[i]),"vz_gem_r;gem_r[mm];vz(mm)",100,500,1300,100,-5200,-3800);
      vz_gem_rp[l][i] = new TH2D(Form("vz_gem_rp_%s_%s",type[l],locations[i]),"vz_gem_rp;gem_rp;vz(mm)",100,0,0.1,100,-5200,-3800);
      vz_gem_ph[l][i] = new TH2D(Form("vz_gem_phi_%s_%s",type[l],locations[i]),"vz_gem_phi;gem_phi(rad);vz(mm)",100,-pi,pi,100,-5200,-3800);
      vz_gem_php[l][i] = new TH2D(Form("vz_gem_phip_%s_%s",type[l],locations[i]),"vz_gem_phip;gem_phip;vz(mm)",100,-0.01,0.01,100,-5200,-3800);
      vz_tg_th[l][i] = new TH2D(Form("vz_tg_th_%s_%s",type[l],locations[i]),"vz_tg_th;tg_th(deg);vz(mm)",50,0,1.8,100,-5200,-3800);
      vz_tg_ph[l][i] = new TH2D(Form("vz_tg_ph_%s_%s",type[l],locations[i]),"vz_tg_ph;tg_ph(rad);vz(mm)",100,-pi,pi,100,-5200,-3800);
      vz_tg_p[l][i] = new TH2D(Form("vz_tg_p_%s_%s",type[l],locations[i]),"vz_tg_p;tg_p(GeV);vz(mm)",100,0,12,100,-5200,-3800);
      sieve_r_tg_th[l][i] = new TH2D(Form("sieve_r_tg_th_%s_%s",type[l],locations[i]),"sieve_r_tg_th;sieve_r(mm);tg_th(deg)",200,0,100,50,0,1.8); }
    

      for(int j=0; j<nEntries1; j++){  

         T1->GetEntry(j);

         if(sieve_r1 < 26.5) continue;
   
         double rprime = (gem1_x1*gem1_px1 + gem1_y1*gem1_py1)/(gem1_r1*gem1_pz1);
         double phip = (-gem1_y1*gem1_px1 + gem1_x1*gem1_py1)/(gem1_r1*gem1_pz1); 

	 vz_gem_r[0][i]->Fill(gem1_r1,tg_vz1,rate1);  vz_gem_rp[0][i]->Fill(rprime,tg_vz1,rate1);
         vz_gem_ph[0][i]->Fill(gem1_phi1,tg_vz1,rate1); vz_gem_php[0][i]->Fill(phip,tg_vz1,rate1);
         vz_tg_th[0][i]->Fill((tg_th1)*180/pi,tg_vz1,rate1);   vz_tg_ph[0][i]->Fill(tg_ph1,tg_vz1,rate1);
         vz_tg_p[0][i]->Fill(tg_p1/1000,tg_vz1,rate1);  sieve_r_tg_th[0][i]->Fill(sieve_r1,tg_th1*(180/pi),rate1);        

    }

    for(int j=0; j<nEntries2; j++){  

         T2->GetEntry(j);

         if(sieve_r2 < 26.5) continue;
   
         double rprime = (gem1_x2*gem1_px2 + gem1_y2*gem1_py2)/(gem1_r2*gem1_pz2);
         double phip = (-gem1_y2*gem1_px2 + gem1_x2*gem1_py2)/(gem1_r2*gem1_pz2); 

	 vz_gem_r[1][i]->Fill(gem1_r2,tg_vz2,rate2);  vz_gem_rp[1][i]->Fill(rprime,tg_vz2,rate2);
         vz_gem_ph[1][i]->Fill(gem1_phi2,tg_vz2,rate2); vz_gem_php[1][i]->Fill(phip,tg_vz2,rate2);
         vz_tg_th[1][i]->Fill((tg_th2)*180/pi,tg_vz2,rate2);   vz_tg_ph[1][i]->Fill(tg_ph2,tg_vz2,rate2);
         vz_tg_p[1][i]->Fill(tg_p2/1000,tg_vz2,rate2);  sieve_r_tg_th[1][i]->Fill(sieve_r2,tg_th2*(180/pi),rate2);        

    }

    

      c[i][0]->cd(1); vz_gem_r[0][i]->Draw("colz");    c[i][0]->cd(2); vz_gem_r[1][i]->Draw("colz");
      c[i][1]->cd(1); vz_gem_rp[0][i]->Draw("colz");   c[i][1]->cd(2); vz_gem_rp[1][i]->Draw("colz");
      c[i][2]->cd(1); vz_gem_ph[0][i]->Draw("colz");   c[i][2]->cd(2); vz_gem_ph[1][i]->Draw("colz");
      c[i][3]->cd(1); vz_gem_php[0][i]->Draw("colz");  c[i][3]->cd(2); vz_gem_php[1][i]->Draw("colz");
      c[i][4]->cd(1); vz_tg_th[0][i]->Draw("colz");    c[i][4]->cd(2); vz_tg_th[1][i]->Draw("colz");
      c[i][5]->cd(1); vz_tg_ph[0][i]->Draw("colz");    c[i][5]->cd(2); vz_tg_ph[1][i]->Draw("colz");
      c[i][6]->cd(1); vz_tg_p[0][i]->Draw("colz");     c[i][6]->cd(2); vz_tg_p[1][i]->Draw("colz");
      c[i][7]->cd(1); sieve_r_tg_th[0][i]->Draw("colz");     c[i][7]->cd(2); sieve_r_tg_th[1][i]->Draw("colz");  
      

     }

  TFile* fout = new TFile("initial_plots_vz.root","RECREATE");
  fout->cd();

  for(int j=0; j<4; j++){

    for(int i=0; i<nPlots; i++){

    c[j][i]->Write();
 
    }
  }

  fout->Close();

  }
