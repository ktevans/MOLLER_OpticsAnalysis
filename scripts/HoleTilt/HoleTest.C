#include <TF1.h>
void HoleTest(const TString& files)
{

  // Allow Tree to use the root files you call

  TChain* T = new TChain("T");
  T->Add(files);

  // Define variables that we will loop over later

  Double_t rate = 0;
  std::vector<remollEventParticle_t>* parts = 0;
  std::vector<remollGenericDetectorHit_t>* hits = 0;

  // Define some branches of the Tree (which is "T")

  T->SetBranchAddress("rate", &rate);
  T->SetBranchAddress("hit", &hits);
  T->SetBranchAddress("part", &parts);

// What does this line do?
gROOT -> SetBatch(kTRUE);

//Histogram skeletons:

//TH1* h1 = new TH1I("h1", "h1 title", 100, 0.0, 4.0);
   //[1D hist]* [name] = new ["TH1I" means one integer per bin]("name", "title of hist", [# of bins], [x_min], [x_max]);

//TH2* h2 = new TH2F("h2", "h2 title", 40, 0.0, 2.0, 30, -1.5, 3.5);
   //[2D hist]* [name] = new ["TH2F" means one float per bin]("name", "title of hist", [# of x bins], [x_min], [x_max], [# of y bins], [y_min], [y_max]);

//Could also use TH(1/2)C for one byte per bin, TH(1/2)S for one short per bin, or TH(1/2)D for one double per bin.

//Here is me defining histograms and setting the axis titles:

//Main detector histograms

TH1F* main_hole1 = new TH1F("main_hole1", "Detector 28 Primary Hit With Hole 1", 1000,0,1300);
main_hole1->GetXaxis()->SetTitle("Position in R");
main_hole1->SetMarkerColor(kBlue);

TH1F* main_hole2 = new TH1F("main_hole2", "Detector 28 Primary Hit With Hole 2", 1000,0,1300);
main_hole2->GetXaxis()->SetTitle("Position in R");
main_hole2->SetMarkerColor(kRed);

TH1F* main_hole3 = new TH1F("main_hole3", "Detector 28 Primary Hit With Hole 3", 1000,0,1300);
main_hole3->GetXaxis()->SetTitle("Position in R");
main_hole3->SetMarkerColor(kGreen);


// define logical flag for each hole

bool hole_1 = false;
bool hole_2 = false;
bool hole_3 = false;

  // Loop over all events

  for (size_t iev = 0; iev < T->GetEntries(); iev++) {
    T->GetEntry(iev);

    hole_1 = false;
    hole_2 = false;
    hole_3 = false;

    // Process hits: loop over all the hits in this event

    for (size_t ihit = 0; ihit < hits->size(); ihit++) {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //test if primary electrons went through sieve holes. Detectors 1001, 1002, and 1003 are on each set of holes

      if ((hit.det == 1001 && hit.trid == 1) || (hit.det == 1001 && hit.trid == 2)) {
          hole_1 = true;
      }
      if ((hit.det == 1002 && hit.trid == 1) || (hit.det == 1002 && hit.trid == 2)) {
          hole_2 = true;
      }
      if ((hit.det == 1003 && hit.trid == 1) || (hit.det == 1003 && hit.trid == 2)) {
          hole_3 = true;
      }
    }  // end loop over hits

    // Process hits again and separate them by which hole the primary electrons went through

    for (size_t ihit = 0; ihit < hits->size(); ihit++) {
      remollGenericDetectorHit_t hit = hits->at(ihit);

      if((hit.det == 28 && hole_1 && hit.trid == 1) || (hit.det == 28 && hole_1 && hit.trid == 2)) {
          main_hole1 -> Fill(hit.r,rate);
      }

      if((hit.det == 28 && hole_2 && hit.trid == 1) || (hit.det == 28 && hole_2 && hit.trid == 2)) {
          main_hole2 -> Fill(hit.r,rate);
      }

      if((hit.det == 28 && hole_3 && hit.trid == 1) || (hit.det == 28 && hole_3 && hit.trid == 2)) {
          main_hole3 -> Fill(hit.r,rate);
      }

    }  // end 2nd loop over hits
  }    //end loop over events

//----------------------------------------------------------------------
  // Draw and save the histograms

  TCanvas *c1 = new TCanvas("c1","Primary Electron Energies at Main Detector",100,100,500,500);

  main_hole1->Draw();  

  main_hole2->Draw("SAMES");

  main_hole3->Draw("SAMES");


  //This will save a .png file with your canvas on it.

  c1->SaveAs("images/HolePosTest.png");
}

