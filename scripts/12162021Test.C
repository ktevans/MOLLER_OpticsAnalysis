#include <TF1.h>
void Analysis(const TString& collimator, const TString& geo)
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");

  T->Add("rootfilesPT/test_"+geo+"_"+collimator+".root");

  double curr = 85e-6; // Originally 70 microamps
  double nelec_s = curr/1.6e-19; //Number of electrons per second
  Double_t scale = nelec_s/T->GetEntries();

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

  Double_t endep = 0.0;

  double power = 0.0;

  double Edephigh = 11000.0;
  int Edepnbin = 100;

//----------------------------------------------------------------------------

  //Define Histograms that we will fill later

  //2D histogram for particles that hit the sieve/blocker (xy plot)
  TH2F *surface_all = new TH2F("surface_all","All Particles that Hit the Surface of a 90mm "+collimator+" with "+geo+" Geometry", 1000, -120, 120, 1000, -120, 120);
  surface_all -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  surface_all -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  //2D histogram for the energy of particles that hit the sieve/blocker (radial plot)
  TH2F *surface_all_e = new TH2F("surface_all_e","Energy of All Particles that Hit the Surface of a 90mm "+collimator+" with "+geo+" Geometry", 100, 25, 105, 100, 0, 11000);
  surface_all_e -> GetXaxis() -> SetTitle("r Position of Hits [mm]");
  surface_all_e -> GetYaxis() -> SetTitle("Energy of Hits [MeV]");

  //2D histogram for particles that hit the sieve/blocker (xy plot)
  TH2F *surface_CP = new TH2F("surface_CP","All Charged Particles that Hit the Surface of a 90mm "+collimator+" with "+geo+" Geometry", 1000, -120, 120, 1000, -120, 120);
  surface_CP -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  surface_CP -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  //2D histogram for the energy of particles that hit the sieve/blocker (radial plot)
  TH2F *surface_CP_e = new TH2F("surface_CP_e","Energy of All Charged Particles that Hit the Surface of a 90mm "+collimator+" with "+geo+" Geometry", 100, 25, 105, 100, 0, 11000);
  surface_CP_e -> GetXaxis() -> SetTitle("r Position of Hits [mm]");
  surface_CP_e -> GetYaxis() -> SetTitle("Energy of Hits [MeV]");

  //Energy deposition of charged particles

  TH1F *Edep_CP = new TH1F("Edep_CP", "Energy Deposited on the Surface of a 90mm "+collimator+" with "+geo+" Geometry", Edepnbin, 0, Edephigh);
  Edep_CP -> GetXaxis() -> SetTitle("Energy Deposition [MeV]");
  Edep_CP -> GetYaxis() -> SetTitle("Rate [MeV^{-1}s^{-1}]");

  T->Project("Edep_CP", "sum.edep", Form("%g*(sum.det==1000 && (sum.pid==11 || sum.pid==-11))", scale*((double) Edepnbin)/Edephigh));
  //T->Project("Edep_CP", "sum.edep", Form("sum.det==1000 && (sum.pid==11 || sum.pid==-11)", scale*((double) Edepnbin)/Edephigh));


  TH1F *Ewdep_CP = new TH1F("Ewdep_CP", "Energy Deposited on the Surface of a 90mm "+collimator+" with "+geo+" Geometry", Edepnbin, 0, Edephigh);
  Ewdep_CP -> GetXaxis() -> SetTitle("Energy Deposition [MeV]");
  Ewdep_CP -> GetYaxis() -> SetTitle("Rate [MeV^{-1}s^{-1}]");

  T->Project("Ewdep_CP", "sum.edep", Form("%g*sum.edep*(sum.det==1000 && (sum.pid==11 || sum.pid==-11) && sum.edep>1e-20)", scale));
  //T->Project("Ewdep_CP", "sum.edep", Form("sum.edep*(sum.det==1000 && (sum.pid==11 || sum.pid==-11) && sum.edep>1e-20)", scale));


  //2D histogram for particles that hit the sieve/blocker (xy plot)
  TH2F *surface_gamma = new TH2F("surface_gamma","All Gammas that Hit the Surface of a 90mm "+collimator+" with "+geo+" Geometry", 1000, -120, 120, 1000, -120, 120);
  surface_gamma -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  surface_gamma -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  //2D histogram for the energy of particles that hit the sieve/blocker (radial plot)
  TH2F *surface_gamma_e = new TH2F("surface_gamma_e","Energy of All Gammas that Hit the Surface of a 90mm "+collimator+" with "+geo+" Geometry", 100, 25, 105, 100, 0, 11000);
  surface_gamma_e -> GetXaxis() -> SetTitle("r Position of Hits [mm]");
  surface_gamma_e -> GetYaxis() -> SetTitle("Energy of Hits [MeV]");

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);

    //process over hits
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      if (hit.det==1000 && hit.pz>=0)
      //&& abs(hit.z-580)<=0.1
      {
        surface_all -> Fill(hit.x, hit.y, rate);
        surface_all_e -> Fill(hit.r, hit.e, rate);

        if(hit.pid==11 || hit.pid==-11)
        {
          surface_CP -> Fill(hit.x, hit.y, rate);
          surface_CP_e -> Fill(hit.r, hit.e, rate);

          //Edep_CP -> Fill(hit.edep, rate);
        }

        if(hit.pid==22)
        {
          surface_gamma -> Fill(hit.x, hit.y, rate);
          surface_gamma_e -> Fill(hit.r, hit.e, rate);
        }

        endep += hit.edep;

      }

    }//end process over hits

  }//end process over events

  cout<<endep<<endl;

//--------------------------------------------------------------------------------
//Draw and save the histograms

//Create a canvas on which to draw the histograms
TCanvas *all = new TCanvas("all","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

surface_all -> Draw();

//Save the canvas as an image in the director "remoll/images/Blocker/"
all -> SaveAs("images/InnerBore/All_90mm"+collimator+"_"+geo+".png");

//Create a canvas on which to draw the histograms
TCanvas *all_e = new TCanvas("all_e","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

surface_all_e -> Draw();

//Save the canvas as an image in the director "remoll/images/Blocker/"
all_e -> SaveAs("images/InnerBore/All_Energy_90mm"+collimator+"_"+geo+".png");

//Charged particles

//Create a canvas on which to draw the histograms
TCanvas *all_CP = new TCanvas("all_CP","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

surface_CP -> Draw();

//Save the canvas as an image in the director "remoll/images/Blocker/"
all_CP -> SaveAs("images/InnerBore/CP_90mm"+collimator+"_"+geo+".png");

//Create a canvas on which to draw the histograms
TCanvas *all_CP_e = new TCanvas("all_CP_e","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

surface_CP_e -> Draw();

//Save the canvas as an image in the director "remoll/images/Blocker/"
all_CP_e -> SaveAs("images/InnerBore/CP_Energy_90mm"+collimator+"_"+geo+".png");

//--------------------------------------------------------------------

//Create a canvas on which to draw the histograms
TCanvas *edep_CP_e = new TCanvas("edep_CP_e","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

Edep_CP -> Draw("B");

power = Ewdep_CP -> Integral()*1.6e-13;
printf("Upstream power = %f\n", power);
TPaveLabel *Plab0 = new TPaveLabel(0.37, 0.76, 0.85, 0.87, Form("%5.1f W @ %4.1f #muA", power, curr*1e6), "NDC");
Plab0->Draw();

//Save the canvas as an image in the director "remoll/images/Blocker/"
edep_CP_e -> SaveAs("images/InnerBore/CP_Edep_90mm"+collimator+"_"+geo+".png");

//--------------------------------------------------------------------

//Gammas

//Create a canvas on which to draw the histograms
TCanvas *all_Gamma = new TCanvas("all_Gamma","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

surface_gamma -> Draw();

//Save the canvas as an image in the director "remoll/images/Blocker/"
all_Gamma -> SaveAs("images/InnerBore/Gamma_90mm"+collimator+"_"+geo+".png");

//Create a canvas on which to draw the histograms
TCanvas *all_Gamma_e = new TCanvas("all_Gamma_e","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

surface_gamma_e -> Draw();

//Save the canvas as an image in the director "remoll/images/Blocker/"
all_Gamma_e -> SaveAs("images/InnerBore/Gamma_Energy_90mm"+collimator+"_"+geo+".png");


}//end

