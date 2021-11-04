// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries,
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/PTResults" defined for the images to go to
//
//  Run using (for example):
//   build/reroot
//   .L scripts/DetailedSieve120HoleAnalysis1.C
//   DetailedSieve120HoleAnalysis()
//  Or use:
//   build/reroot -l -q -b 'DetailedSieve120HoleAnalysis1.C()'
//
//  Can put multiple root files in the script, and they will be chained together.


#include <TF1.h>

//120 is the sieve thickness in mm
void DetailedSieve120HoleAnalysis()
{

//---Set up Chain and Tree---

  //Allow Tree to use the root files that you call. This line creates a chain of root files that you can add onto.
  TChain* T = new TChain("T");

  //Add files from the directory "rootfilesPT/", "120" is the sieve thickness in mm
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm0.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm1.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm2.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm3.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm4.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm5.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm6.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm7.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm8.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm9.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm10.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm11.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm12.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm13.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm14.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm15.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm16.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm17.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm18.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm19.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm20.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm21.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm22.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm23.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm24.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm25.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm26.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm27.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm28.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_120mm29.root");

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
  TH1F *radial_clean_pass = new TH1F("radial_clean_pass","Charged Particles that Pass Through Any of the Sieve (120mm) Holes and Hit the Main Detector", 1000, 650, 1200);
  radial_clean_pass -> GetXaxis() -> SetTitle("r Position of Hits [mm]");
  radial_clean_pass -> SetMarkerColor(kBlue);

  //---Sieve Hole Showers---

  //1D histogram for charged particles that result from primaries entering the sieve holes and showering and make it to the main detector on the rings (r plot)
  TH1F *radial_hole_shower = new TH1F("radial_hole_shower","Charged Particles that Result from Primaries Hitting a Sieve Hole and then Showering Through Sieve (120mm) and Hit the Main Detector", 1000, 650, 1200);
  radial_hole_shower -> GetXaxis() -> SetTitle("r Position of Hits [mm]");
  radial_hole_shower -> SetMarkerColor(kRed);

  //---Sieve Surface Showers---

  //1D histogram for charged particles that result from primaries hitting the sieve surface and showering into one of the sieve holes and then make it to the main detector on the rings (r plot)
  TH1F *radial_hit_shower = new TH1F("radial_hit_shower","Charged Particles that Result from Primaries Hitting the Sieve Surface and then Showering into a Sieve (120mm) Hole and Hit the Main Detector", 1000, 650, 1200);
  radial_hit_shower -> GetXaxis() -> SetTitle("r Position of Hits [mm]");
  radial_hit_shower -> SetMarkerColor(kGreen);

  //---Color Histograms---

  //These are dummy histograms that I will use to help make the Legends later. They are filled with the colors that I want to grab. The histograms of interest (created above) are all points. When points are shown in a legend, they're hard to see, so I'm using a fill color in order to put a box of color in the legend. If your plots are filled or are lines, this step is unnecessary.

  auto h1color = new TH1F("h1color","TLegend help",1,-1,1);
  h1color->FillRandom("gaus",3); //This fills the histogram with a random function. I've chosen to fill it with a Gaussian ("gaus"), and it will fill 3 times. These choices are arbitrary as I'm only using the histogram to grab the fill color from it.
  h1color->SetFillColor(kBlue); //This will color in the histogram blue.

  auto h2color = new TH1F("h2color","TLegend help",1,-1,1);
  h2color->FillRandom("gaus",3);
  h2color->SetFillColor(kRed);

  auto h3color = new TH1F("h3color","TLegend help",1,-1,1);
  h3color->FillRandom("gaus",3);
  h3color->SetFillColor(kGreen);

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
      if((hit.trid == 1 || hit.trid == 2 || hit.pid == 11 || hit.pid == -11) && (hit.det == 1001 || hit.det == 1002 || hit.det == 1003) && abs(hit.z - 565) < 0.1 && hit.pz >= 0)
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

      //Test if primaries hits the sieve surface and then caused a shower to exit out of the hole.
      if(!in_hole && !clean_pass_prim && !clean_pass_e && (hit.pid == 11 || hit.pid == -11))
      {
        hit_shower = true;
      }

    }//end second loop over hits


    //Process hits again because we will now be filling histograms.
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //Look at primaries hitting main detector rings with positive z momentum.
      if((hit.trid == 1 || hit.trid == 2 || hit.pid == 11 || hit.pid == -11) && hit.pz >= 0 && hit.det == 28 && hit.r>=650 && hit.r<=1200)
      {

        if(clean_pass_prim || clean_pass_e)
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

  TCanvas *cleanpass = new TCanvas("cleanpass", "Primaries that Cleanly Pass Through", 100, 100, 500, 500);

  gStyle -> SetOptTitle(0);

  radial_clean_pass -> Draw();
  radial_hole_shower -> Draw("SAMES");
  radial_hit_shower -> Draw("SAMES");

  auto titleCleanPass = new TPaveLabel(0.0, 0.9, 1.0, 1.0, "Primaries that Hit the Main Detector Rings for a 120mm Full Tungsten Sieve", "brNDC");
  titleCleanPass -> Draw();

  gPad -> Update();

  TPaveStats *st1 = (TPaveStats*)radial_clean_pass -> GetListOfFunctions() -> FindObject("stats");
  st1 -> SetY1NDC(0.9);
  st1 -> SetY2NDC(0.75);

  TPaveStats *st2 = (TPaveStats*)radial_hole_shower -> GetListOfFunctions() -> FindObject("stats");
  st2 -> SetY1NDC(0.75);
  st2 -> SetY2NDC(0.5);

  TPaveStats *st3 = (TPaveStats*)radial_hit_shower -> GetListOfFunctions() -> FindObject("stats");
  st3 -> SetY1NDC(0.5);
  st3 -> SetY2NDC(0.25);

  auto legend = new TLegend (0.0, 0.7, 0.25, 0.9);
  legend -> AddEntry(h1color, "Clean Pass Primaries", "f");
  legend -> AddEntry(h2color, "Hole Shower Primaries", "f");
  legend -> AddEntry(h3color, "Hit Shower Primaries", "f");
  legend -> Draw();

  cleanpass -> SaveAs("images/PTResults/CP_Hole_Analysis_Sieve_120.png");

  TCanvas *separate = new TCanvas("separate", "All Charged Particles", 100, 100, 1500, 500);

  separate -> Divide(3,1);

  separate -> cd(1);
  radial_clean_pass -> Draw();

  separate -> cd(2);
  radial_hole_shower -> Draw();

  separate -> cd(3);
  radial_hit_shower -> Draw();

  separate -> SaveAs("images/PTResults/CP_Hole_Analysis_Sieve_120_Separate.png");

}//end DetailedSieve120HoleAnalysis()

