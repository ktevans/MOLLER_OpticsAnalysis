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
void DetailedSieve100HoleShowerAnalysis()
{

//---Set up Chain and Tree---

  //Allow Tree to use the root files that you call. This line creates a chain of root files that you can add onto.
  TChain* T = new TChain("T");

  //Add files from the directory "rootfilesPT/", "100" is the sieve thickness in mm
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm0.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm1.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm2.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm3.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm4.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm5.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm6.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm7.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm8.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm9.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm10.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm11.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm12.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm13.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm14.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm15.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm16.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm17.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm18.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm19.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm20.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm21.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm22.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm23.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm24.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm25.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm26.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm27.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm28.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_100mm29.root");

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

  //---Sieve Hole Showers---

  //1D histogram for charged particles that result from primaries entering the sieve holes and showering and make it to the main detector on the rings (r plot)
  TH1F *radial_hole_shower = new TH1F("radial_hole_shower","Charged Particles that Result from Primaries Hitting a Sieve Hole and then Showering Through Sieve (100mm) and Hit the Main Detector", 1000, 650, 1200);
  radial_hole_shower -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

//----------------------------------------------------------------------------

//---Define Logical Flags---

  //Test if a primary hit the upstream surface of the sieve hole detectors, i.e., if a primary entered one of the sieve holes.
  bool in_hole = false;

  //Test if a primary cleanly passed through one of the sieve holes.
  //in_hole_# && prim_out_hole_#
  bool clean_pass_prim = false;
  bool clean_pass_e = false;

  //Test if a primary entered a hole and then caused a shower.
  //in_hole_# && !prim_out_hole_#
  bool hole_shower = false;

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
      if((hit.trid == 1 || hit.trid == 2 || hit.pid == 11 || hit.pid == -11) && hit.r >= 35.306 && hit.r <= 97.9932 && hit.det == 1004 && hit.pz >= 0)
      {
        in_e = hit.e;
      }

      //Record the energy of charged particles and primaries that hit the downstream surface of the sieve.
      if((hit.trid == 1 || hit.trid == 2 || hit.pid == 11 || hit.pid == -11) && hit.r >= 35.306 && hit.r <= 97.9932 && hit.det == 1005 && hit.pz >= 0)
      {
        out_e = hit.e;
      }

      //Test if primaries cleanly passed through the holes. If the energy of the incoming particle is less than 0.1MeV different than the energy of the outgoing particle, then we can say that this is a clean pass because the energy of the particle doesn't change.
      if(in_hole && abs(in_e - out_e) < 0.1 && (hit.trid == 1 || hit.trid == 2))
      {
        clean_pass_prim = true;
      }

      //Test if a non-primary charged particle cleanly passed through the holes.
      if(in_hole && abs(in_e - out_e) < 0.1 && !clean_pass_prim)
      {
        clean_pass_e = true;
      }

      //Test if primaries entered a hole and then caused a shower.
      if(in_hole && !clean_pass_prim && (hit.pid == 11 || hit.pid == -11))
      {
        hole_shower = true;
      }

    }//end second loop over hits


    //Process hits again because we will now be filling histograms.
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //Look at primaries hitting main detector rings with positive z momentum.
      if((hit.pid == 11 || hit.pid == -11) && hit.pz >= 0 && hit.det == 28 && hit.r>=650 && hit.r<=1200)
      {

        if(hole_shower)
        {
          //fill histogram for charged particles from sieve hole showers that made it to the rings on the main detector.
          radial_hole_shower -> Fill(hit.r, rate);
        }

      }

    }//end third loop over hits

  }//end loop over events

//--------------------------------------------------------------------------------

//---Draw and Save Histograms---

  TCanvas *cleanpass = new TCanvas("cleanpass", "Primaries that Cleanly Pass Through", 100, 100, 500, 500);

  gStyle -> SetOptTitle(0);

  radial_hole_shower -> Draw();

  auto titleCleanPass = new TPaveLabel(0.0, 0.9, 1.0, 1.0, "Primaries that Hit the Main Detector Rings for a 100mm Full Tungsten Sieve", "brNDC");
  titleCleanPass -> Draw();

  gPad -> Update();

  TPaveStats *st2 = (TPaveStats*)radial_hole_shower -> GetListOfFunctions() -> FindObject("stats");
  st2 -> SetY1NDC(0.9);
  st2 -> SetY2NDC(0.7);

  cleanpass -> SaveAs("images/PTResults/Primary_Hole_Shower_Analysis_Sieve_100.png");

}//end DetailedSieve100HoleAnalysis()

