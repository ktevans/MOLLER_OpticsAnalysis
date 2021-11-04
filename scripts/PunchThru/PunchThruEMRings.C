// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries, 
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/PT" defined for the images to go to 
//  
//  Run using (for example):
//   build/reroot
//   .L scripts/PunchThru##Wep.C
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

#include <TF1.h>
void PunchThru()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  
  //Add files from the directory "rootfilesPT/", "##" is the sieve thickness in mm
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

  //2D histogram for e+ and e- that punch through the sieve and make it to the main detector on the rings (xy plot)
  TH2F *punch_thru_main_e1 = new TH2F("punch_thru_main_e1","Electrons and Positrons that Punched Through the Sieve (##mm) and Hit the Main Detector for ep Scattering with Thin Carbon Target", 1000, -1200, 1200, 1000, -1200, 1200);
  punch_thru_main_e1 -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  punch_thru_main_e1 -> GetYaxis() -> SetTitle("y Position of Hits [mm]");
  punch_thru_main_e1 -> SetMarkerColor(kBlue);

  TH2F *punch_thru_main_e2 = new TH2F("punch_thru_main_e2","Electrons and Positrons that Punched Through the Sieve (##mm) and Hit the Main Detector for ep Scattering with Thin Carbon Target", 1000, -1200, 1200, 1000, -1200, 1200);
  punch_thru_main_e2 -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  punch_thru_main_e2 -> GetYaxis() -> SetTitle("y Position of Hits [mm]");
  punch_thru_main_e2 -> SetMarkerColor(kRed);

  TH2F *punch_thru_main_e3 = new TH2F("punch_thru_main_e3","Electrons and Positrons that Punched Through the Sieve (##mm) and Hit the Main Detector for ep Scattering with Thin Carbon Target", 1000, -1200, 1200, 1000, -1200, 1200);
  punch_thru_main_e3 -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  punch_thru_main_e3 -> GetYaxis() -> SetTitle("y Position of Hits [mm]");
  punch_thru_main_e3 -> SetMarkerColor(kGreen);

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


  //Define logical flag for each hole
  bool no_hole_1 = false;
  bool no_hole_2 = false;
  bool no_hole_3 = false;

  //Define logical flag for punch-through
  bool punch_thru = false;

  bool e1 = false;
  bool e2 = false;
  bool e3 = false;

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);

    no_hole_1 = true;
    no_hole_2 = true;
    no_hole_3 = true;

    punch_thru = false;

    e1 = false;
    e2 = false;
    e3 = false;

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

            if (hit.e<=20)
            {
              e1 = true;        
            }

            if (hit.e>20 && hit.e<=100)
            {
              e2 = true;        
            }

            if (hit.e>=100)
            {
              e3 = true;
            }//end energy ifs

          }//end downstream if

      }//end pid and hole if

    }//end process over hits

    //process over hits again to look at the main detector
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

        //Only look at "punch through particles" that hit the main detector on rings 1-7
        if (punch_thru && hit.det==28 && hit.r>=650 && hit.r<=1200)
        {
          if (e1)
          {
            punch_thru_main_e1 -> Fill(hit.x, hit.y, rate);
          }

          if (e2)
          {
            punch_thru_main_e2 -> Fill(hit.x, hit.y, rate);
          }

          if (e3)
          {
            punch_thru_main_e3 -> Fill(hit.x, hit.y, rate);
          }

	}//end main det if

    }//end process over hits
  }//end process over events

//--------------------------------------------------------------------------------
  //Draw and save the histograms

  TCanvas *c2 = new TCanvas("c2","Primary Electrons at Main Detector Separated by hole", 100, 100, 500, 500);

  gStyle -> SetOptTitle(0);

  punch_thru_main_e1 -> Draw();
  punch_thru_main_e2 -> Draw("SAMES");
  punch_thru_main_e3 -> Draw("SAMES");

  auto titl2 = new TPaveLabel(0.1, 0.92, 0.9, 1.0, "Punch Through Electron Energies at Main Detector Separated by Energy at Sieve Surface", "brNDC");
  titl2 -> Draw();

  gPad -> Update();

  TPaveStats *st1 = (TPaveStats*)punch_thru_main_e1 -> GetListOfFunctions() -> FindObject("stats");
  st1 -> SetY1NDC(0.9);
  st1 -> SetY2NDC(0.65);

  TPaveStats *st2 = (TPaveStats*)punch_thru_main_e2 -> GetListOfFunctions() -> FindObject("stats");
  st2 -> SetY1NDC(0.65);
  st2 -> SetY2NDC(0.4);

  TPaveStats *st3 = (TPaveStats*)punch_thru_main_e3 -> GetListOfFunctions() -> FindObject("stats");
  st3 -> SetY1NDC(0.4);
  st3 -> SetY2NDC(0.15);

  auto legend = new TLegend ();
  legend -> AddEntry(h1color, "0 - 20 MeV", "f");
  legend -> AddEntry(h2color, "20 - 100 MeV", "f");
  legend -> AddEntry(h3color, "100+ MeV", "f");
  legend -> Draw();

  c2->SaveAs("images/PT/100BWSieveElectronEnergiesRings.png");

}//end PunchThru()

