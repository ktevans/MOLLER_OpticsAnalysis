// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries, 
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/EAnalysis" defined for the images to go to 
//  
//  Run using (for example):
//   build/reroot
//   .L scripts/PrimaryAnalysis100mm0.C
//   PunchThru()
//
//  Can put multiple root files in the script, and they will be chained together.
//

#include <TF1.h>
void PrimaryAnalysis100mm0()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  
  //Add files from the directory "rootfilesPT/", "100" is the sieve thickness in mm
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm0.root");

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

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);


    //Process over hits
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      if((hit.trid == 1 || hit.trid == 2) && hit.det ==28 && hit.r >= 650 && hit.r <= 1200 && hit.pz >= 0)
      {
        prim_pass -> Fill(hit.r, rate);
      }

    }//end process over hits
  }//end process over events

//--------------------------------------------------------------------------------
//Draw and save the histograms

  TCanvas *main_all = new TCanvas("main_all","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

  prim_pass -> Draw();

  main_all -> SaveAs("images/PrimAnalysis/prim_main_WSieve_100_0.png");


}//end PunchThru()
