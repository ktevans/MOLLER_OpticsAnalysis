// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries, 
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/EAnalysis" defined for the images to go to 
//  
//  Run using (for example):
//   build/reroot
//   .L scripts/PrimaryAnalysis100mm4.C
//   PunchThru()
//
//  Can put multiple root files in the script, and they will be chained together.
//

#include <TF1.h>
void NS_PrimaryUDAnalysis100mm4()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  
  //Add files from the directory "rootfilesPT/", "100" is the sieve thickness in mm
  T->Add("rootfilesPT/NoSieveC12_ep_100k_100mm4.root");

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

//----------------------------------------------------------------------------

  //Define Histograms that we will fill later

  TH1F *prim_pass = new TH1F("prim_pass","Primaries that Hit the Main Detector Rings with a W Sieve (100mm)", 1000, 650, 1200);
  prim_pass -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

  TH1F *prim_us = new TH1F("prim_us","Primaries that Hit the Upstream Surface of a W Sieve (100mm)", 1000, 30, 100);
  prim_us -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

  TH1F *prim_ds = new TH1F("prim_ds","Primaries that Hit the Downstream Surface of a W Sieve (100mm)", 1000, 30, 100);
  prim_ds -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);

    //Process over hits
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      if((hit.trid == 1 || hit.trid == 2) && hit.pz >= 0)
      {
        if(hit.det == 28 && hit.r >= 650 && hit.r <= 1200)
        {
          prim_pass -> Fill(hit.r, rate);
        }

        if(hit.det == 1004 && hit.r >= 35.306 && hit.r <= 97.9932)
        {
          prim_us -> Fill(hit.r, rate);
        }

        if(hit.det == 1005 && hit.r >= 35.306 && hit.r <= 97.9932)
        {
          prim_ds -> Fill(hit.r, rate);
        }
      }

    }//end process over hits
  }//end process over events

//--------------------------------------------------------------------------------
//Draw and save the histograms

  TCanvas *main = new TCanvas("main","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

  prim_pass -> Draw();

  main -> SaveAs("images/PrimAnalysis/prim_main_WSieve_100_4.png");

  TCanvas *us = new TCanvas("us","Particles Hitting the Upstream Detector", 1000, 1000, 1000, 1000);

  prim_us -> Draw();

  us -> SaveAs("images/PrimAnalysis/prim_us_WSieve_100_4.png");

  TCanvas *ds = new TCanvas("ds","Particles Hitting the Downstream Detector", 1000, 1000, 1000, 1000);

  prim_ds -> Draw();

  ds -> SaveAs("images/PrimAnalysis/prim_ds_WSieve_100_4.png");


}//end PunchThru()
