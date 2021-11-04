#include <TF1.h>
void PunchThru(const TString& files)
{
  //Allow Tree to use the root files that you call
  TChain* T = new TChain("T");
  T->Add(files);

  //Define variables that we will loop over later
  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  //Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  gROOT -> SetBatch(kTRUE);

  //TH2F *us_sieve_virt = new TH2F("us_sieve_virt","Upstream Sieve Virtual Detector 500+ MeV Electron and Positron Hits for ep Scattering with C12 Target", 7000, -150, 150, 7000, -150, 150);
  TH2F *us_sieve_virt = new TH2F("us_sieve_virt","Upstream Sieve Virtual Detector Electron and Positron Hits for ep Scattering with C12 Target", 7000, -150, 150, 7000, -150, 150);
  us_sieve_virt -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  us_sieve_virt -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  //TH2F *ds_sieve_virt = new TH2F("ds_sieve_virt","Downstream Sieve Virtual Detector 500+ MeV Electron and Positron Hits for ep Scattering with C12 Target", 7000, -150, 150, 7000, -150, 150);
  TH2F *ds_sieve_virt = new TH2F("ds_sieve_virt","Downstream Sieve Virtual Detector Electron and Positron Hits for ep Scattering with C12 Target", 7000, -150, 150, 7000, -150, 150);
  ds_sieve_virt -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  ds_sieve_virt -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  //TH2F *punch_thru_main = new TH2F("punch_thru_main","500+ MeV Electrons and Positrons that Punched Through the Sieve for ep Scattering with C12 Target", 1000, -300, 300, 1000, -300, 300);
  TH2F *punch_thru_main = new TH2F("punch_thru_main","Electrons and Positrons that Punched Through the Sieve for ep Scattering with C12 Target", 1000, -300, 300, 1000, -300, 300);
  punch_thru_main -> GetXaxis() -> SetTitle("x Position of Hits [mm]");
  punch_thru_main -> GetYaxis() -> SetTitle("y Position of Hits [mm]");

  TH2F *part_energy = new TH2F("part_energy","Electron and Positron Energies  that Punched Through the Sieve for ep Scattering with C12 Target", 1000, 0, 500, 1000, 0, 150);
  part_energy -> GetXaxis() -> SetTitle("Energy of Punch Through Hits [MeV]");
  part_energy -> GetYaxis() -> SetTitle("Radial Position of Punch Through Hits [mm]");


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

      //Only plot electrons hitting the upstream and downstream detectors that are above 500 MeV and will not go through the sieve holes
      //if ((hit.pid==11 || hit.pid==-11) && hit.e>500 && no_hole_1 && no_hole_2 && no_hole_3 && hit.r >=35.306 && hit.r<97.9932)
      if ((hit.pid==11 || hit.pid==-11) && no_hole_1 && no_hole_2 && no_hole_3 && hit.r >=35.306 && hit.r<97.9932)
      {
        //Only look at the sectors of the sieve based on the phi value of each hit
        if ((hit.ph>=-2.4670228 && hit.ph<=-2.0184732) || (hit.ph>=-1.5699236 && hit.ph<=-1.121374) || (hit.ph>=-0.6728244 && hit.ph<=-0.2242748) || (hit.ph>=0.2242748 && hit.ph<=0.6728244) || (hit.ph>=1.121374 && hit.ph<=1.5699236) || (hit.ph>=2.0184732 && hit.ph<=2.4670228) || (hit.ph>=2.9155721 && hit.ph<=3.141593) || (hit.ph>=-3.141593 && hit.ph<=-2.9155721))
        {

          if (hit.det == 1004)
          {
            us_sieve_virt -> Fill(hit.x, hit.y, rate);
          }
      
          if (hit.det == 1005)
          {
            ds_sieve_virt -> Fill(hit.x, hit.y, rate);
            part_energy -> Fill(hit.e, hit.r, rate);
            punch_thru = true;
          }

	}//end phi if

        if (punch_thru && hit.det==28)
        {
          punch_thru_main -> Fill(hit.x, hit.y, rate);
	}
      }//end pid and hole if

    }
  }

//--------------------------------------------------------------------------------
  //Draw and save the histograms

  TCanvas *virt = new TCanvas("virt","Electrons Hitting the Virtual Detectors Upstream and Downstream of the Sieve", 1000, 1000, 1000, 1000);

  virt -> Divide(1,2);
  
  virt -> cd(1);
  us_sieve_virt -> Draw();

  virt -> cd(2);
  ds_sieve_virt -> Draw();

  virt -> SaveAs("images/Punch_Thru_US_DS_Sieve.png");

  //Get rid of automatic title
  //gStyle -> SetOptTitle(0);

  TCanvas *main = new TCanvas("main","Electrons and Positrons Hitting the Main Detector", 500, 500, 500, 500);

  punch_thru_main -> Draw();
  main -> SaveAs("images/Punch_Thru_Main.png");

  TCanvas *energy = new TCanvas("energy","Electron and Positron Energies that Punch Through the Sieve", 500, 500, 500, 500);

  part_energy -> Draw();
  energy -> SaveAs("images/Punch_Thru_Energy.png");


}
