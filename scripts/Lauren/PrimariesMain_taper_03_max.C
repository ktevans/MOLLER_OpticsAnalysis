// Simple macro to draw a 1D histogram at detector position 28 which allows you to change
//   change the range of the plot and the energies.
//
//  Need to use reroot (CERN's root compiled with special remoll libraries, 
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//   needs to have a subdirectory "images"  defined for the images to go to 


#include <TF1.h>
void PrimariesMain_taper_03_max()
{
  TChain* T = new TChain("T");
  T->Add("rootfiles_lmc/remollout_taper_03_max_0123_ep.root");
  T->Add("rootfiles_lmc/remollout_taper_03_max_1234_ep.root");
  T->Add("rootfiles_lmc/remollout_taper_03_max_2345_ep.root");
  T->Add("rootfiles_lmc/remollout_taper_03_max_3456_ep.root");
  T->Add("rootfiles_lmc/remollout_taper_03_max_4567_ep.root");
  T->Add("rootfiles_lmc/remollout_taper_03_max_5678_ep.root");
  T->Add("rootfiles_lmc/remollout_taper_03_max_6789_ep.root");
  T->Add("rootfiles_lmc/remollout_taper_03_max_7890_ep.root");
  T->Add("rootfiles_lmc/remollout_taper_03_max_8901_ep.root");
  T->Add("rootfiles_lmc/remollout_taper_03_max_9012_ep.root");


  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  // Define some branches of the Tree (which is "T")
  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

  TH1F* h28 = new TH1F("h28","Electron Hits on the Main Detector Rings",500,650,1200);
  h28->GetXaxis()->SetTitle("Radial position of hits [mm]");
  
  // Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++) 
  {

    T->GetEntry(iev);

    // Process hits: loop over all the hits in this event
    for (size_t ihit = 0; ihit < hits->size(); ihit++) 
    {
        remollGenericDetectorHit_t hit = hits->at(ihit); 
  
      if (hit.det==28 && hit.trid==1 && hit.r>=650 && hit.r<=1200)
      {
         h28->Fill(hit.r);
      } // end if statement
    } // end loop over hits
  } // end loop over events  

  // Draw and save the histograms
  TCanvas *c1 = new TCanvas("c1","Energies at virtual detectors",100,100,500,500);

  h28->Draw();

  c1->SaveAs("images/primaries_main_03_max_taper.png");
}
