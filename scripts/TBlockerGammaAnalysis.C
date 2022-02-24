// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries,
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/Blocker" defined for the images to go to
//
//  Run using (using a thickness of 100mm for example):
//   build/reroot
//   .L scripts/BlockerPunchThru.C
//   main("100")
//
//  Alternatively, you can type the following command directly in the terminal
//  while in your remoll directory:
//  echo 'gROOT->LoadMacro("scripts/BlockerPunchThru.C"); Blocker("100"); gSystem->Exit(0);' | build/reroot -b -l
//
//  Can put multiple root files in the script, and they will be chained together.
//
//  This script will take root files of a certain tapered Blocker thickness.
//  All Gammas that reach the main detector rings are plotted (xy and
//  r). The z vertex and energies for these particles are also plotted.

#include <TF1.h>
void Blocker(const TString& Thickness)
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");

  //Add files from the directory "rootfilesPT/", "Thickness" is the Blocker thickness in mm. Replace these root files with whatever root files you would like to analyze.
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm0.root");
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm1.root");
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm2.root");
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm3.root");
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm4.root");
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm5.root");
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm6.root");
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm7.root");
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm8.root");
  T->Add("rootfilesPT/blocker/TWBlockerC12_ep_100k_"+Thickness+"mm9.root");

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

  //---All Charged Particles---

  //1D histogram for e+ and e- that make it to the main detector on the rings
  TH1F *radial_main_all = new TH1F("radial_main_all","Energies of All Gammas that Hit the Main Detector for a"+Thickness+" mm Tapered Blocker", 100, 0, 10000);
  radial_main_all -> GetXaxis() -> SetTitle("Energies of Hits [MeV]");

  //2D histogram for particles that make it to the main detector on the rings (xy plot)
  TH2F *xy_main_all = new TH2F("xy_main_all","All Gammas that Hit the Main Detector for a "+Thickness+" mm Tapered Blocker", 100, -1200, 1200, 100, -1200, 1200);
  xy_main_all -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  xy_main_all -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  //1D histogram for z vertices of particles that make it to the main detector on the rings (z plot)
  TH1F *vertex_main = new TH1F("vertex_main","Z Vertex of All Charged Particles that Hit the Main Detector for a "+Thickness+" mm Tapered Blocker", 100, -4500, 22000);
  vertex_main -> GetXaxis() -> SetTitle("z Position of the Vertex of Hits [mm]");

  //1D histogram for particles that make it to the main detector on the ring 2 (radius plot)
  TH1F *ring2_all = new TH1F("ring2_all","All Gammas that Hit Ring 2 on the Main Detector for a "+Thickness+" mm Tapered Blocker", 1000, 710, 760);
  ring2_all -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);

    //process over hits again to look at the main detector
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

        //Only look at charged particles that hit the main detector on rings 1-7.
        if (hit.det==28 && hit.r>=650 && hit.r<=1200 && hit.pz>=0 && hit.pid==22)
        {
          xy_main_all -> Fill(hit.x, hit.y, rate);
          radial_main_all -> Fill(hit.e, rate);
          vertex_main -> Fill(hit.vz, rate);

          if (hit.r<=760 && hit.r>=710)
          {
            ring2_all -> Fill(hit.r, rate);
          }

      	}//end main det if

    }//end process over hits
  }//end process over events

//--------------------------------------------------------------------------------
//Draw and save the histograms

  //---Main Detector All Rings in Color---

  //Create a canvas on which to draw the histograms
  TCanvas *main_all_color = new TCanvas("main_all_color","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

  //Divide the canvas into 1 column, 2 rows
  main_all_color -> Divide(1,2);

  //Look at the first entry on the canvas and draw the xy main detector
  main_all_color -> cd(1);
  xy_main_all -> Draw("colz");

  //Look at the second entry on the canvas and draw the r main detector
  main_all_color -> cd(2);
  radial_main_all -> Draw("B");

  //Save the canvas as an image in the director "remoll/images/Blocker/"
  main_all_color -> SaveAs("images/Blocker/InnerHoleTaper/Gamma_Main_All_Color_TWBlocker_"+Thickness+".png");

  //---Main Detector All Rings---

  //Create a canvas on which to draw the histograms
  TCanvas *main_all = new TCanvas("main_all","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

  //Divide the canvas into 1 column, 2 rows
  main_all -> Divide(1,2);

  //Look at the first entry on the canvas and draw the xy main detector
  main_all-> cd(1);
  xy_main_all -> Draw();

  //Look at the second entry on the canvas and draw the r main detector
  main_all -> cd(2);
  radial_main_all -> Draw();

  //Save the canvas as an image in the director "remoll/images/Blocker/"
  main_all -> SaveAs("images/Blocker/InnerHoleTaper/Gamma_Main_All_TWBlocker_"+Thickness+".png");

  //---Main Detector Vertex and Ring 2---

  //Create a canvas on which to draw the histograms
  TCanvas *main_all_vr = new TCanvas("main_all_vr","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

  //Divide the canvas into 1 column, 2 rows
  main_all_vr -> Divide(1,2);

  //Look at the first entry on the canvas and draw the xy main detector
  main_all_vr -> cd(1);
  vertex_main -> Draw("B");

  //Look at the second entry on the canvas and draw the r main detector
  main_all_vr -> cd(2);
  ring2_all -> Draw("B");

  //Save the canvas as an image in the director "remoll/images/Blocker/"
  main_all_vr -> SaveAs("images/Blocker/InnerHoleTaper/Gamma_Main_All_VR_TWBlocker_"+Thickness+".png");

}//end Blocker()

