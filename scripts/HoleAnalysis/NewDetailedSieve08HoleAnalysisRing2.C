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
void NewDetailedSieve08HoleAnalysisRing2()
{

//---Set up Chain and Tree---

  //Allow Tree to use the root files that you call. This line creates a chain of root files that you can add onto.
  TChain* T = new TChain("T");

  //Add files from the directory "rootfilesPT/", "100" is the sieve thickness in mm
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm0.root");
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm1.root");
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm2.root");
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm3.root");
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm4.root");
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm5.root");
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm6.root");
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm7.root");
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm8.root");
  T->Add("rootfilesHA/HD08_sieveC12_ep_100k_100mm9.root");

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
  TH1F *radial_clean_pass = new TH1F("radial_clean_pass","Charged Particles that Pass Through Any of the Sieve (100mm) Holes (08mm Diameter) and Hit the Main Detector", 1000, 710, 760);
  radial_clean_pass -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

  //---Sieve Hole Showers---

  //1D histogram for charged particles that result from primaries entering the sieve holes and showering and make it to the main detector on the rings (r plot)
  TH1F *radial_hole_shower = new TH1F("radial_hole_shower","Charged Particles that Result from Primaries Hitting a Sieve Hole (08mm Diameter) and then Showering Through Sieve (100mm) and Hit the Main Detector", 1000, 710, 760);
  radial_hole_shower -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

  //---Sieve Surface Showers---

  //1D histogram for charged particles that result from primaries hitting the sieve surface and showering into one of the sieve holes and then make it to the main detector on the rings (r plot)
  TH1F *radial_hit_shower = new TH1F("radial_hit_shower","Charged Particles that Result from Primaries Hitting the Sieve Surface and then Showering into a Sieve (100mm) Hole (08mm Diameter) and Hit the Main Detector", 1000, 710, 760);
  radial_hit_shower -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

//----------------------------------------------------------------------------

//---Define LLogical Flags---

  //Test if a primary hit the upstream surface of the sieve hole detectors, i.e., if a primary entered one of the sieve holes.
  bool in_hole = false;

  //Test if a primary cleanly passed through one of the sieve holes.
  //in_hole_# && prim_out_hole_#
  bool clean_pass_prim = false;
  bool clean_pass_e = false;

  //Test if a primary entered a hole and then caused a shower.
  //in_hole_# && !prim_out_hole_#
  bool hole_shower = false;

  //Test if a primary hit the sieve surface and then caused a shower. This is shower leakage.
  //!in_hole_# && any_out_hole_#
  bool hit_shower = false;

  //Look at the energy of the particles before and after they pass through the sieve.
  Float_t in_e = 0;
  Float_t out_e = 0;

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {

    T->GetEntry(iev);

    in_hole = false;

    clean_pass_prim = false;
    clean_pass_e = false;

    hole_shower = false;

    hit_shower = false;

    in_e = 0;
    out_e = 0;


    //Process hits, i.e., loop over all the hits in this event
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //Test if the primaries entered the holes.
      if((hit.trid == 1 || hit.trid == 2 || hit.pid == 11 || hit.pid == -11) && (hit.det == 1001 || hit.det == 1002 || hit.det == 1003) && abs(hit.z - 575) < 0.1 && hit.pz >= 0)
      {
        in_hole = true;
      }

    }//end loop over hits

    //Process hits again because the booleans we will flag here will be dependent on the previous ones.
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //Record the energy of charged particles and primaries that hit the upstream surface of the sieve.
      if((hit.pid == 11 || hit.pid == -11) && hit.r >= 35.306 && hit.r <= 97.9932 && hit.det == 1004 && hit.pz >= 0)
      {
        in_e = hit.e;
      }

      //Record the energy of charged particles and primaries that hit the downstream surface of the sieve.
      if((hit.pid == 11 || hit.pid == -11) && hit.r >= 35.306 && hit.r <= 97.9932 && hit.det == 1005 && hit.pz >= 0)
      {
        out_e = hit.e;
      }

      //Test if primaries cleanly passed through the holes. If the energy of the incoming particle is less than 0.1MeV different than the energy of the outgoing particle, then we can say that this is a clean pass because the energy of the particle doesn't change.
      if(in_hole && abs(in_e - out_e) < 0.1 && (hit.trid == 1 || hit.trid == 2))
      {
        clean_pass_prim = true;
      }

      //Test if a non-primary charged particle cleanly passed through the holes.
      if(in_hole && abs(in_e - out_e) < 0.1 &&(hit.pid == 11 || hit.pid == -11))
      {
        clean_pass_e = true;
      }

      //Test if primaries entered a hole and then caused a shower.
      if(in_hole && !clean_pass_e && (hit.pid == 11 || hit.pid == -11))
      {
        hole_shower = true;
      }

      //Test if primaries hits the sieve surface and then caused a shower to exit out of the hole.
      if(!in_hole && !clean_pass_e && (hit.pid == 11 || hit.pid == -11))
      {
        hit_shower = true;
      }

    }//end second loop over hits


    //Process hits again because we will now be filling histograms.
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //Look at primaries hitting main detector rings with positive z momentum.
      if((hit.pid == 11 || hit.pid == -11) && hit.pz >= 0 && hit.det == 28 && hit.r>=710 && hit.r<=760)
      {

        if(clean_pass_e)
        {
          //fill histogram for primaries that cleanly passed through the sieve holes and made it to the rings on the main detector.
          radial_clean_pass -> Fill(hit.r, rate);
        }

        if(hole_shower)
        {
          //fill histogram for charged particles from sieve hole showers that made it to the rings on the main detector.
          radial_hole_shower -> Fill(hit.r, rate);
        }

        if(hit_shower)
        {
          //fill histogram for charged particles from sieve surface showers that made it to the rings on the main detector.
          radial_hit_shower -> Fill(hit.r, rate);
        }

      }

    }//end third loop over hits

  }//end loop over events

//--------------------------------------------------------------------------------

//---Draw and Save Histograms---

//---Separate the Histograms---

  TCanvas *separate = new TCanvas("separate", "All Charged Particles", 100, 100, 1500, 500);

  separate -> Divide(3,1);

  separate -> cd(1);
  radial_clean_pass -> Draw();

  separate -> cd(2);
  radial_hole_shower -> Draw();

  separate -> cd(3);
  radial_hit_shower -> Draw();

  separate -> SaveAs("images/HA/Only_CP_08Hole_Analysis_Sieve_100_Ring2.png");

}//end DetailedSieve100HoleAnalysis()

