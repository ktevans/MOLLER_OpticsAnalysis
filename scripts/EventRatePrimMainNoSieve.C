
#include <TF1.h>
void Analysis()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");

  T->Add("rootfilesPT/David3/elasticC12_nosieve_0.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_1.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_2.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_3.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_4.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_5.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_6.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_7.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_8.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_9.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_10.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_11.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_12.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_13.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_14.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_15.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_16.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_17.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_18.root");
  T->Add("rootfilesPT/David3/elasticC12_nosieve_19.root");

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

  //Define variable for event rate and for the current
  double evrate = 0.0;

  double curr = 85e-6;

//----------------------------------------------------------------------------

  //Define Histograms that we will fill later

  TH1F *radial_prim_blocker = new TH1F("radial_prim_blocker","Radial Position of Primary Hits on the Main Detector with No Sieve in Place", 500, 600, 1200);
  radial_prim_blocker -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);

    //process over hits again to look at the blocker detector
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

        //Only look at charged particles that hit the main detector on rings 1-7.
        if (hit.det==28 && hit.pz>=0 && hit.r>600 && hit.r<1200 && (hit.trid==1))
        {

          radial_prim_blocker -> Fill(hit.r, rate);

      	}//end blocker det if

    }//end process over hits
  }//end process over events

//--------------------------------------------------------------------------------
//Draw and save the histograms

  //Create a canvas on which to draw the histograms
  TCanvas *prim_blocker = new TCanvas("prim_blocker","Particles Hitting the Blocker Detector", 1000, 1000, 1000, 1000);

  radial_prim_blocker -> Draw();

  //Integrate over this histogram to get the event rate in GHz/muA
  evrate = radial_prim_blocker -> Integral();
  //Print this value from the Integral and place it on the histogram
  printf("Event Rate = %f\n", evrate);
  TPaveLabel *Plab0 = new TPaveLabel(0.27, 0.76, 0.75, 0.87, Form("%5.4f GHz/#muA at %4.0f #muA", (evrate*1e-9)/(curr*1e6*20), curr*1e6), "NDC");
  Plab0 -> Draw();

  //Save the canvas as an image in the director "remoll/images/Blocker/"
  prim_blocker -> SaveAs("images/Prim_Det28_All_noblocker.png");

}//end Blocker()

