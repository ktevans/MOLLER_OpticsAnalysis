// Simple macro to draw a 1D histogram at detector position 28 which allows you to change
//   change the range of the plot and the energies.
//
//  Need to use reroot (CERN's root compiled with special remoll libraries, 
//  or root when you have linked to ibremoll.so, i.e. by a command like
//    setenv LD_PRELOAD build/libremoll.so
//   needs to have a subdirectory "images"  defined for the images to go to 


#include <TF1.h>
void eenergies(const TString& files)
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

  TH1F* he28 = new TH1F("he28","Hit Energies of Electrons Greater than 500 MeV", 100, 0,0.01);
  he28->GetXaxis()->SetTitle("need to understand better what this is plotting"); he28->GetYaxis()->SetTitle("need to understand better what this is plotting");

  // Draw and save the histograms
  TCanvas *c1 = new TCanvas("c1","Rates at virtual detectors",100,100,500,500);
  
  // Loop over all events
  for (size_t iev = 0; iev < T->GetEntries(); iev++) 
  {

    T->GetEntry(iev);

    // Process hits: loop over all the hits in this event
    for (size_t ihit = 0; ihit < hits->size(); ihit++) 
    {
        remollGenericDetectorHit_t hit = hits->at(ihit); 
  
      if (hit.det==28 && hit.e>500 && hit.pid==11)
      {
         he28->Fill(hit.r);
      } // end if statement
    } // end loop over hits
  } // end loop over events  

  he28->Draw();

  c1->SaveAs("images/electron_energies_main.png");
}