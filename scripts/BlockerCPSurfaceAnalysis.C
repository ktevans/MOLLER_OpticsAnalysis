

#include <TF1.h>
void Blocker(const TString& Thickness, const double t)
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");

  //Add files from the directory "rootfilesPT/", "Thickness" is the Blocker thickness in mm. Replace these root files with whatever root files you would like to analyze.
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm0.root");
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm1.root");
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm2.root");
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm3.root");
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm4.root");
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm5.root");
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm6.root");
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm7.root");
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm8.root");
  T->Add("rootfilesPT/blocker/WBlockerC12_ep_100k_"+Thickness+"mm9.root");

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

 Float_t r = 29.195+(0.0045*(t));

  //----------------------------------------------------------------------------

    //Define Histograms that we will fill later

    //2D histogram for particles that hit the upstream surface of the blocker (xy plot)
    TH2F *US_surface = new TH2F("US_surface","All Charged Particles that Hit the Upstream Surface of a "+Thickness+" mm Blocker", 100, -120, 120, 100, -120, 120);
    US_surface -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
    US_surface -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

    //2D histogram for particles that hit the downstream surface of the blocker (xy plot)
    TH2F *DS_surface = new TH2F("DS_surface","All Charged Particles that Hit the Upstream Surface of a "+Thickness+" mm Blocker", 100, -120, 120, 100, -120, 120);
    DS_surface -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
    DS_surface -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

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
          if (hit.pz>=0 && (hit.pid==11 || hit.pid==-11) && hit.r<97.9932 && hit.r>=r)
          {
            if (hit.det==1004)
            {
              US_surface -> Fill(hit.x, hit.y, rate);
            }

            if (hit.det==1005)
            {
              DS_surface -> Fill(hit.x, hit.y, rate);
            }

        	}//end main det if

      }//end process over hits
    }//end process over events

//Create a canvas on which to draw the histograms
TCanvas *virt = new TCanvas("virt","Charged Particles Hitting the Virtual Detectors Upstream and Downstream of the Blocker", 1000, 1000, 1000, 1000);

//Divide the canvas into 1 column, 2 rows
virt -> Divide(1,2);

//Look at the first entry on the canvas and draw the upstream detector
virt -> cd(1);
US_surface -> Draw("colz");

//Look at the second entry on the canvas and draw the downstream detector
virt -> cd(2);
DS_surface -> Draw("colz");

//Save the canvas as an image in the director "remoll/images/Blocker/"
virt -> SaveAs("images/Blocker/InnerHoleTaper/CP_US_DS_WBlocker_"+Thickness+".png");

}//end Blocker()

