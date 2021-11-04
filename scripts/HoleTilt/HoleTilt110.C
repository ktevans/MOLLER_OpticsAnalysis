#include <TF1.h>
void HoleTilt()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm0.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm1.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm2.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm3.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm4.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm5.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm6.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm7.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm8.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_110mm9.root");


  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

  TH1F *theta_hole_1 = new TH1F("theta_hole_1","Polar Angle of Electrons That Hit Hole 1", 200, 0, 0.03);
  theta_hole_1 -> GetXaxis() -> SetTitle("Theta of Incoming Electron [rad]");
  theta_hole_1 -> SetLineColor(kBlue);

  TH1F *theta_hole_2 = new TH1F("theta_hole_2","Polar Angle of Electrons That Hit Hole 2", 200, 0, 0.03);
  theta_hole_2 -> GetXaxis() -> SetTitle("Theta of Incoming Electron [rad]");
  theta_hole_2 -> SetLineColor(kRed);

  TH1F *theta_hole_3 = new TH1F("theta_hole_3","Polar Angle of Electrons That Hit Hole 3", 200, 0, 0.03);
  theta_hole_3 -> GetXaxis() -> SetTitle("Theta of Incoming Electron [rad]");
  theta_hole_3 -> SetLineColor(kGreen);

 //These are dummy histograms that I will use to help make the Legends later. They are filled with the colors that I want to grab.

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
      }

      if (hit.det == 1002 && (hit.trid == 1 || hit.trid == 2))
      {
        hole_2 = true;
      }

      if (hit.det == 1003 && (hit.trid == 1 || hit.trid == 2))
      {
        hole_3 = true;
      }

    }//end process over hits

    //Process over hits again
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      //only look at primary electrons that hit the upstream surface of the sieve
      if (hit.det==1004 && (hit.trid==1 || hit.trid==2) && hit.r >=35.306 && hit.r<97.9932)
      {

          px = hit.px;
          py = hit.py;
          pz = hit.pz;
          pt = TMath::Sqrt(px*px + py*py); //transverse momentum in the xy plane
          th = TMath::ATan(pt/pz); //theta = arctan(pt/pz)

          if (hole_1 && hit.pz>=0)
          {
            theta_hole_1 -> Fill(th);
          }

          if (hole_2 && hit.pz>=0)
          {
            theta_hole_2 -> Fill(th);
          }

          if (hole_3 && hit.pz>=0)
          {
            theta_hole_3 -> Fill(th);
          }

      }//end trid and radius if

    }//end process over hits

  }//end process over events

//--------------------------------------------------------------------------------
  //Draw and save the histograms

  TCanvas *canvas = new TCanvas("canvas","electron polar angles hitting the sieve holes", 500, 500, 700, 700);

  //Get rid of automatic title:

  gStyle->SetOptTitle(0);
  
  theta_hole_1 -> Draw();

  theta_hole_2 -> Draw("SAMES");

  theta_hole_3 -> Draw("SAMES");

  //Make test for new title. Coordinates are NDC (x_min, y_min, x_max, y_max).

  auto titl = new TPaveLabel(0.1,0.92,0.8,1.0,"Primary Electron Polar Angles at Upstream Surface of Sieve","brNDC");
  titl->Draw();

  gPad->Update();

  TPaveStats *s1 = (TPaveStats*)theta_hole_1->GetListOfFunctions()->FindObject("stats");
  s1->SetY1NDC(0.9); //starting y position
  s1->SetY2NDC(0.7); //ending y position

  TPaveStats *s2 = (TPaveStats*)theta_hole_2->GetListOfFunctions()->FindObject("stats");
  s2->SetY1NDC(0.7);
  s2->SetY2NDC(0.5);

  TPaveStats *s3 = (TPaveStats*)theta_hole_3->GetListOfFunctions()->FindObject("stats");
  s3->SetY1NDC(0.5); //starting y position
  s3->SetY2NDC(0.3); //ending y position

  auto legend1 = new TLegend(0.1, 0.1, 0.25, 0.25);

  legend1->AddEntry(h1color,"Hole 1","f");
  legend1->AddEntry(h2color,"Hole 2","f");
  legend1->AddEntry(h3color,"Hole 3","f");
  legend1->Draw();


  canvas -> SaveAs("images/HT/Hole_Tilt_110mm.png");


}

