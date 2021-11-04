// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries,
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/PTResults" defined for the images to go to
//
//  Run using (for example):
//   build/reroot
//   .L scripts/DetailedSieve100HoleAnalysis1.C
//   DetailedSieve100HoleAnalysis()
//  Or use:
//   build/reroot -l -q -b 'DetailedSieve100HoleAnalysis1.C()'
//
//  Can put multiple root files in the script, and they will be chained together.


#include <TF1.h>

//100 is the sieve thickness in mm
void DetailedSieve12HoleAnalysisAllCP()
{

//---Set up Chain and Tree---

  //Allow Tree to use the root files that you call. This line creates a chain of root files that you can add onto.
  TChain* T = new TChain("T");

  //Add files from the directory "rootfilesPT/", "100" is the sieve thickness in mm
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm0.root");
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm1.root");
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm2.root");
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm3.root");
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm4.root");
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm5.root");
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm6.root");
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm7.root");
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm8.root");
  T->Add("rootfilesHA/HD12_sieveC12_ep_100k_100mm9.root");

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

//---Define Histograms---

  //---Clean Pass Histograms---

  //1D histogram for primaries that cleanly pass through the sieve hole 1 and make it to the main detector on the rings (r plot)
  TH1F *radial_clean_pass = new TH1F("radial_clean_pass","All Charged Particles that Hit the Main Detector Ring 2 (12mm Hole Diameter)", 1000, 710, 760);
  radial_clean_pass -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {

    T->GetEntry(iev);

    //Process hits again because we will now be filling histograms.
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //Look at primaries hitting main detector rings with positive z momentum.
      if((hit.pid == 11 || hit.pid == -11) && hit.pz >= 0 && hit.det == 28 && hit.r>=710 && hit.r<=760)
      {
        radial_clean_pass -> Fill(hit.r,rate);
      }

    }//end third loop over hits

  }//end loop over events

//--------------------------------------------------------------------------------

//---Draw and Save Histograms---

//---Separate the Histograms---

  TCanvas *separate = new TCanvas("separate", "All Charged Particles", 100, 100, 500, 500);

  radial_clean_pass -> Draw();

  separate -> SaveAs("images/HA/Sieve_12Hole_Analysis__AllCP.png");

}//end DetailedSieve100HoleAnalysis()

