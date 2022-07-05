const double pi = acos(-1);

void tail(){

  TFile* fin = new TFile("Cfoil_optics1DS_p5.root","READ");
  TTree* t = (TTree*)fin->Get("newT");
 
  double tg_th, tg_p, gem1_r, gem1_k, rate, ushybrid_r, ushybrid_k, dshybrid_r, dshybrid_k;
  double col2Ent_k, col2Exit_k, col4Ent_k, col4Exit_k, col5Ent_k, col5Exit_k, col6Ent_k, col6Exit_k;
  double lintelEnt_k, lintelExit_k, collar1Ent_k, collar1Exit_k, drift1_r, drift1_k, drift2_r, drift2_k, drift2_x, drift2_y;

  t->SetBranchAddress("tg_th",&tg_th);
  t->SetBranchAddress("tg_p",&tg_p);
  t->SetBranchAddress("gem1_r",&gem1_r);
  t->SetBranchAddress("gem1_k",&gem1_k);
  t->SetBranchAddress("rate",&rate);
  t->SetBranchAddress("ushybrid_r",&ushybrid_r);
  t->SetBranchAddress("ushybrid_k",&ushybrid_k);
  t->SetBranchAddress("dshybrid_r",&dshybrid_r);
  t->SetBranchAddress("dshybrid_k",&dshybrid_k);
  t->SetBranchAddress("col2Ent_k",&col2Ent_k);
  t->SetBranchAddress("col2Exit_k",&col2Exit_k);
  t->SetBranchAddress("col4Ent_k",&col4Ent_k);
  t->SetBranchAddress("col4Exit_k",&col4Exit_k);
  t->SetBranchAddress("col5Ent_k",&col5Ent_k);
  t->SetBranchAddress("col5Exit_k",&col5Exit_k);
  t->SetBranchAddress("col6Ent_k",&col6Ent_k);
  t->SetBranchAddress("col6Exit_k",&col6Exit_k);
  t->SetBranchAddress("lintelEnt_k",&lintelEnt_k);
  t->SetBranchAddress("lintelExit_k",&lintelExit_k);
  t->SetBranchAddress("collar1Ent_k",&collar1Ent_k);
  t->SetBranchAddress("collar1Exit_k",&collar1Exit_k);
  t->SetBranchAddress("drift1_r",&drift1_r);
  t->SetBranchAddress("drift1_k",&drift1_k);
  t->SetBranchAddress("drift2_r",&drift2_r);
  t->SetBranchAddress("drift2_k",&drift2_k);
  t->SetBranchAddress("drift2_x",&drift2_x);
  t->SetBranchAddress("drift2_y",&drift2_y);
  
  
  TH1D* th = new TH1D("th","Theta Distribution",100,0,1.8);
  TH1D* p = new TH1D("p","Momentum Distribution",100,0,12);
  TH1D* gem_r = new TH1D("gem_r","Radial Distribution at Gem Plane",800,500,1300);
  TH1D* gem_k = new TH1D("gem_k","Momentum Distribution at the Gem plane",100,0,12);
  TH2D* gem_kr = new TH2D("gem_kr","Gem k vs Gem r",800, 500, 1300, 100, 0, 12);
  TH1D* ds_r = new TH1D("ds_r","Radial Distribution",800,500,1300);
  TH1D* ds_k = new TH1D("ds_k","Momentum Distribution",100,0,12);
  TH1D* us_r = new TH1D("us_r","Radial Distribution",800,500,1300);
  TH1D* us_k = new TH1D("us_k","Momentum Distribution",100,0,12);
  TH1D* col2Ent = new TH1D("col2Ent","Momentum Distribution",100,0,12);
  TH1D* col2Exit = new TH1D("col2Exit","Momentum Distribution",100,0,12);
  TH1D* col4Ent = new TH1D("col4Ent","Momentum Distribution",100,0,12);
  TH1D* col4Exit = new TH1D("col4Exit","Momentum Distribution",100,0,12);
  TH1D* col5Ent = new TH1D("col5Ent","Momentum Distribution",100,0,12);
  TH1D* col5Exit = new TH1D("col5Exit","Momentum Distribution",100,0,12);
  TH1D* col6Ent = new TH1D("col6Ent","Momentum Distribution",100,0,12);
  TH1D* col6Exit = new TH1D("col6Exit","Momentum Distribution",100,0,12);
  TH1D* lintelEnt = new TH1D("lintelEnt","Momentum Distribution",100,0,12);
  TH1D* lintelExit = new TH1D("lintelExit","Momentum Distribution",100,0,12);
  TH1D* collar1Ent = new TH1D("collar1Ent","Momentum Distribution",100,0,12);
  TH1D* collar1Exit = new TH1D("collar1Exit","Momentum Distribution",100,0,12);
  TH1D* drift1 = new TH1D("drift1","Momentum Distribution",100,0,12);
  TH1D* drift2 = new TH1D("drift2","Momentum Distribution",100,0,12);
  TH1D* drift1r = new TH1D("drift1r","r Distribution",800,300,1300);
  TH1D* drift2r = new TH1D("drift2r","r Distribution",800,500,1300);
  TH2D* drift2_xy = new TH2D("drift2_xy","XY distribution at drift2 plane", 800,-800, 800, 800, -800, 800);

  int n = t->GetEntries();

  for(int i = 0; i<n; i++){

    t->GetEntry(i);

    if(!((gem1_r > 620 && gem1_r < 640) && gem1_k < 8000)) continue;

      th->Fill(tg_th*(180/pi), rate);
      p->Fill(tg_p/1000, rate);
      gem_r->Fill(gem1_r, rate);
      gem_k->Fill(gem1_k/1000, rate); 
      us_r->Fill(ushybrid_r, rate);
      us_k->Fill(ushybrid_k/1000, rate);
      ds_r->Fill(dshybrid_r, rate);
      ds_k->Fill(dshybrid_k/1000, rate); 
      col2Ent->Fill(col2Ent_k/1000, rate);
      col2Exit->Fill(col2Exit_k/1000, rate); 
      col4Ent->Fill(col4Ent_k/1000, rate);
      col4Exit->Fill(col4Exit_k/1000, rate); 
      col5Ent->Fill(col5Ent_k/1000, rate);
      col5Exit->Fill(col5Exit_k/1000, rate); 
      col6Ent->Fill(col6Ent_k/1000, rate);
      col6Exit->Fill(col6Exit_k/1000, rate);
      lintelEnt->Fill(lintelEnt_k/1000, rate);
      lintelExit->Fill(lintelExit_k/1000, rate);
      collar1Ent->Fill(collar1Ent_k/1000, rate);
      collar1Exit->Fill(collar1Exit_k/1000, rate);
      drift1->Fill(drift1_k/1000, rate);
      drift2->Fill(drift2_k/1000, rate);
      drift1r->Fill(drift1_r, rate);
      drift2r->Fill(drift2_r, rate);
      drift2_xy->Fill(drift2_x, drift2_y, rate);
      gem_kr->Fill(gem1_r, gem1_k/1000, rate);

    

  }

  TFile* fout = new TFile("tail.root","RECREATE");
  fout->cd();
  th->Write(); p->Write(); gem_r->Write(); gem_k->Write();
  us_k->Write(); us_r->Write(); ds_k->Write(); ds_r->Write(); 
  col2Ent->Write();
  col2Exit->Write();
  col4Ent->Write();
  col4Exit->Write();
  col5Ent->Write();
  col5Exit->Write();
  col6Ent->Write();
  col6Exit->Write();
  lintelEnt->Write();
  lintelExit->Write();
  collar1Ent->Write();
  collar1Exit->Write(); drift1->Write(); drift2->Write(); drift1r->Write(); drift2r->Write(); drift2_xy->Write(); gem_kr->Write();
  fout->Close();

}
