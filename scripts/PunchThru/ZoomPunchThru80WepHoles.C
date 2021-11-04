// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries, 
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/PT" defined for the images to go to 
//  
//  Run using (for example):
//   build/reroot
//   .L scripts/PunchThru80Wep.C
//   PunchThru()
//
//  Can put multiple root files in the script, and they will be chained together.
//
//  This script will take root files of a certain sieve thickness. It will first loop
//  through the events and flag any in which a primary particle hits a sieve hole.
//  Then it will exclude these flagged events and plot electrons and positrons that hit
//  upstream and downstream of the surface of the sieve. Those particles that hit 
//  downstream of the surface are flagged as "punch through particles" and their energies
//  are plotted. The energies are split above and below 500 MeV because we expect the
//  magnet to bend anything below 500 MeV away from the main detector rings. We can look
//  at how many punch through particles are above 500 MeV and compare that number to how
//  many particles hit the main rings. Finally, punch through particles are plotted on
//  the rings of the main detector. An xy plot and radial plot are included.
//
//  Addition: I now also plot electrons and positrons that hit the main detector after 
//  passing through the sieve holes. This is so that I can look at the amount of noise our 
//  signal is likely to see.

#include <TF1.h>
void ZoomPunchThru80WepHoles()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  
  //Add files from the directory "rootfilesPT/", "80" is the sieve thickness in mm
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm0.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm1.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm2.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm3.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm4.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm5.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm6.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm7.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm8.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_80mm9.root");

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
  
  //---Main detector histograms---

  //2D histogram for e+ and e- that punch through the sieve and make it to the main detector on the rings (xy plot)
  TH2F *punch_thru_main = new TH2F("punch_thru_main","Electrons and Positrons that Punched Through the Sieve (80mm) and Hit the Main Detector for ep Scattering with Thin Carbon Target", 1000, -1200, 1200, 1000, -1200, 1200);
  punch_thru_main -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  punch_thru_main -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  //1D histogram for e+ and e- that punch through the sieve and make it to the main detector on the rings (r plot)
  TH1F *radial_main = new TH1F("radial_main","Electrons and Positrons that Punch Through the Sieve (80mm) and Hit the Main Detector", 1000, 680, 750);
  radial_main -> GetXaxis() -> SetTitle("r Position of Hits [mm]");


  //2D histogram for electrons that make it to the main detector on the rings (xy plot)
  TH2F *main_holes = new TH2F("main_holes","Electrons and Positrons that Pass Through the Sieve Holes (80mm) and Hit the Main Detector for ep Scattering with Thin Carbon Target", 1000, -1200, 1200, 1000, -1200, 1200);
  main_holes -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  main_holes -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  //1D histogram for electrons that make it to the main detector on the rings (r plot)
  TH1F *radial_main_holes = new TH1F("radial_main_holes","Particles that Pass Through the Sieve Holes (80mm) and Hit the Main Detector", 1000, 680, 750);
  radial_main_holes -> GetXaxis() -> SetTitle("r Position of Hits [mm]");


//----------------------------------------------------------------------------

  //Define logical flag for each hole
  bool no_hole_1 = false;
  bool no_hole_2 = false;
  bool no_hole_3 = false;


  //Define logical flag for punch-through
  bool punch_thru = false;

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);

    no_hole_1 = true;
    no_hole_2 = true;
    no_hole_3 = true;
    punch_thru = false;

    //Process hits, i.e., loop over all the hits in this event
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      //no_hole_# is false if the electron goes through the hole
      if (hit.det == 1001 && (hit.trid == 1 || hit.trid == 2))
      {
        no_hole_1 = false;
      }

      if (hit.det == 1002 && (hit.trid == 1 || hit.trid == 2))
      {
        no_hole_2 = false;
      }

      if (hit.det == 1003 && (hit.trid == 1 || hit.trid == 2))
      {
        no_hole_3 = false;
      }
    }//end process over hits

    //Process over hits again
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      if ((hit.pid==11 || hit.pid==-11) && no_hole_1 && no_hole_2 && no_hole_3 && hit.r >=35.306 && hit.r<97.9932)
      {
      
          if (hit.det == 1005 && hit.pz >= 0)
          {
            punch_thru = true; //flag particles as "punch through particles"
          }//end downstream if

      }//end pid and hole if

    }//end process over hits

    //process over hits again to look at the main detector
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

        //Only look at "punch through particles" that hit the main detector on rings 1-7 and make sure they are e- or e+ with positive z momentum.
        if (punch_thru && hit.det==28 && hit.r>=680 && hit.r<=750 && (hit.pid==11 || hit.pid==-11) && hit.pz>=0)
        {
          punch_thru_main -> Fill(hit.x, hit.y, rate);
          radial_main -> Fill(hit.r, rate);
	}//end main det if

    }//end process over hits
  }//end process over events

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);

    //process over hits to look at the main detector
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

        //Only look at sieve hole particles that hit the main detector on rings 1-7 and make sure they are e- or e+ with positive z momentum.
       if (hit.det==28 && hit.r>=680 && hit.r<=750 && (hit.pid==11 || hit.pid==-11) && hit.pz>=0)
        {
          main_holes -> Fill(hit.x, hit.y, rate);
          radial_main_holes -> Fill(hit.r, rate);
        }//end hole and radius if

    }//end process over hits

  }//end process over events


//--------------------------------------------------------------------------------
//Draw and save the histograms

  //---Main Detector Electrons and Positrons---

  //Create a canvas on which to draw the histograms
  TCanvas *main = new TCanvas("main","Electrons and Positrons Hitting the Main Detector", 1000, 1000, 1000, 1000);

  //Divide the canvas into 1 column, 2 rows
  main -> Divide(1,2);

  //Look at the first entry on the canvas and draw the xy main detector
  main -> cd(1);
  punch_thru_main -> Draw();

  //Look at the second entry on the canvas and draw the r main detector
  main -> cd(2);
  radial_main -> Draw();

  //Save the canvas as an image in the director "remoll/images/PT/"
  main -> SaveAs("images/PT/Zoom_Punch_Thru_Main_WSieve_80.png");


  //---Main Detector Holes---

  //Create a canvas on which to draw the histograms
  TCanvas *main_all = new TCanvas("main_all","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

  //Divide the canvas into 1 column, 2 rows
  main_all -> Divide(1,2);

  //Look at the first entry on the canvas and draw the xy main detector
  main_all -> cd(1);
  main_holes -> Draw();

  //Look at the second entry on the canvas and draw the r main detector
  main_all -> cd(2);
  radial_main_holes -> Draw();

  //Save the canvas as an image in the director "remoll/images/PT/"
  main_all -> SaveAs("images/PT/Zoom_Punch_Thru_Main_All_WSieve_80.png");

}//end PunchThru()

