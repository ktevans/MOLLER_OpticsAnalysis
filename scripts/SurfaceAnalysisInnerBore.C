
#include <TF1.h>
void Analysis(const TString& collimator, const TString& geo)
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");

  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_0.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_1.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_2.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_3.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_4.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_5.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_6.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_7.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_8.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_9.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_10.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_11.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_12.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_13.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_14.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_15.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_16.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_17.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_18.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_19.root");

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

  Double_t endep = 0;

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
      {
        surface_all -> Fill(hit.x, hit.y, rate);
        surface_all_e -> Fill(hit.r, hit.e, rate);

        if(hit.pid==11 || hit.pid==-11)
        {
          surface_CP -> Fill(hit.x, hit.y, rate);
          surface_CP_e -> Fill(hit.r, hit.e, rate);
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

