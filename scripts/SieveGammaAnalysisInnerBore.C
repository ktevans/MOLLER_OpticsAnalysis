
#include <TF1.h>
void Analysis(const TString& collimator, const TString& geo)
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");

  //string geo = "g1";

  //if(g == 2)
  //{
    //geo = "g2";
  //}

  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_0.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_1.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_2.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_3.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_4.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_5.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_6.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_7.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_8.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_9.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_10.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_11.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_12.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_13.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_14.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_15.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_16.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_17.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_18.root");
  T->Add("rootfilesPT/"+collimator+"_elasticC12_sieve_"+geo+"_19.root");

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

  TH1F *radial_main_all_color = new TH1F("radial_main_all_color","Radial Position of Gamma Hits on the Main Detector Rings for a 90mm "+collimator+" with "+geo+" Geometry", 100, 650, 1200);
  radial_main_all_color -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

  TH2F *xy_main_all_color = new TH2F("xy_main_all_color","Gamma Hits on the Main Detector Rings for a 90mm "+collimator+" with "+geo+" Geometry", 100, -1200, 1200, 100, -1200, 1200);
  xy_main_all_color -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  xy_main_all_color -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH2F *xy_main_all = new TH2F("xy_main_all","Gamma Hits on the Main Detector Rings for a 90mm "+collimator+" with "+geo+" Geometry", 1000, -1200, 1200, 1000, -1200, 1200);
  xy_main_all -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  xy_main_all -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH1F *vertex_main = new TH1F("vertex_main","Z Vertex of All Gammas that Hit the Main Detector for a 90mm "+collimator+" with "+geo+" Geometry", 100, -4500, 22000);
  vertex_main -> GetXaxis() -> SetTitle("z Position of the Vertex of Hits [mm]");

  TH1F *ring2_all = new TH1F("ring2_all","All Gammas that Hit Ring 2 on the Main Detector for a 90mm "+collimator+" with "+geo+" Geometry", 1000, 710, 760);
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
        if (hit.det==28 && hit.r>=650 && hit.r<=1200 && hit.pz>=0 && (hit.pid==22))
        {
          xy_main_all -> Fill(hit.x, hit.y, rate);
          xy_main_all_color -> Fill(hit.x, hit.y, rate);
          radial_main_all_color -> Fill(hit.r, rate);
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
  xy_main_all_color -> Draw("colz");

  //Look at the second entry on the canvas and draw the r main detector
  main_all_color -> cd(2);
  radial_main_all_color -> Draw("B");

  //Save the canvas as an image in the director "remoll/images/Blocker/"
  main_all_color -> SaveAs("images/InnerBore/Gamma_Main_All_Color_90mm"+collimator+"_"+geo+".png");

  //---Main Detector All Rings---

  //Create a canvas on which to draw the histograms
  TCanvas *main_all = new TCanvas("main_all","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

  xy_main_all -> Draw();

  //Save the canvas as an image in the director "remoll/images/Blocker/"
  main_all -> SaveAs("images/InnerBore/Gamma_Main_All_90mm"+collimator+"_"+geo+".png");

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
  main_all_vr -> SaveAs("images/InnerBore/Gamma_Main_All_VR_90mm"+collimator+"_"+geo+".png");

}//end Blocker()

