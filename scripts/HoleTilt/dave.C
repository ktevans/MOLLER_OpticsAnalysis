// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries, 
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//   needs to have a subdirectory "images"  defined for the images to go to 
//  
// Run using (for example):
//   build/reroot -l -q 'analysis/dave_test.C("remollout.root")'
//
//  Can put multiple root files in argument, and they will be chained together.
//
//  Includes examples of weighted and unweighted 1D histrograms and a 2D 
//  histogram, as well as some simple conditional cuts.


#include <TF1.h>
void dave(const TString& files)
{
  TChain* T = new TChain("T");
  T->Add(files);

  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  // Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  //Define some histograms

  TH1F* hr28 = new TH1F("hr28","Hit radius at detector plane 28 (main det)",100,0,2000);
  hr28->GetXaxis()->SetTitle("r [mm], 20 mm / bin"); hr28->GetYaxis()->SetTitle("Hz/uA");

  TH1F* hr28_raw = new TH1F("hr28_raw","Hit radius at detector plane 28 (main det) raw hits",100,0,2000);
  hr28_raw->GetXaxis()->SetTitle("r [mm], 20 mm / bin"); hr28_raw->GetYaxis()->SetTitle("hits");

  TH1F* hr28_photon = new TH1F("hr28_photon","Hit radius at detector plane 28 (main det) photons ",100,0,2000);
  hr28_photon->GetXaxis()->SetTitle("r [mm], 20 mm / bin"); hr28_photon->GetYaxis()->SetTitle("hits");

  TH1F* hr28_positron = new TH1F("hr28_positron","Hit radius at detector plane 28 (main det) postirons ",100,0,2000);
  hr28_photon->GetXaxis()->SetTitle("r [mm], 20 mm / bin"); hr28_photon->GetYaxis()->SetTitle("hits");

  TH1F* hr29 = new TH1F("hr29","Hit radius at detector plane 29 (pion det)",100,0,2000);
  hr29->GetXaxis()->SetTitle("r [mm], 20 mm / bin"); hr29->GetYaxis()->SetTitle("Hz/uA");

  TH1F* hr29_raw = new TH1F("hr29_raw","Hit radius at detector plane 29 (main det) raw hits",100,0,2000);
  hr29_raw->GetXaxis()->SetTitle("r [mm], 20 mm / bin"); hr29_raw->GetYaxis()->SetTitle("hits");

  TH1F* hr29_ring5 = new TH1F("hr29_ring5","Hit radius at plane 29, events with ring 5 electrons",100,0,2000);
  hr29_ring5->GetXaxis()->SetTitle("r [mm], 20 mm / bin"); hr29_raw->GetYaxis()->SetTitle("hits");

 TH2F* h28_xy = new TH2F("h28_xy","Detector 28 charged hits x vs y ",40,-2000,2000,40,-2000,2000);

  bool ring_5 = false;    // define logical flag

  // Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++) {
    T->GetEntry(iev);

    ring_5=false;
    // Process hits: loop over all the hits in this event
    for (size_t ihit = 0; ihit < hits->size(); ihit++) {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      // fill histograms weighted by rate variable, and raw (as thrown)
      if (hit.det == 28 && hit.pid != 22 && hit.pid != 0) {
        hr28->Fill(hit.r, rate);
        hr28_raw->Fill(hit.r);
	h28_xy->Fill(hit.x,hit.y);
	// did an energetic electron hit ring 5?
	if (hit.r > 950 && hit.r < 1050 && hit.e > 1000) ring_5 = true; 
      }

      // fill photon histogram
      if (hit.det == 28 && hit.pid == 22 ) {
        hr28_photon->Fill(hit.r);
      }

      // fill positron histogram
      if (hit.det == 28 && hit.pid == -11 ) {
        hr28_positron->Fill(hit.r);
      }

      if (hit.det == 29 && hit.pid != 22 && hit.pid != 0) {
        hr29->Fill(hit.r, rate);
        hr29_raw->Fill(hit.r);
      }

    }  // end loop over hits

    // Process hits again
    for (size_t ihit = 0; ihit < hits->size(); ihit++) {
      remollGenericDetectorHit_t hit = hits->at(ihit);
      if (hit.det == 29 && hit.pid != 22 && hit.pid != 0 && ring_5) {
	// charged hits in Det 29 for electrons in ring 5
        hr29_ring5->Fill(hit.r);
      }
    }  // end 2nd loop over hits
  }    //end loop over events

//----------------------------------------------------------------------
  // Draw and save the histograms
  TCanvas *c1 = new TCanvas("c1","Rates at virtual detectors",100,100,500,500);
  c1->Divide(2,2);
  c1->cd(1);
  hr28->Draw();
  c1->cd(2);
  hr29->Draw();
  c1->cd(3);
  hr28_raw->Draw();
  c1->cd(4);
  h28_xy->Draw();

  c1->SaveAs("images/dave_pion_rates.png");

  TCanvas *c2 = new TCanvas("c2","Electron Rates at virtual detectors",100,100,500,500);
  c2->Divide(2,2);
  c2->cd(1);
  hr29_raw->Draw();
  c2->cd(2);
  hr29_ring5->Draw();
  c2->cd(3);
  hr28_photon->Draw();
  c2->cd(4);
  hr28_positron->Draw();

  c2->SaveAs("images/dave_rates.png");
}
