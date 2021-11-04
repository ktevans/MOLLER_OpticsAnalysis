#include <TF1.h>
void PunchThru()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm0.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm1.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm2.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm3.root");
//  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm4.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm5.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm6.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm7.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm8.root");
  T->Add("rootfilesPT/WSieveC12_ep_100k_77mm9.root");

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

  TH2F *us_sieve_virt = new TH2F("us_sieve_virt","Upstream Sieve (110mm) Virtual Detector Electron and Positron Hits for ep Scattering with Thin Carbon Target", 7000, -150, 150, 7000, -150, 150);
  us_sieve_virt -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  us_sieve_virt -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH2F *ds_sieve_virt = new TH2F("ds_sieve_virt","Downstream Sieve (110mm) Virtual Detector Electron and Positron Hits for ep Scattering with Thin Carbon Target", 7000, -150, 150, 7000, -150, 150);
  ds_sieve_virt -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  ds_sieve_virt -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH2F *punch_thru_main = new TH2F("punch_thru_main","Electrons and Positrons that Punched Through the Sieve (110mm) and Hit the Main Detector for ep Scattering with Thin Carbon Target", 1000, -1200, 1200, 1000, -1200, 1200);
  punch_thru_main -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  punch_thru_main -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH2F *part_energy = new TH2F("part_energy","Electron and Positron Energies that Punched Through the Sieve (110mm) for ep Scattering with Thin Carbon Target", 1000, 0, 500, 1000, 0, 150);
  part_energy -> GetXaxis() -> SetTitle("Energy of Punch Through Hits [MeV]");
  part_energy -> GetYaxis() -> SetTitle("Radial Position of Punch Through Hits [mm]");

  TH1F *radial_main = new TH1F("radial_main","Electrons and Positrons that Punch Through the Sieve (110mm) and Hit the Main Detector", 1000, 650, 1200);
  radial_main -> GetXaxis() -> SetTitle("r Position of Hits [mm]");


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

      //no_hole_# is false if primary electron goes through the hole
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
        //Only look at the sectors of the sieve based on the phi value of each hit
        //if ((hit.ph>=-2.4670228 && hit.ph<=-2.0184732) || (hit.ph>=-1.5699236 && hit.ph<=-1.121374) || (hit.ph>=-0.6728244 && hit.ph<=-0.2242748) || (hit.ph>=0.2242748 && hit.ph<=0.6728244) || (hit.ph>=1.121374 && hit.ph<=1.5699236) || (hit.ph>=2.0184732 && hit.ph<=2.4670228) || (hit.ph>=2.9155721 && hit.ph<=3.141593) || (hit.ph>=-3.141593 && hit.ph<=-2.9155721))
        //{

          if (hit.det == 1004 && hit.pz >= 0)
          {
            us_sieve_virt -> Fill(hit.x, hit.y, rate);
          }
      
          if (hit.det == 1005 && hit.pz >= 0)
          {
            ds_sieve_virt -> Fill(hit.x, hit.y, rate);
            part_energy -> Fill(hit.e, hit.r, rate);
            punch_thru = true;
          }
      }//end pid and hole if
	//}//end phi if
    }//end process over hits
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

        if (punch_thru && hit.det==28 && hit.r >= 650 && hit.r <= 1200)
        {
          punch_thru_main -> Fill(hit.x, hit.y, rate);
          radial_main -> Fill(hit.r, rate);
	}

    }//end process over hits
  }//end process over events

//--------------------------------------------------------------------------------
  //Draw and save the histograms

  TCanvas *virt = new TCanvas("virt","Charged Particles Hitting the Virtual Detectors Upstream and Downstream of the Sieve", 1000, 1000, 1000, 1000);

  virt -> Divide(1,2);
  
  virt -> cd(1);
  us_sieve_virt -> Draw();

  virt -> cd(2);
  ds_sieve_virt -> Draw();

  virt -> SaveAs("images/PT/Punch_Thru_US_DS_WSieve_77.png");

  TCanvas *main = new TCanvas("main","Electrons and Positrons Hitting the Main Detector", 1000, 1000, 1000, 1000);

  main -> Divide(1,2);

  main -> cd(1);
  punch_thru_main -> Draw();

  main -> cd(2);
  radial_main -> Draw();

  main -> SaveAs("images/PT/Punch_Thru_Main_WSieve_77.png");

  TCanvas *energy = new TCanvas("energy","Electron and Positron Energies that Punch Through the Sieve", 400, 400, 600, 600);

  part_energy -> Draw();
  energy -> SaveAs("images/PT/Punch_Thru_Energy_WSieve_77.png");


}
