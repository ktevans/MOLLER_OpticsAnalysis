// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries, 
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/HT/" defined for the images to go to 
//  
//  Run using (for example):
//   build/reroot
//   .L scripts/HoleTilt/HoleTiltMoller.C
//   HoleTilt()
//
//  Can put multiple root files in the script, and they will be chained together.
//
//  This script will take root files with sieve thickness 100mm and hole diameter 
//  0.5in. It will first loop through the Moller events and flag any in which a 
//  primary particle hits a sieve hole. Then it will take these flagged events and 
//  plot the polar angles for the primary electrons hitting the upstream surface 
//  of the sieve. This will tell us the polar angles of the primary electrons when 
//  they arrive at the sieve holes. The script will plot these angles unweighted and 
//  color-coded based on which hole the electrons hit. It will display a legend 
//  and 3 separate stat boxes.

#include <TF1.h>
void HoleTiltMoller()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  T->Add("sieveLH_moller_100k_100mm_05in_0.root");
//  T->Add("sieveLH_moller_100k_100mm_05in_1.root");
  T->Add("sieveLH_moller_100k_100mm_05in_2.root");
  T->Add("sieveLH_moller_100k_100mm_05in_3.root");
//  T->Add("rootfilesHT/sieveLH_moller_100k_100mm_05in_4.root");
  T->Add("sieveLH_moller_100k_100mm_05in_5.root");
  T->Add("sieveLH_moller_100k_100mm_05in_6.root");
  T->Add("sieveLH_moller_100k_100mm_05in_7.root");
//  T->Add("rootfilesHT/sieveLH_moller_100k_100mm_05in_8.root");
//  T->Add("rootfilesHT/sieveLH_moller_100k_100mm_05in_9.root");


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

  //1D histogram for the polar angles of the primary electrons hitting hole 1 on the upstream surface of the sieve
  TH1F *theta_hole_1 = new TH1F("theta_hole_1","Polar Angle of Electrons That Hit Hole 1", 200, -5, 5);
  theta_hole_1 -> GetXaxis() -> SetTitle("Theta of Incoming Electron [rad]");
  theta_hole_1 -> SetLineColor(kBlue); //the line of the histogram for hole 1 will be blue

  //1D histogram for the polar angles of the primary electrons hitting hole 2 on the upstream surface of the sieve
  TH1F *theta_hole_2 = new TH1F("theta_hole_2","Polar Angle of Electrons That Hit Hole 2", 200, -5, 5);
  theta_hole_2 -> GetXaxis() -> SetTitle("Theta of Incoming Electron [rad]");
  theta_hole_2 -> SetLineColor(kRed); //the line of the histogram for hole 2 will be red

  //1D histogram for the polar angles of the primary electrons hitting hole 3 on the upstream surface of the sieve
  TH1F *theta_hole_3 = new TH1F("theta_hole_3","Polar Angle of Electrons That Hit Hole 3", 200, -5, 5);
  theta_hole_3 -> GetXaxis() -> SetTitle("Theta of Incoming Electron [rad]");
  theta_hole_3 -> SetLineColor(kGreen); //the line of the histogram for hole 2 will be green

 //These are dummy histograms that I will use to help make the Legends later. They are filled with the colors that I want to grab. I just fill them randomly so that I can get the colors; I never draw the histograms.

 auto h1color = new TH1F("h1color","TLegend help",1,-1,1);
 h1color->FillRandom("gaus",3);
 h1color->SetFillColor(kBlue);

 auto h2color = new TH1F("h2color","TLegend help",1,-1,1);
 h2color->FillRandom("gaus",3);
 h2color->SetFillColor(kRed);

 auto h3color = new TH1F("h3color","TLegend help",1,-1,1);
 h3color->FillRandom("gaus",3);
 h3color->SetFillColor(kGreen);


  //Define logical flag for each hole
  bool hole_1 = false;
  bool hole_2 = false;
  bool hole_3 = false;

  //Define variables for electron momentum and polar angle
  Float_t px, py, pz, pt, th = 0;

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);

    hole_1 = false;
    hole_2 = false;
    hole_3 = false;

    //Process hits, i.e., loop over all the hits in this event
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      //hole_# is true if the primary electron goes through the hole

      if (hit.det == 1001 && (hit.trid == 1 || hit.trid == 2))
      {
        hole_1 = true;
      }//end hole 1 if

      if (hit.det == 1002 && (hit.trid == 1 || hit.trid == 2))
      {
        hole_2 = true;
      }//end hole 2 if

      if (hit.det == 1003 && (hit.trid == 1 || hit.trid == 2))
      {
        hole_3 = true;
      }//end hole 3 if

    }//end process over hits

    //Process over hits again
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      //only look at primary electrons that hit the upstream surface of the sieve
      if (hit.det==1004 && (hit.trid==1 || hit.trid==2) && hit.r >=35.306 && hit.r<97.9932)
      {

          //Calculate hit.th using the momentum of the hit
          px = hit.px;
          py = hit.py;
          pz = hit.pz;
          pt = TMath::Sqrt(px*px + py*py); //transverse momentum in the xy plane
          th = TMath::ATan(pt/pz); //theta = arctan(pt/pz)

          //fill each histogram based on which hole the primary electron hit and require that the electrons are traveling with positive z momentum
          if (hole_1 && hit.pz>=0)
          {
            theta_hole_1 -> Fill(th); //not weighted
          }//end hole 1 if

          if (hole_2 && hit.pz>=0)
          {
            theta_hole_2 -> Fill(th);
          }//end hole 2 if

          if (hole_3 && hit.pz>=0)
          {
            theta_hole_3 -> Fill(th);
          }//end hole 3 if

      }//end trid and radius if

    }//end process over hits

  }//end process over events

//--------------------------------------------------------------------------------
  //Draw and save the histograms

  TCanvas *canvas = new TCanvas("canvas","electron polar angles hitting the sieve holes", 500, 500, 700, 700);

  //Get rid of automatic title
  gStyle->SetOptTitle(0);
  
  //Draw each histogram onto the canvas. "SAMES" keeps the histograms already drawn on the canvas.
  theta_hole_1 -> Draw();

  theta_hole_2 -> Draw("SAMES");

  theta_hole_3 -> Draw("SAMES");

  //Make text for new title. Coordinates are NDC (x_min, y_min, x_max, y_max).
  auto titl = new TPaveLabel(0.1,0.92,0.8,1.0,"Primary Electron Polar Angles at Upstream Surface of Sieve","brNDC");

  titl->Draw();

  //We have to update the canvas so that when we call the stat boxes, they actually exist.
  gPad->Update();

  //Create and position stat boxes for each histogram. This will make sure the stat boxes aren't stacked on top of each other.
  TPaveStats *s1 = (TPaveStats*)theta_hole_1->GetListOfFunctions()->FindObject("stats");
  s1->SetY1NDC(0.9); //starting y position
  s1->SetY2NDC(0.7); //ending y position

  TPaveStats *s2 = (TPaveStats*)theta_hole_2->GetListOfFunctions()->FindObject("stats");
  s2->SetY1NDC(0.7);
  s2->SetY2NDC(0.5);

  TPaveStats *s3 = (TPaveStats*)theta_hole_3->GetListOfFunctions()->FindObject("stats");
  s3->SetY1NDC(0.5); //starting y position
  s3->SetY2NDC(0.3); //ending y position

  //Create and position legend. Coordinates are NDC (x_min, y_min, x_max, y_max).
  auto legend1 = new TLegend(0.1,0.1,0.25,0.25);

  //Add the entries for each hole color. "f" means that we use the fill color from h#color. We could use "l" for the line in theta_hole_#, and that would show a colored line in the legend rather than a filled box. Both are valid options.
  legend1->AddEntry(h1color,"Hole 1","f");
  legend1->AddEntry(h2color,"Hole 2","f");
  legend1->AddEntry(h3color,"Hole 3","f");
  legend1->Draw();

  //Save the canvas as a PNG in the directory "images/HT".
  canvas -> SaveAs("images/HT/Hole_Tilt_Angles_Moller.png");

}//end HoleTilt()

