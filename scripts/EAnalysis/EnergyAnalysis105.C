// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries, 
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//  needs to have a subdirectory "images/EAnalysis" defined for the images to go to 
//  
//  Run using (for example):
//   build/reroot
//   .L scripts/EnergyAnalysis105.C
//   EnergyAnalysis105()
//
//  Can put multiple root files in the script, and they will be chained together.
//

#include <TF1.h>
void EnergyAnalysis105()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  
  //Add files from the directory "rootfilesPT/", "105" is the sieve thickness in mm
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm0.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm1.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm2.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm3.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm4.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm5.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm6.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm7.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm8.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_105mm9.root");

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

  
  Float_t in_e, out_e = 0; 

//----------------------------------------------------------------------------

  //Define Histograms that we will fill later

  //2D histogram for e+ and e- hitting the upstream sieve surface
  TH2F *us_sieve_virt_energy = new TH2F("us_sieve_virt_energy","Upstream Sieve (105mm) Virtual Detector Primary Energies for ep Scattering with Thin Carbon Target", 7000, 0, 1500, 7000, 30, 110);
  us_sieve_virt_energy -> GetXaxis() -> SetTitle("Energy of Hits [MeV]");
  us_sieve_virt_energy -> GetYaxis() -> SetTitle("r Position of Hits [mm]");

  //2D histogram for e+ and e- hitting the downstream sieve surface, i.e., the particles that punch through the sieve 
  TH2F *ds_sieve_virt_energy = new TH2F("ds_sieve_virt_energy","Downstream Sieve (105mm) Virtual Detector Primary Energies for ep Scattering with Thin Carbon Target", 7000, 0, 1500, 7000, 30, 110);
  ds_sieve_virt_energy -> GetXaxis() -> SetTitle("Energy of Hits [MeV]");
  ds_sieve_virt_energy -> GetYaxis() -> SetTitle("r Position of Hits [mm]");

  TH1F *prim_clean_pass = new TH1F("prim_clean_pass","Primaries that Pass Through the Sieve (105mm) Holes without Losing Energy and Hit the Main Detector Rings", 1000, 650, 1200);
  prim_clean_pass -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

  TH1F *prim_pass = new TH1F("prim_pass","All Primaries that Hit the Main Detector Rings with a W Sieve (105mm)", 1000, 650, 1200);
  prim_pass -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

//----------------------------------------------------------------------------

  //Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {
    T->GetEntry(iev);

    in_e = 0;
    out_e = 0;

    //Process over hits
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      if ((hit.trid==1 || hit.trid==2) && hit.r >=35.306 && hit.r<97.9932)
      {

          if (hit.det == 1004 && hit.pz >= 0)
          {
            us_sieve_virt_energy -> Fill(hit.e, hit.r, rate);
            in_e = hit.e;
          }//end upstream if
      
          if (hit.det == 1005 && hit.pz >= 0)
          {
            ds_sieve_virt_energy -> Fill(hit.e, hit.r, rate);
            out_e = hit.e;

          }//end downstream if 

      }//end pid and hole if

      if(abs(in_e - out_e) <= 0.1 && (hit.trid == 1 || hit.trid == 2) && hit.det ==28 && hit.r >= 650 && hit.r <= 1200 && hit.pz >= 0)
      {
        prim_clean_pass -> Fill(hit.r, rate);
      }

      if((hit.trid == 1 || hit.trid == 2) && hit.det ==28 && hit.r >= 650 && hit.r <= 1200 && hit.pz >= 0)
      {
        prim_pass -> Fill(hit.r, rate);
      }

    }//end process over hits
  }//end process over events

//--------------------------------------------------------------------------------
//Draw and save the histograms

  //---Sieve Surfaces---

  //Create a canvas on which to draw the histograms
  TCanvas *virt = new TCanvas("virt","Charged Particles Hitting the Virtual Detectors Upstream and Downstream of the Sieve", 1000, 1000, 1000, 1000);

  //Divide the canvas into 1 column, 2 rows
  virt -> Divide(1,2);
  
  //Look at the first entry on the canvas and draw the upstream detector
  virt -> cd(1);
  us_sieve_virt_energy -> Draw();

  //Look at the second entry on the canvas and draw the downstream detector
  virt -> cd(2);
  ds_sieve_virt_energy -> Draw();

  //Save the canvas as an image in the director "remoll/images/PT/"
  virt -> SaveAs("images/EAnalysis/US_DS_Prim_Energy_WSieve_105.png");

  //---Main Det---

  TCanvas *main_all = new TCanvas("main_all","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

  prim_clean_pass -> Draw();

  main_all -> SaveAs("images/EAnalysis/same_energy_main_WSieve_105.png");

  TCanvas *main_all_prim = new TCanvas("main_all_prim","Particles Hitting the Main Detector", 1000, 1000, 1000, 1000);

  prim_pass -> Draw();

  main_all_prim -> SaveAs("images/EAnalysis/prim_main_WSieve_105.png");


}//end EnergyAnalysis()
