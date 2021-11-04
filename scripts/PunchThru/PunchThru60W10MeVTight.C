#include <TF1.h>
void PunchThru()
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets1.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets2.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets3.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets4.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets5.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets6.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets7.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets8.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets9.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets10.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets11.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets12.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets13.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets14.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets15.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets16.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets17.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets18.root");
  T->Add("rootfiles/WSieveC12_ep_100k_60mm_TightDets19.root");

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);
;
  TH2F *us_sieve_virt = new TH2F("us_sieve_virt","Upstream W Sieve (60mm) Virtual Detector Electron and Positron Hits Greater than 10MeV for ep Scattering with C12 Target", 7000, -150, 150, 7000, -150, 150);
  us_sieve_virt -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  us_sieve_virt -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH2F *ds_sieve_virt = new TH2F("ds_sieve_virt","Downstream W Sieve (60mm) Virtual Detector Electron and Positron Hits Greater than 10MeV for ep Scattering with C12 Target", 7000, -150, 150, 7000, -150, 150);
  ds_sieve_virt -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  ds_sieve_virt -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH2F *punch_thru_main = new TH2F("punch_thru_main","Electrons and Positrons Greater than 10MeV that Punched Through the W Sieve (60mm) and Hit the Main Detector for ep Scattering with C12 Target", 1000, -1000, 1000, 1000, -1000, 1000);
  punch_thru_main -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  punch_thru_main -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH2F *part_energy = new TH2F("part_energy","Electron and Positron Energies Greater than 10MeV that Punched Through theW  Sieve (60mm) for ep Scattering with C12 Target", 1000, 0, 500, 1000, 30, 115);
  part_energy -> GetXaxis() -> SetTitle("Energy of Punch Through Hits [MeV]");
  part_energy -> GetYaxis() -> SetTitle("Radial Position of Punch Through Hits [mm]");

  //TH2F *col2 = new TH2F("col2","Electrons and Positrons Greater than 10MeV that Punch Through the W Sieve (60mm) and Make it Past Collimator 2 for ep Scattering with C12 Target", 1000, -200, 200, 1000, -200, 200);
  //col2 -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  //col2 -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH1F *radial_main = new TH1F("radial_main","Electrons and Positrons Greater than 10MeV that Punch Through the W Sieve (60mm) and Hit the Main Detector",1000,500,1300);
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

      //no_hole_# is false if the electron goes through the hole
      if (hit.det == 1001 && (hit.pid == 11 || hit.pid==-11))
      {
        no_hole_1 = false;
      }

      if (hit.det == 1002 && (hit.pid == 11 || hit.pid==-11))
      {
        no_hole_2 = false;
      }

      if (hit.det == 1003 && (hit.pid == 11 || hit.pid==-11))
      {
        no_hole_3 = false;
      }
    }

    //Process over hits again
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      if ((hit.pid==11 || hit.pid==-11) && no_hole_1 && no_hole_2 && no_hole_3 && hit.r >=35.306 && hit.r<97.9932 && hit.e>10)
      {
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

        if (punch_thru && hit.det==28)
        {
          punch_thru_main -> Fill(hit.x, hit.y, rate);
          radial_main -> Fill(hit.r, rate);
	}
        //if (punch_thru && hit.det==1006)
        //{
          //col2 -> Fill(hit.x, hit.y, rate);
        //}
      }//end pid and hole if

    }
  }

//--------------------------------------------------------------------------------
  //Draw and save the histograms

  TCanvas *virt = new TCanvas("virt","Electrons Hitting the Virtual Detectors Upstream and Downstream of the 60 mm Sieve", 1000, 1000, 1000, 1000);

  virt -> Divide(1,2);
  
  virt -> cd(1);
  us_sieve_virt -> Draw();

  virt -> cd(2);
  ds_sieve_virt -> Draw();

  virt -> SaveAs("images/Punch_Thru_US_DS_WSieve_60mm_10MeV_Tight.png");

  TCanvas *main2 = new TCanvas("main","Electrons and Positrons Hitting the Main Detector", 1000, 1000, 1000, 1000);

  main2 -> Divide(1,2);

  main2 -> cd(1);
  punch_thru_main -> Draw();

  main2 -> cd(2);
  radial_main -> Draw();

  main2 -> SaveAs("images/Punch_Thru_Main_W60mm_10MeV_Tight.png");

  TCanvas *energy = new TCanvas("energy","Electron and Positron Energies that Punch Through the Sieve", 400, 400, 600, 600);

  part_energy -> Draw();
  energy -> SaveAs("images/Punch_Thru_Energy_W60mm_10MeV_Tight.png");


}
