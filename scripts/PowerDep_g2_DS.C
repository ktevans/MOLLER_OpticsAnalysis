//  Need to use reroot (CERN's root compiled with special remoll libraries,
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/" defined for the images to go to
//
//  Run using:
//   build/reroot
//   .L scripts/EvenRatePrimBlocker.C
//   Analysis("g1")
//
//  Alternatively, you can type the following command directly in the terminal
//  while in your remoll directory:
//  echo 'gROOT->LoadMacro("scripts/EvenRatePrimBlocker.C"); Analysis("g1"); gSystem->Exit(0);' | build/reroot -b -l
//
//  Can put multiple root files in the script, and they will be chained together.
//
//  This script will plot all primaries made using the elastic C12 generator that
//  hit the blocker detector (1000) for a 90mm blocker with inner radius of 28.63mm.
//  Then, the script will calculate the event rate and print it onto the histogram.

#include <TF1.h>
void PowerDep()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");

  T->Add("rootfilesPT/blocker_beamC12_DS_g2_0.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_1.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_2.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_3.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_4.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_5.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_6.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_7.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_8.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_9.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_10.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_11.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_12.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_13.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_14.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_15.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_16.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_17.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_18.root");
  T->Add("rootfilesPT/blocker_beamC12_DS_g2_19.root");

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

  //Define variable for event rate and for the current (in A)
  double power = 0.0;

  double curr = 85e-6;
  double nelec_s = curr/1.6e-19;
  Double_t scale = nelec_s/T->GetEntries();

//----------------------------------------------------------------------------

  //Define Histograms that we will fill later

  TH1F *edep_blocker = new TH1F("edep_blocker","Sum of Energy Deposition on the Blocker for a 90mm Blocker with 30.54mm Inner Bore Radius and an Downstream C12 Target", 100, 0, 11000);
  edep_blocker -> GetXaxis() -> SetTitle("Energy Deposited on Detector [MeV]");

//----------------------------------------------------------------------------

  T -> Project("edep_blocker", "sum.edep", Form("%g*sum.edep*(sum.det==1000 && sum.edep>1e-20)", scale));

//--------------------------------------------------------------------------------
//Draw and save the histograms

  //Create a canvas on which to draw the histograms
  TCanvas *blocker = new TCanvas("blocker","Particles Hitting the Blocker Detector", 1000, 1000, 1000, 1000);

  edep_blocker -> Draw();

  //Integrate over this histogram to get the power in W
  power = edep_blocker -> Integral()*1.6e-13;
  //Print this value from the Integral and place it on the histogram
  printf("Power = %f W\n", power);
  TPaveLabel *Plab0 = new TPaveLabel(0.27, 0.76, 0.75, 0.87, Form("%5.8f W at %1.0f #muA", power, curr*1e6), "NDC");
  Plab0 -> Draw();

  //Save the canvas as an image in the director "remoll/images/"
  blocker -> SaveAs("images/PowerDep_Det1000_All_90mmblocker_DS_g2.png");

}//end PowerDep()

