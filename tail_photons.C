
TFile *fout;
TH1D* energy;
TH2D* vyz;
TH2D* vyz_e;

long nTotEv(0);
string fin;

void initHisto();
long processOne(string);
void process(int);
void writeOutput();

void tail_photons(const string& finName = "./remollout.root", int test_run=0){
  fin = finName;
  initHisto();
  process(test_run);
  writeOutput();
}

void process(int test_run){

  if(fin==""){
    cout<<"\t did not find input file. Quitting!"<<endl;
    return 2;
  }

  int nFiles(0);
  if( fin.find(".root") < fin.size() ){
    cout<<"Processing single file:\n\t"<<fin<<endl;
    nTotEv+=processOne(fin);
    nFiles=1;
  }

   else{
    cout<<"Attempting to process list of output from\n\t"<<fin<<endl;
    ifstream ifile(fin.c_str());
    string data;
    while(ifile>>data){
      cout<<" processing: "<<data<<endl;
      nTotEv+=processOne(data);
      nFiles++;
    
      if(test_run==1 && nFiles==10) break;

    }
  }
  
  cout<<"\nFinished processing a total of "<<nTotEv<<endl;
}

void initHisto(){
  string foutNm = "tail_photons.root";

  fout = new TFile(foutNm.c_str(),"RECREATE");
 
  energy = new TH1D("energy", "Photons energy distribution", 100, 0, 12);
  vyz = new TH2D("vyz", "Vertex Distributions;vy[mm];vz[mm]", 1000, 18500, 18700, 1000, -1000, 1000);
  vyz_e = new TH2D("vyz_e", "Vertex Distributions (Energy Weighted);vz[mm];vy[mm]", 1000, 18500, 18700, 1000, -1000, 1000);
			 
 
} 

long processOne(string fnm){

  TFile *fin=TFile::Open(fnm.c_str(),"READ");
  if(!fin->IsOpen() || fin->IsZombie()){
    cout<<"Problem: can't find file: "<<fnm<<endl;
    fin->Close();
    delete fin;
    return 0;
  }

  TTree *t=(TTree*)fin->Get("T");
  if (t == 0) return 0;
  Double_t rate=0;
  std::vector<remollGenericDetectorHit_t> *hit=0;
  t->SetBranchAddress("rate", &rate);
  t->SetBranchAddress("hit", &hit);
  
  long nEntries = t->GetEntries();

  for (Long64_t event = 0; event < nEntries; event++) {
   
    t->GetEntry(event); 
   
    if(event%5000==0) cout << "At tree entry = " << event << endl;

    if(std::isnan(rate) || std::isinf(rate)) continue;

    int hits_main = 0; bool found = false;
 
    for(int j=0;j<hit->size();j++){

      if(std::isnan(hit->at(j).x) || std::isinf(hit->at(j).x)) continue;
      if(std::isnan(hit->at(j).y) || std::isinf(hit->at(j).y)) continue;
      
      if(hit->at(j).det==28 && hit->at(j).pid==11 && hit->at(j).trid==1 && hit->at(j).mtrid==0) hits_main++;
     
    }

    if(hits_main>0){

          for(int k=0;k<hit->size();k++){
   
	    if(!(hit->at(k).det == 32 && hit->at(k).pid==11 && hit->at(k).trid==1 && hit->at(k).mtrid==0)) continue;
            if(hit->at(k).r > 620 && hit->at(k).r < 640 && hit->at(k).k < 8000 ) found = true;

         }

    }


    if(!found) continue; 
             
        for(int l=0;l<hit->size();l++){

          if(hit->at(l).det != 5719) continue; 
          if(hit->at(l).pid != 22) continue;

          if(abs(hit->at(l).vy) > 100){

           energy->Fill(hit->at(l).k/1000, rate);
          vyz->Fill(hit->at(l).vz, hit->at(l).vy, rate);
          vyz_e->Fill(hit->at(l).vz, hit->at(l).vy, rate*hit->at(l).k); }

  }

  }

  fin->Close();
  delete fin;
  return nEntries;
}
    

void writeOutput(){
  fout->cd();

  energy->Write();
  vyz->Write();
  vyz_e->Write();

  fout->Close();
}

  

