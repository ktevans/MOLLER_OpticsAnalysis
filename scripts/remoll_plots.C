// Simple example macro for reroot analysis of remoll simulations for MOLLER
//
//  Need to use reroot (CERN's root compiled with special remoll libraries),
//  or generic root when you have linked to libremoll.so, i.e. by a command like
//     setenv LD_PRELOAD build/libremoll.so
//
//   Needs to have a subdirectory "images" defined, for the images to go to
//
// Run using (for example):
//   build/reroot -l -q 'remoll_plots.C("remollout.root")'
//
//  Can put multiple root files in argument, and they will be chained together.
//
//  Includes examples of weighted and unweighted 1D histograms and  2D
//  histograms, as well as some simple conditional cuts.
//    Can also run from the TBrowser:
//     build/reroot
//     re-root [1] .L remoll_plots.C
//     re-root [2] remoll_plots("remollout.root")
//        (this would analyze the single file remollout.root)

//------------------------

// 1. bm->z < -4890
// 2. bm->z > -4890 && bm->z < -4630
// 3. bm->z > -4630 && bm->z <-4370
// 4. bm->z >-4370 && bm->z <-4110
// 5. bm->z >-4110 && bm->z <-3850

//-------------------------




#include <TF1.h>
void remoll_plots(const TString& files)
{
 TChain* T = new TChain("T");
 T->Add(files);

 Double_t rate = 0;
 std::vector<remollEventParticle_t>* parts = 0;
 std::vector<remollGenericDetectorHit_t>* hits = 0;
 remollBeamTarget_t *bm=0;

 // Define some branches of the Tree (which is "T")
 T->SetBranchAddress("rate", &rate);
 T->SetBranchAddress("hit", &hits);
 T->SetBranchAddress("part", &parts);
 T->SetBranchAddress("bm", &bm);

 //Define some histograms
gROOT -> SetBatch(kTRUE);

//REGULAR HISTS
TH1F* maindet_1D = new TH1F("maindet_1D","Main Detector",110,0,1.1);
maindet_1D->GetXaxis()->SetTitle("I am not sure");
maindet_1D->GetYaxis()->SetTitle("Really I should ask");

TH1F* maindet_1D_square = new TH1F("maindet_1D_square","Main Detector r",400,0,2000);
maindet_1D_square->GetXaxis()->SetTitle("Radial Value");
maindet_1D_square->GetYaxis()->SetTitle("Events");

TH1F* maindet_1D_square_hole1 = new TH1F("maindet_1D_square_hole1","Main Detector r hole 1",400,0,2000);
maindet_1D_square_hole1->GetXaxis()->SetTitle("Radial Value");
maindet_1D_square_hole1->GetYaxis()->SetTitle("Events");
maindet_1D_square_hole1->SetLineColorAlpha(4, 0.35);

TH1F* maindet_1D_square_hole2 = new TH1F("maindet_1D_square_hole2","Main Detector r hole 2",400,0,2000);
maindet_1D_square_hole2->GetXaxis()->SetTitle("Radial Value");
maindet_1D_square_hole2->GetYaxis()->SetTitle("Events");
maindet_1D_square_hole2->SetLineColorAlpha(2, 0.35);

TH1F* maindet_1D_square_hole3 = new TH1F("maindet_1D_square_hole3","Main Detector r hole 3",400,0,2000);
maindet_1D_square_hole3->GetXaxis()->SetTitle("Radial Value");
maindet_1D_square_hole3->GetYaxis()->SetTitle("Events");
maindet_1D_square_hole3->SetLineColorAlpha(3, 0.35);

TH2F* maindet_2D = new TH2F("maindet_2D","Detector 28  primary hits",1000,-2000,2000,1000,-2000,2000);
maindet_2D->GetXaxis()->SetTitle("Position in X");
maindet_2D->GetYaxis()->SetTitle("Position in Y");

TH2F* maindet_2D_slice = new TH2F("maindet_2D_slice","Detector 28 primary hits",1000,-1500,-500,1000,-500,500);
maindet_2D_slice->GetXaxis()->SetTitle("Position in X");
maindet_2D_slice->GetYaxis()->SetTitle("Position in Y");

TH2F* main_hole1 = new TH2F("main_hole1", "Detector 28 Primary Hit With Hole 1", 1000,-2000,2000,1000,-2000,2000);
main_hole1->GetXaxis()->SetTitle("Position in X");
main_hole1->GetYaxis()->SetTitle("Position in Y");
main_hole1->SetMarkerColor(4);

TH2F* main_hole2 = new TH2F("main_hole2", "Detector 28 Primary Hit With Hole 2", 1000,-2000,2000,1000,-2000,2000);
main_hole2->GetXaxis()->SetTitle("Position in X");
main_hole2->GetYaxis()->SetTitle("Position in Y");
main_hole2->SetMarkerColor(2);

TH2F* main_hole3 = new TH2F("main_hole3", "Detector 28 Primary Hit With Hole 3", 1000,-2000,2000,1000,-2000,2000);
main_hole3->GetXaxis()->SetTitle("Position in X");
main_hole3->GetYaxis()->SetTitle("Position in Y");
main_hole3->SetMarkerColor(3);

TH2F* main_hole1_slice = new TH2F("main_hole1_slice", "Detector 28 Primary Hit With Hole 1 Slice", 1000,-1500,-500,1000,-500,500);
main_hole1_slice->GetXaxis()->SetTitle("Position in X");
main_hole1_slice->GetYaxis()->SetTitle("Position in Y");
main_hole1_slice->SetMarkerColor(4);

TH2F* main_hole2_slice = new TH2F("main_hole2_slice", "Detector 28 Primary Hit With Hole 2 Slice", 1000,-1500,-500,1000,-500,500);
main_hole2_slice->GetXaxis()->SetTitle("Position in X");
main_hole2_slice->GetYaxis()->SetTitle("Position in Y");
main_hole2_slice->SetMarkerColor(2);

TH2F* main_hole3_slice = new TH2F("main_hole3_slice", "Detector 28 Primary Hit With Hole 3 Slice", 1000,-1500,-500,1000,-500,500);
main_hole3_slice->GetXaxis()->SetTitle("Position in X");
main_hole3_slice->GetYaxis()->SetTitle("Position in Y");
main_hole3_slice->SetMarkerColor(3);

TH1F* target_z = new TH1F("target_z","Target Z",200,-6000,-3000);
target_z->GetXaxis()->SetTitle("Z in mm");
target_z->GetYaxis()->SetTitle("Events");

TH1F* polar_angle = new TH1F("polar_angle","Polar Angle",100,0,30);
polar_angle->GetXaxis()->SetTitle("polar angle (rad)");
polar_angle->GetYaxis()->SetTitle("Events");

TH1F* hole1_polar_angle = new TH1F("hole1_polar_angle","Polar Angle at hole 1",100,0,30);
hole1_polar_angle->GetXaxis()->SetTitle("polar angle (rad)");
hole1_polar_angle->GetYaxis()->SetTitle("Events");
hole1_polar_angle->SetLineColorAlpha(4, 0.35);

TH1F* hole2_polar_angle = new TH1F("hole2_polar_angle","Polar Angle at hole 2",100,0,30);
hole2_polar_angle->GetXaxis()->SetTitle("polar angle (rad)");
hole2_polar_angle->GetYaxis()->SetTitle("Events");
hole2_polar_angle->SetLineColorAlpha(2, 0.35);

TH1F* hole3_polar_angle = new TH1F("hole3_polar_angle","Polar Angle at hole 3",100,0,30);
hole3_polar_angle->GetXaxis()->SetTitle("polar angle (rad)");
hole3_polar_angle->GetYaxis()->SetTitle("Events");
hole3_polar_angle->SetLineColorAlpha(3, 0.35);

TH1F* hit_e = new TH1F("hit_e","Energy at Main Detector ",200,0,10000);
hit_e->GetXaxis()->SetTitle("Energy");
hit_e->GetYaxis()->SetTitle("Events");

//Energy
TH2F* maindet_2D_energy_500_below = new TH2F("maindet_2D_energy_500_below","Detector 28  primary hits with energy below 500",1000,-2000,2000,1000,-2000,2000);
maindet_2D_energy_500_below->GetXaxis()->SetTitle("Position in X");
maindet_2D_energy_500_below->GetYaxis()->SetTitle("Position in Y");

TH2F* maindet_2D_energy_500_above = new TH2F("maindet_2D_energy_500_above","Detector 28  primary hits with energy above 500",1000,-2000,2000,1000,-2000,2000);
maindet_2D_energy_500_above->GetXaxis()->SetTitle("Position in X");
maindet_2D_energy_500_above->GetYaxis()->SetTitle("Position in Y");




//-----------------------------------------------------------------------------------------------------------------------------


//Z DEPENDANCE 1

TH1F* target_z1 = new TH1F("target_z1","Target Z less than -4890",200,-6000,-3000);
target_z1->GetXaxis()->SetTitle("Z in mm");
target_z1->GetYaxis()->SetTitle("Events");

TH2F* main_hole1_z1 = new TH2F("main_hole1_z1", "Detector 28 Primary Hit With Hole 1 with Z less than -4890", 1000,-2000,2000,1000,-2000,2000);
main_hole1_z1->GetXaxis()->SetTitle("Position in X");
main_hole1_z1->GetYaxis()->SetTitle("Position in Y");
main_hole1_z1->SetMarkerColorAlpha(4,0.7);

TH2F* main_hole2_z1 = new TH2F("main_hole2_z1", "Detector 28 Primary Hit With Hole 2 with Z less than -4890", 1000,-2000,2000,1000,-2000,2000);
main_hole2_z1->GetXaxis()->SetTitle("Position in X");
main_hole2_z1->GetYaxis()->SetTitle("Position in Y");
main_hole2_z1->SetMarkerColorAlpha(2,0.7);

TH2F* main_hole3_z1 = new TH2F("main_hole3_z1", "Detector 28 Primary Hit With Hole 3 with Z less than -4890", 1000,-2000,2000,1000,-2000,2000);
main_hole3_z1->GetXaxis()->SetTitle("Position in X");
main_hole3_z1->GetYaxis()->SetTitle("Position in Y");
main_hole3_z1->SetMarkerColorAlpha(3,0.7);


TH1F*  main_hole1_z1_r = new TH1F(" main_hole1_z1_r","Radial values Detector 28 Primary Hit With Hole 1 with Z less than -4890",400,600,1200);
main_hole1_z1_r->GetXaxis()->SetTitle("I am not sure");
main_hole1_z1_r->GetYaxis()->SetTitle("Really I should ask");
main_hole1_z1_r->SetLineColorAlpha(4, 0.35);

TH1F*  main_hole2_z1_r = new TH1F(" main_hole2_z1_r","Radial values Detector 28 Primary Hit With Hole 2 with Z less than -4890",400,600,1200);
main_hole2_z1_r->GetXaxis()->SetTitle("I am not sure");
main_hole2_z1_r->GetYaxis()->SetTitle("Really I should ask");
main_hole2_z1_r->SetLineColorAlpha(2, 0.35);

TH1F*  main_hole3_z1_r = new TH1F(" main_hole3_z1_r","Radial values Detector 28 Primary Hit With Hole 3 with Z less than -4890",400,600,1200);
main_hole3_z1_r->GetXaxis()->SetTitle("I am not sure");
main_hole3_z1_r->GetYaxis()->SetTitle("Really I should ask");
main_hole3_z1_r->SetLineColorAlpha(3, 0.35);


//Z DEPENDANCE SLICE

TH2F* main_hole1_z1_slice = new TH2F("main_hole1_z1_slice", "Detector 28 Primary Hit With Hole 1 with Z less than -4890", 1000,-1500,-500,1000,-500,500);
main_hole1_z1_slice->GetXaxis()->SetTitle("Position in X");
main_hole1_z1_slice->GetYaxis()->SetTitle("Position in Y");
main_hole1_z1_slice->SetMarkerColor(4);

TH2F* main_hole2_z1_slice = new TH2F("main_hole2_z1_slice", "Detector 28 Primary Hit With Hole 2 with Z less than -4890", 1000,-1500,-500,1000,-500,500);
main_hole2_z1_slice->GetXaxis()->SetTitle("Position in X");
main_hole2_z1_slice->GetYaxis()->SetTitle("Position in Y");
main_hole2_z1_slice->SetMarkerColor(2);

TH2F* main_hole3_z1_slice = new TH2F("main_hole3_z1_slice", "Detector 28 Primary Hit With Hole 3 with Z less than -4890", 1000,-1500,-500,1000,-500,500);
main_hole3_z1_slice->GetXaxis()->SetTitle("Position in X");
main_hole3_z1_slice->GetYaxis()->SetTitle("Position in Y");
main_hole3_z1_slice->SetMarkerColor(3);


//polar angle
TH1F* polar_angle_z1 = new TH1F("polar_angle_z1","Polar Angle with Z less than -4890",100,0,30);
target_z->GetXaxis()->SetTitle("polar angle (rad)");
target_z->GetYaxis()->SetTitle("Events");
polar_angle_z1->SetLineColorAlpha(1, 0.35);

TH1F* hole1_polar_angle_z1 = new TH1F("hole1_polar_angle_z1","Hole 1 polar angle with Z less than -4890",100,0,30);
hole1_polar_angle_z1->GetXaxis()->SetTitle("polar angle (rad)");
hole1_polar_angle_z1->GetYaxis()->SetTitle("Events");
hole1_polar_angle_z1->SetLineColorAlpha(4, 0.7);

TH1F* hole2_polar_angle_z1 = new TH1F("hole2_polar_angle_z1","Hole 2 polar angle with Z less than -4890",100,0,30);
hole2_polar_angle_z1->GetXaxis()->SetTitle("polar angle (rad)");
hole2_polar_angle_z1->GetYaxis()->SetTitle("Events");
hole2_polar_angle_z1->SetLineColorAlpha(2, 0.7);

TH1F* hole3_polar_angle_z1 = new TH1F("hole3_polar_angle_z1","Hole 3 polar angle with Z less than -4890",100,0,30);
hole3_polar_angle_z1->GetXaxis()->SetTitle("polar angle (rad)");
hole3_polar_angle_z1->GetYaxis()->SetTitle("Events");
hole3_polar_angle_z1->SetLineColorAlpha(3, 0.7);


//Energy

TH1F* hole1_hite_z1 = new TH1F("hole1_hite_z1","Hole 1 Hit Energy Z less than -4890",200,0,10000);
hole1_hite_z1->GetXaxis()->SetTitle("Energy");
hole1_hite_z1->GetYaxis()->SetTitle("Events");
hole1_hite_z1->SetLineColorAlpha(4, 0.7);

TH1F* hole2_hite_z1 = new TH1F("hole2_hite_z1","Hole 2 Hit Energy Z less than -4890",200,0,10000);
hole2_hite_z1->GetXaxis()->SetTitle("Energy");
hole2_hite_z1->GetYaxis()->SetTitle("Events");
hole2_hite_z1->SetLineColorAlpha(2, 0.7);

TH1F* hole3_hite_z1 = new TH1F("hole3_hite_z1","Hole 3 Hit Energy Z less than -4890",200,0,10000);
hole3_hite_z1->GetXaxis()->SetTitle("Energy");
hole3_hite_z1->GetYaxis()->SetTitle("Events");
hole3_hite_z1->SetLineColorAlpha(3, 0.7);


TH1F* hite_z1 = new TH1F("hite_z1","Hit Energy Z less than -4890",200,0,10000);
hite_z1->GetXaxis()->SetTitle("Energy");
hite_z1->GetYaxis()->SetTitle("Events");
hite_z1->SetLineColorAlpha(1, 0.7);

//LAB FRAME AT MAIN Detector



//-----------------------------------------------------------------------------------------------------------------------------

//Z DEPENDANCE 2

TH1F* target_z2 = new TH1F("target_z2","Target Z between -4890 and -4630",200,-6000,-3000);
target_z2->GetXaxis()->SetTitle("Z in mm");
target_z2->GetYaxis()->SetTitle("Events");
target_z2->SetLineColorAlpha(2, 0.35);

TH2F* main_hole1_z2 = new TH2F("main_hole1_z2", "Detector 28 Primary Hit With Hole 1 with Z between -4890 and -4630", 1000,-2000,2000,1000,-2000,2000);
main_hole1_z2->GetXaxis()->SetTitle("Position in X");
main_hole1_z2->GetYaxis()->SetTitle("Position in Y");
main_hole1_z2->SetMarkerColorAlpha(4,0.7);

TH2F* main_hole2_z2 = new TH2F("main_hole2_z2", "Detector 28 Primary Hit With Hole 2 with Z between -4890 and -4630", 1000,-2000,2000,1000,-2000,2000);
main_hole2_z2->GetXaxis()->SetTitle("Position in X");
main_hole2_z2->GetYaxis()->SetTitle("Position in Y");
main_hole2_z2->SetMarkerColorAlpha(2,0.7);

TH2F* main_hole3_z2 = new TH2F("main_hole3_z2", "Detector 28 Primary Hit With Hole 3 with Z between -4890 and -4630", 1000,-2000,2000,1000,-2000,2000);
main_hole3_z2->GetXaxis()->SetTitle("Position in X");
main_hole3_z2->GetYaxis()->SetTitle("Position in Y");
main_hole3_z2->SetMarkerColorAlpha(3,0.7);


TH1F*  main_hole1_z2_r = new TH1F(" main_hole1_z2_r","Radial values Detector 28 Primary Hit With Hole 1 with Z between -4890 and -4630",400,600,1200);
main_hole1_z2_r->GetXaxis()->SetTitle("I am not sure");
main_hole1_z2_r->GetYaxis()->SetTitle("Really I should ask");
main_hole1_z2_r->SetLineColorAlpha(4, 0.35);

TH1F*  main_hole2_z2_r = new TH1F(" main_hole2_z2_r","Radial values Detector 28 Primary Hit With Hole 2 with Z between -4890 and -4630",400,600,1200);
main_hole2_z2_r->GetXaxis()->SetTitle("I am not sure");
main_hole2_z2_r->GetYaxis()->SetTitle("Really I should ask");
main_hole2_z2_r->SetLineColorAlpha(2, 0.35);

TH1F*  main_hole3_z2_r = new TH1F(" main_hole3_z2_r","Radial values Detector 28 Primary Hit With Hole 3 with Z between -4890 and -4630",400,600,1200);
main_hole3_z2_r->GetXaxis()->SetTitle("I am not sure");
main_hole3_z2_r->GetYaxis()->SetTitle("Really I should ask");
main_hole3_z2_r->SetLineColorAlpha(3, 0.35);


//Z DEPENDANCE SLICE

TH2F* main_hole1_z2_slice = new TH2F("main_hole1_z2_slice", "Detector 28 Primary Hit With Hole 1 with Z between -4890 and -4630", 1000,-1500,-500,1000,-500,500);
main_hole1_z2_slice->GetXaxis()->SetTitle("Position in X");
main_hole1_z2_slice->GetYaxis()->SetTitle("Position in Y");
main_hole1_z2_slice->SetMarkerColor(4);

TH2F* main_hole2_z2_slice = new TH2F("main_hole2_z2_slice", "Detector 28 Primary Hit With Hole 2 with Z between -4890 and -4630", 1000,-1500,-500,1000,-500,500);
main_hole2_z2_slice->GetXaxis()->SetTitle("Position in X");
main_hole2_z2_slice->GetYaxis()->SetTitle("Position in Y");
main_hole2_z2_slice->SetMarkerColor(2);

TH2F* main_hole3_z2_slice = new TH2F("main_hole3_z2_slice", "Detector 28 Primary Hit With Hole 3 with Z between -4890 and -4630", 1000,-1500,-500,1000,-500,500);
main_hole3_z2_slice->GetXaxis()->SetTitle("Position in X");
main_hole3_z2_slice->GetYaxis()->SetTitle("Position in Y");
main_hole3_z2_slice->SetMarkerColor(3);


//polar angle
TH1F* polar_angle_z2 = new TH1F("polar_angle_z2","Polar Angle with Z between -4890 and -4630",100,0,30);
target_z->GetXaxis()->SetTitle("polar angle (rad)");
target_z->GetYaxis()->SetTitle("Events");
polar_angle_z2->SetLineColorAlpha(2, 0.35);

TH1F* hole1_polar_angle_z2 = new TH1F("hole1_polar_angle_z2","Hole 1 polar angle with Z between -4890 and -4630",100,0,30);
hole1_polar_angle_z2->GetXaxis()->SetTitle("polar angle (rad)");
hole1_polar_angle_z2->GetYaxis()->SetTitle("Events");
hole1_polar_angle_z2->SetLineColorAlpha(4, 0.7);

TH1F* hole2_polar_angle_z2 = new TH1F("hole2_polar_angle_z2","Hole 2 polar angle with Z between -4890 and -4630",100,0,30);
hole2_polar_angle_z2->GetXaxis()->SetTitle("polar angle (rad)");
hole2_polar_angle_z2->GetYaxis()->SetTitle("Events");
hole2_polar_angle_z2->SetLineColorAlpha(2, 0.7);

TH1F* hole3_polar_angle_z2 = new TH1F("hole3_polar_angle_z2","Hole 3 polar angle with Z between -4890 and -4630",100,0,30);
hole3_polar_angle_z2->GetXaxis()->SetTitle("polar angle (rad)");
hole3_polar_angle_z2->GetYaxis()->SetTitle("Events");
hole3_polar_angle_z2->SetLineColorAlpha(3, 0.7);



//energy



TH1F* hole1_hite_z2 = new TH1F("hole1_hite_z2","Hole 1 Hit Energy Z between -4890 and -4630",200,0,10000);
hole1_hite_z2->GetXaxis()->SetTitle("Energy");
hole1_hite_z2->GetYaxis()->SetTitle("Events");
hole1_hite_z2->SetLineColorAlpha(4, 0.7);

TH1F* hole2_hite_z2 = new TH1F("hole2_hite_z2","Hole 2 Hit Energy Z between -4890 and -4630",200,0,10000);
hole2_hite_z2->GetXaxis()->SetTitle("Energy");
hole2_hite_z2->GetYaxis()->SetTitle("Events");
hole2_hite_z2->SetLineColorAlpha(2, 0.7);

TH1F* hole3_hite_z2 = new TH1F("hole3_hite_z2","Hole 3 Hit Energy Z between -4890 and -4630",200,0,10000);
hole3_hite_z2->GetXaxis()->SetTitle("Energy");
hole3_hite_z2->GetYaxis()->SetTitle("Events");
hole3_hite_z2->SetLineColorAlpha(3, 0.7);

TH1F* hite_z2 = new TH1F("hite_z2","Hit Energy Z between -4890 and -4630",200,0,10000);
hite_z2->GetXaxis()->SetTitle("Energy");
hite_z2->GetYaxis()->SetTitle("Events");
hite_z2->SetLineColorAlpha(2, 0.7);




//-----------------------------------------------------------------------------------------------------------------------------


//Z DEPENDANCE 3

TH1F* target_z3 = new TH1F("target_z3","Target Z between -4630 and -4370",200,-6000,-3000);
target_z3->GetXaxis()->SetTitle("Z in mm");
target_z3->GetYaxis()->SetTitle("Events");
target_z3->SetLineColorAlpha(3, 0.35);

TH2F* main_hole1_z3 = new TH2F("main_hole1_z3", "Detector 28 Primary Hit With Hole 1 with Z between -4630 and -4370", 1000,-2000,2000,1000,-2000,2000);
main_hole1_z3->GetXaxis()->SetTitle("Position in X");
main_hole1_z3->GetYaxis()->SetTitle("Position in Y");
main_hole1_z3->SetMarkerColorAlpha(4,0.7);

TH2F* main_hole2_z3 = new TH2F("main_hole2_z3", "Detector 28 Primary Hit With Hole 2 with Z between -4630 and -4370", 1000,-2000,2000,1000,-2000,2000);
main_hole2_z3->GetXaxis()->SetTitle("Position in X");
main_hole2_z3->GetYaxis()->SetTitle("Position in Y");
main_hole2_z3->SetMarkerColorAlpha(2,0.7);

TH2F* main_hole3_z3 = new TH2F("main_hole3_z3", "Detector 28 Primary Hit With Hole 3 with Z between -4630 and -4370", 1000,-2000,2000,1000,-2000,2000);
main_hole3_z3->GetXaxis()->SetTitle("Position in X");
main_hole3_z3->GetYaxis()->SetTitle("Position in Y");
main_hole3_z3->SetMarkerColorAlpha(3,0.7);


TH1F*  main_hole1_z3_r = new TH1F(" main_hole1_z3_r","Radial values Detector 28 Primary Hit With Hole 1 with Z between -4630 and -4370",400,600,1200);
main_hole1_z3_r->GetXaxis()->SetTitle("I am not sure");
main_hole1_z3_r->GetYaxis()->SetTitle("Really I should ask");
main_hole1_z3_r->SetLineColorAlpha(4, 0.35);

TH1F*  main_hole2_z3_r = new TH1F(" main_hole2_z3_r","Radial values Detector 28 Primary Hit With Hole 2 with Z between -4630 and -4370",400,600,1200);
main_hole2_z3_r->GetXaxis()->SetTitle("I am not sure");
main_hole2_z3_r->GetYaxis()->SetTitle("Really I should ask");
main_hole2_z3_r->SetLineColorAlpha(2, 0.35);

TH1F*  main_hole3_z3_r = new TH1F(" main_hole3_z3_r","Radial values Detector 28 Primary Hit With Hole 3 with Z between -4630 and -4370",400,600,1200);
main_hole3_z3_r->GetXaxis()->SetTitle("I am not sure");
main_hole3_z3_r->GetYaxis()->SetTitle("Really I should ask");
main_hole3_z3_r->SetLineColorAlpha(3, 0.35);


//Z DEPENDANCE SLICE

TH2F* main_hole1_z3_slice = new TH2F("main_hole1_z3_slice", "Detector 28 Primary Hit With Hole 1 with Z between -4630 and -4370", 1000,-1500,-500,1000,-500,500);
main_hole1_z3_slice->GetXaxis()->SetTitle("Position in X");
main_hole1_z3_slice->GetYaxis()->SetTitle("Position in Y");
main_hole1_z3_slice->SetMarkerColor(4);

TH2F* main_hole2_z3_slice = new TH2F("main_hole2_z3_slice", "Detector 28 Primary Hit With Hole 2 with Z between -4630 and -4370", 1000,-1500,-500,1000,-500,500);
main_hole2_z3_slice->GetXaxis()->SetTitle("Position in X");
main_hole2_z3_slice->GetYaxis()->SetTitle("Position in Y");
main_hole2_z3_slice->SetMarkerColor(2);

TH2F* main_hole3_z3_slice = new TH2F("main_hole3_z3_slice", "Detector 28 Primary Hit With Hole 3 with Z between -4630 and -4370", 1000,-1500,-500,1000,-500,500);
main_hole3_z3_slice->GetXaxis()->SetTitle("Position in X");
main_hole3_z3_slice->GetYaxis()->SetTitle("Position in Y");
main_hole3_z3_slice->SetMarkerColor(3);


//polar angle
TH1F* polar_angle_z3 = new TH1F("polar_angle_z3","Polar Angle with Z between -4630 and -4370",100,0,30);
target_z->GetXaxis()->SetTitle("polar angle (rad)");
target_z->GetYaxis()->SetTitle("Events");
polar_angle_z3->SetLineColorAlpha(3, 0.35);

TH1F* hole1_polar_angle_z3 = new TH1F("hole1_polar_angle_z3","Hole 1 polar angle with Z between -4630 and -4370",100,0,30);
hole1_polar_angle_z3->GetXaxis()->SetTitle("polar angle (rad)");
hole1_polar_angle_z3->GetYaxis()->SetTitle("Events");
hole1_polar_angle_z3->SetLineColorAlpha(4, 0.7);

TH1F* hole2_polar_angle_z3 = new TH1F("hole2_polar_angle_z3","Hole 2 polar angle with Z between -4630 and -4370",100,0,30);
hole2_polar_angle_z3->GetXaxis()->SetTitle("polar angle (rad)");
hole2_polar_angle_z3->GetYaxis()->SetTitle("Events");
hole2_polar_angle_z3->SetLineColorAlpha(2, 0.7);

TH1F* hole3_polar_angle_z3 = new TH1F("hole3_polar_angle_z3","Hole 3 polar angle with Z between -4630 and -4370",100,0,30);
hole3_polar_angle_z3->GetXaxis()->SetTitle("polar angle (rad)");
hole3_polar_angle_z3->GetYaxis()->SetTitle("Events");
hole3_polar_angle_z3->SetLineColorAlpha(3, 0.7);


//energy


TH1F* hole1_hite_z3 = new TH1F("hole1_hite_z3","Hole 1 Hit Energy Z between -4630 and -4370",200,0,10000);
hole1_hite_z3->GetXaxis()->SetTitle("Energy");
hole1_hite_z3->GetYaxis()->SetTitle("Events");
hole1_hite_z3->SetLineColorAlpha(4, 0.7);

TH1F* hole2_hite_z3 = new TH1F("hole2_hite_z3","Hole 2 Hit Energy Z between -4630 and -4370",200,0,10000);
hole2_hite_z3->GetXaxis()->SetTitle("Energy");
hole2_hite_z3->GetYaxis()->SetTitle("Events");
hole2_hite_z3->SetLineColorAlpha(2, 0.7);

TH1F* hole3_hite_z3 = new TH1F("hole3_hite_z3","Hole 3 Hit Energy Z between -4630 and -4370",200,0,10000);
hole3_hite_z3->GetXaxis()->SetTitle("Energy");
hole3_hite_z3->GetYaxis()->SetTitle("Events");
hole3_hite_z3->SetLineColorAlpha(3, 0.7);

TH1F* hite_z3 = new TH1F("hite_z3","Hit Energy Z between -4630 and -4370",200,0,10000);
hite_z3->GetXaxis()->SetTitle("Energy");
hite_z3->GetYaxis()->SetTitle("Events");
hite_z3->SetLineColorAlpha(3, 0.7);




//-----------------------------------------------------------------------------------------------------------------------------


//Z DEPENDANCE 4

TH1F* target_z4 = new TH1F("target_z4","Target Z between -4370 and -4110",200,-6000,-3000);
target_z4->GetXaxis()->SetTitle("Z in mm");
target_z4->GetYaxis()->SetTitle("Events");
target_z4->SetLineColorAlpha(4, 0.35);

TH2F* main_hole1_z4 = new TH2F("main_hole1_z4", "Detector 28 Primary Hit With Hole 1 with Z between -4370 and -4110", 1000,-2000,2000,1000,-2000,2000);
main_hole1_z4->GetXaxis()->SetTitle("Position in X");
main_hole1_z4->GetYaxis()->SetTitle("Position in Y");
main_hole1_z4->SetMarkerColorAlpha(4,0.7);

TH2F* main_hole2_z4 = new TH2F("main_hole2_z4", "Detector 28 Primary Hit With Hole 2 with Z between -4370 and -4110", 1000,-2000,2000,1000,-2000,2000);
main_hole2_z4->GetXaxis()->SetTitle("Position in X");
main_hole2_z4->GetYaxis()->SetTitle("Position in Y");
main_hole2_z4->SetMarkerColorAlpha(2,0.7);

TH2F* main_hole3_z4 = new TH2F("main_hole3_z4", "Detector 28 Primary Hit With Hole 3 with Z between -4370 and -4110", 1000,-2000,2000,1000,-2000,2000);
main_hole3_z4->GetXaxis()->SetTitle("Position in X");
main_hole3_z4->GetYaxis()->SetTitle("Position in Y");
main_hole3_z4->SetMarkerColorAlpha(3,0.7);


TH1F*  main_hole1_z4_r = new TH1F(" main_hole1_z4_r","Radial values Detector 28 Primary Hit With Hole 1 with Z between -4370 and -4110",400,600,1200);
main_hole1_z4_r->GetXaxis()->SetTitle("I am not sure");
main_hole1_z4_r->GetYaxis()->SetTitle("Really I should ask");
main_hole1_z4_r->SetLineColorAlpha(4, 0.35);

TH1F*  main_hole2_z4_r = new TH1F(" main_hole2_z4_r","Radial values Detector 28 Primary Hit With Hole 2 with Z between -4370 and -4110",400,600,1200);
main_hole2_z4_r->GetXaxis()->SetTitle("I am not sure");
main_hole2_z4_r->GetYaxis()->SetTitle("Really I should ask");
main_hole2_z4_r->SetLineColorAlpha(2, 0.35);

TH1F*  main_hole3_z4_r = new TH1F(" main_hole3_z4_r","Radial values Detector 28 Primary Hit With Hole 3 with Z between -4370 and -4110",400,600,1200);
main_hole3_z4_r->GetXaxis()->SetTitle("I am not sure");
main_hole3_z4_r->GetYaxis()->SetTitle("Really I should ask");
main_hole3_z4_r->SetLineColorAlpha(3, 0.35);


//Z DEPENDANCE SLICE

TH2F* main_hole1_z4_slice = new TH2F("main_hole1_z4_slice", "Detector 28 Primary Hit With Hole 1 with Z between -4370 and -4110", 1000,-1500,-500,1000,-500,500);
main_hole1_z4_slice->GetXaxis()->SetTitle("Position in X");
main_hole1_z4_slice->GetYaxis()->SetTitle("Position in Y");
main_hole1_z4_slice->SetMarkerColor(4);

TH2F* main_hole2_z4_slice = new TH2F("main_hole2_z4_slice", "Detector 28 Primary Hit With Hole 2 with Z between -4370 and -4110", 1000,-1500,-500,1000,-500,500);
main_hole2_z4_slice->GetXaxis()->SetTitle("Position in X");
main_hole2_z4_slice->GetYaxis()->SetTitle("Position in Y");
main_hole2_z4_slice->SetMarkerColor(2);

TH2F* main_hole3_z4_slice = new TH2F("main_hole3_z4_slice", "Detector 28 Primary Hit With Hole 3 with Z between -4370 and -4110", 1000,-1500,-500,1000,-500,500);
main_hole3_z4_slice->GetXaxis()->SetTitle("Position in X");
main_hole3_z4_slice->GetYaxis()->SetTitle("Position in Y");
main_hole3_z4_slice->SetMarkerColor(3);


//polar angle
TH1F* polar_angle_z4 = new TH1F("polar_angle_z4","Polar Angle with Z between -4370 and -4110",100,0,30);
target_z->GetXaxis()->SetTitle("polar angle (rad)");
target_z->GetYaxis()->SetTitle("Events");
polar_angle_z4->SetLineColorAlpha(4, 0.35);

TH1F* hole1_polar_angle_z4 = new TH1F("hole1_polar_angle_z4","Hole 1 polar angle with Z between -4370 and -4110",100,0,30);
hole1_polar_angle_z4->GetXaxis()->SetTitle("polar angle (rad)");
hole1_polar_angle_z4->GetYaxis()->SetTitle("Events");
hole1_polar_angle_z4->SetLineColorAlpha(4, 0.7);

TH1F* hole2_polar_angle_z4 = new TH1F("hole2_polar_angle_z4","Hole 2 polar angle with Z between -4370 and -4110",100,0,30);
hole2_polar_angle_z4->GetXaxis()->SetTitle("polar angle (rad)");
hole2_polar_angle_z4->GetYaxis()->SetTitle("Events");
hole2_polar_angle_z4->SetLineColorAlpha(2, 0.7);

TH1F* hole3_polar_angle_z4 = new TH1F("hole3_polar_angle_z4","Hole 3 polar angle with Z between -4370 and -4110",100,0,30);
hole3_polar_angle_z4->GetXaxis()->SetTitle("polar angle (rad)");
hole3_polar_angle_z4->GetYaxis()->SetTitle("Events");
hole3_polar_angle_z4->SetLineColorAlpha(3, 0.7);



//Energy


TH1F* hole1_hite_z4 = new TH1F("hole1_hite_z4","Hole 1 Hit Energy Z between -4370 and -4110",200,0,10000);
hole1_hite_z4->GetXaxis()->SetTitle("Energy");
hole1_hite_z4->GetYaxis()->SetTitle("Events");
hole1_hite_z4->SetLineColorAlpha(4, 0.7);

TH1F* hole2_hite_z4 = new TH1F("hole2_hite_z4","Hole 2 Hit Energy Z between -4370 and -4110",200,0,10000);
hole2_hite_z4->GetXaxis()->SetTitle("Energy");
hole2_hite_z4->GetYaxis()->SetTitle("Events");
hole2_hite_z4->SetLineColorAlpha(2, 0.7);

TH1F* hole3_hite_z4 = new TH1F("hole3_hite_z4","Hole 3 Hit Energy Z between -4370 and -4110",200,0,10000);
hole3_hite_z4->GetXaxis()->SetTitle("Energy");
hole3_hite_z4->GetYaxis()->SetTitle("Events");
hole3_hite_z4->SetLineColorAlpha(3, 0.7);

TH1F* hite_z4 = new TH1F("hite_z4","Hit Energy Z between -4370 and -4110",200,0,10000);
hite_z4->GetXaxis()->SetTitle("Energy");
hite_z4->GetYaxis()->SetTitle("Events");
hite_z4->SetLineColorAlpha(4, 0.7);




//-----------------------------------------------------------------------------------------------------------------------------



//Z DEPENDANCE 5

TH1F* target_z5 = new TH1F("target_z5","Target Z between -4110 and -3850",200,-6000,-3000);
target_z5->GetXaxis()->SetTitle("Z in mm");
target_z5->GetYaxis()->SetTitle("Events");
target_z5->SetLineColorAlpha(5, 0.35);

TH2F* main_hole1_z5 = new TH2F("main_hole1_z5", "Detector 28 Primary Hit With Hole 1 with Z between -4110 and -3850", 1000,-2000,2000,1000,-2000,2000);
main_hole1_z5->GetXaxis()->SetTitle("Position in X");
main_hole1_z5->GetYaxis()->SetTitle("Position in Y");
main_hole1_z5->SetMarkerColorAlpha(4,0.7);

TH2F* main_hole2_z5 = new TH2F("main_hole2_z5", "Detector 28 Primary Hit With Hole 2 with Z between -4110 and -3850", 1000,-2000,2000,1000,-2000,2000);
main_hole2_z5->GetXaxis()->SetTitle("Position in X");
main_hole2_z5->GetYaxis()->SetTitle("Position in Y");
main_hole2_z5->SetMarkerColorAlpha(2,0.7);

TH2F* main_hole3_z5 = new TH2F("main_hole3_z5", "Detector 28 Primary Hit With Hole 3 with Z between -4110 and -3850", 1000,-2000,2000,1000,-2000,2000);
main_hole3_z5->GetXaxis()->SetTitle("Position in X");
main_hole3_z5->GetYaxis()->SetTitle("Position in Y");
main_hole3_z5->SetMarkerColorAlpha(3,0.7);


TH1F*  main_hole1_z5_r = new TH1F(" main_hole1_z5_r","Radial values Detector 28 Primary Hit With Hole 1 with Z between -4110 and -3850",400,600,1200);
main_hole1_z5_r->GetXaxis()->SetTitle("I am not sure");
main_hole1_z5_r->GetYaxis()->SetTitle("Really I should ask");
main_hole1_z5_r->SetLineColorAlpha(4, 0.35);

TH1F*  main_hole2_z5_r = new TH1F(" main_hole2_z5_r","Radial values Detector 28 Primary Hit With Hole 2 with Z between -4110 and -3850",400,600,1200);
main_hole2_z5_r->GetXaxis()->SetTitle("I am not sure");
main_hole2_z5_r->GetYaxis()->SetTitle("Really I should ask");
main_hole2_z5_r->SetLineColorAlpha(2, 0.35);

TH1F*  main_hole3_z5_r = new TH1F(" main_hole3_z5_r","Radial values Detector 28 Primary Hit With Hole 3 with Z between -4110 and -3850",400,600,1200);
main_hole3_z5_r->GetXaxis()->SetTitle("I am not sure");
main_hole3_z5_r->GetYaxis()->SetTitle("Really I should ask");
main_hole3_z5_r->SetLineColorAlpha(3, 0.35);


//Z DEPENDANCE SLICE

TH2F* main_hole1_z5_slice = new TH2F("main_hole1_z5_slice", "Detector 28 Primary Hit With Hole 1 with Z between -4110 and -3850", 1000,-1500,-500,1000,-500,500);
main_hole1_z5_slice->GetXaxis()->SetTitle("Position in X");
main_hole1_z5_slice->GetYaxis()->SetTitle("Position in Y");
main_hole1_z5_slice->SetMarkerColor(4);

TH2F* main_hole2_z5_slice = new TH2F("main_hole2_z5_slice", "Detector 28 Primary Hit With Hole 2 with Z between -4110 and -3850", 1000,-1500,-500,1000,-500,500);
main_hole2_z5_slice->GetXaxis()->SetTitle("Position in X");
main_hole2_z5_slice->GetYaxis()->SetTitle("Position in Y");
main_hole2_z5_slice->SetMarkerColor(2);

TH2F* main_hole3_z5_slice = new TH2F("main_hole3_z5_slice", "Detector 28 Primary Hit With Hole 3 with Z between -4110 and -3850", 1000,-1500,-500,1000,-500,500);
main_hole3_z5_slice->GetXaxis()->SetTitle("Position in X");
main_hole3_z5_slice->GetYaxis()->SetTitle("Position in Y");
main_hole3_z5_slice->SetMarkerColor(3);


//polar angle
TH1F* polar_angle_z5 = new TH1F("polar_angle_z5","Polar Angle with Z between -4110 and -3850",100,0,30);
target_z->GetXaxis()->SetTitle("polar angle (rad)");
target_z->GetYaxis()->SetTitle("Events");
polar_angle_z5->SetLineColorAlpha(5, 0.35);

TH1F* hole1_polar_angle_z5 = new TH1F("hole1_polar_angle_z5","Hole 1 polar angle with Z between -4110 and -3850",100,0,30);
hole1_polar_angle_z5->GetXaxis()->SetTitle("polar angle (rad)");
hole1_polar_angle_z5->GetYaxis()->SetTitle("Events");
hole1_polar_angle_z5->SetLineColorAlpha(4, 0.7);

TH1F* hole2_polar_angle_z5 = new TH1F("hole2_polar_angle_z5","Hole 2 polar angle with Z between -4110 and -3850",100,0,30);
hole2_polar_angle_z5->GetXaxis()->SetTitle("polar angle (rad)");
hole2_polar_angle_z5->GetYaxis()->SetTitle("Events");
hole2_polar_angle_z5->SetLineColorAlpha(2, 0.7);

TH1F* hole3_polar_angle_z5 = new TH1F("hole3_polar_angle_z5","Hole 3 polar angle with Z between -4110 and -3850",100,0,30);
hole3_polar_angle_z5->GetXaxis()->SetTitle("polar angle (rad)");
hole3_polar_angle_z5->GetYaxis()->SetTitle("Events");
hole3_polar_angle_z5->SetLineColorAlpha(3, 0.7);


//energy


TH1F* hole1_hite_z5 = new TH1F("hole1_hite_z5","Hole 1 Hit Energy Z between -4110 and -3850",200,0,10000);
hole1_hite_z5->GetXaxis()->SetTitle("Energy");
hole1_hite_z5->GetYaxis()->SetTitle("Events");
hole1_hite_z5->SetLineColorAlpha(4, 0.7);

TH1F* hole2_hite_z5 = new TH1F("hole2_hite_z5","Hole 2 Hit Energy Z between -4110 and -3850",200,0,10000);
hole2_hite_z5->GetXaxis()->SetTitle("Energy");
hole2_hite_z5->GetYaxis()->SetTitle("Events");
hole2_hite_z5->SetLineColorAlpha(2, 0.7);

TH1F* hole3_hite_z5 = new TH1F("hole3_hite_z5","Hole 3 Hit Energy Z between -4110 and -3850",200,0,10000);
hole3_hite_z5->GetXaxis()->SetTitle("Energy");
hole3_hite_z5->GetYaxis()->SetTitle("Events");
hole3_hite_z5->SetLineColorAlpha(3, 0.7);

TH1F* hite_z5 = new TH1F("hite_z5","Hit Energy Z between -4110 and -3850",200,0,10000);
hite_z5->GetXaxis()->SetTitle("Energy");
hite_z5->GetYaxis()->SetTitle("Events");
hite_z5->SetLineColorAlpha(5, 0.7);











// define logical flag that hole 1/2/3 was hit

bool hole_1 = false;
bool hole_2 = false;
bool hole_3 = false;


// Loop over all events
for (size_t iev = 0; iev < T->GetEntries(); iev++) {
  T->GetEntry(iev);

  hole_1 = false;
  hole_2 = false;
  hole_3 = false;

  //   cout << "vertex z" << bm->z << endl;
  target_z->Fill(bm->z);
  for (size_t ipart = 0; ipart < parts->size(); ipart++) {
      remollEventParticle_t  part = parts->at(ipart);

  polar_angle->Fill(1000*part.th, rate);
          }


  // Process hits: loop over all the hits in this event

for (size_t ihit = 0; ihit < hits->size(); ihit++) {
    remollGenericDetectorHit_t hit = hits->at(ihit);


    if ((hit.det == 28 && hit.trid == 1) || (hit.det == 28 && hit.trid == 2)) {
      maindet_2D->Fill(hit.x,hit.y, rate);
      maindet_2D_slice->Fill(hit.x,hit.y, rate);
      maindet_1D_square->Fill(hit.r, rate);
      maindet_1D->Fill(hit.x, rate);
      hit_e->Fill(hit.e, rate);
        if(bm->z < -4890){
          target_z1->Fill(bm->z);
          for (size_t ipart = 0; ipart < parts->size(); ipart++) {
              remollEventParticle_t  part = parts->at(ipart);
          if(part.trid==hit.trid){
          polar_angle_z1->Fill(1000*part.th, rate);}}
          hite_z1->Fill(hit.e, rate);
        }
        if(bm->z > -4890 && bm->z < -4630){
          target_z2->Fill(bm->z);
          for (size_t ipart = 0; ipart < parts->size(); ipart++) {
              remollEventParticle_t  part = parts->at(ipart);
          if(part.trid==hit.trid){
          polar_angle_z2->Fill(1000*part.th, rate);} }
          hite_z2->Fill(hit.e, rate);
        }
        if(bm->z > -4630 && bm->z <-4370){
          target_z3->Fill(bm->z);
          for (size_t ipart = 0; ipart < parts->size(); ipart++) {
              remollEventParticle_t  part = parts->at(ipart);
          if(part.trid==hit.trid){
          polar_angle_z3->Fill(1000*part.th, rate);}}
          hite_z3->Fill(hit.e, rate);
        }
        if(bm->z >-4370 && bm->z <-4110){
          target_z4->Fill(bm->z);
          for (size_t ipart = 0; ipart < parts->size(); ipart++) {
              remollEventParticle_t  part = parts->at(ipart);
          if(part.trid==hit.trid){
          polar_angle_z4->Fill(1000*part.th, rate);}}
          hite_z4->Fill(hit.e, rate);
        }
        if(bm->z >-4110 && bm->z <-3850){
          target_z5->Fill(bm->z);
          for (size_t ipart = 0; ipart < parts->size(); ipart++) {
              remollEventParticle_t  part = parts->at(ipart);
          if(part.trid==hit.trid){
          polar_angle_z5->Fill(1000*part.th, rate);}}
          hite_z5->Fill(hit.e, rate);
        }
        if(hit.e>500){
          maindet_2D_energy_500_above->Fill(hit.x,hit.y, rate);
        }
        if(hit.e<500){
          maindet_2D_energy_500_below->Fill(hit.x,hit.y, rate);
        }
    } //end if statement

    //    cout << "hit.det hit.tr<id" << hit.det << "  " << hit.trid <<endl;
    if ((hit.det == 1001 && hit.trid == 1) || (hit.det == 1001 && hit.trid == 2)) {
      hole_1 = true;
    }
    if ((hit.det == 1002 && hit.trid == 1) || (hit.det == 1002 && hit.trid == 2)) {
      hole_2 = true;
      }
    if ((hit.det == 1003 && hit.trid == 1) || (hit.det == 1003 && hit.trid == 2)) {
      hole_3 = true;
      }

  } //end loop over hits




  // Process hits again
  for (size_t ihit = 0; ihit < hits->size(); ihit++) {
    remollGenericDetectorHit_t hit = hits->at(ihit);
    if ((hit.det == 28 && hole_1 && hit.trid==1)||(hit.det == 28 && hole_1 && hit.trid==2)) {
      // hits main detector and has passes through hole 1
      main_hole1 -> Fill(hit.x,hit.y, rate);
      main_hole1_slice->Fill(hit.x,hit.y, rate);
      maindet_1D_square_hole1->Fill(hit.r, rate);
      for (size_t ipart = 0; ipart < parts->size(); ipart++) {
          remollEventParticle_t  part = parts->at(ipart);
      if(part.trid==hit.trid){
      hole1_polar_angle ->Fill(1000*part.th, rate);}}
      //hits within z region
      if ( bm->z < -4890){
        main_hole1_z1->Fill(hit.x,hit.y, rate);
        main_hole1_z1_slice->Fill(hit.x,hit.y, rate);
        main_hole1_z1_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole1_polar_angle_z1->Fill(1000*part.th, rate); }}
        hole1_hite_z1->Fill(hit.e, rate);
      }//end z1 if statment
      if ( bm->z > -4890 && bm->z < -4630){
        main_hole1_z2->Fill(hit.x,hit.y, rate);
        main_hole1_z2_slice->Fill(hit.x,hit.y, rate);
        main_hole1_z2_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole1_polar_angle_z2->Fill(1000*part.th, rate);}}
        hole1_hite_z2->Fill(hit.e, rate);
      }//end z2 if statment
      if ( bm->z > -4630 && bm->z <-4370){
        main_hole1_z3->Fill(hit.x,hit.y, rate);
        main_hole1_z3_slice->Fill(hit.x,hit.y, rate);
        main_hole1_z3_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole1_polar_angle_z3->Fill(1000*part.th, rate);}}
        hole1_hite_z3->Fill(hit.e, rate);
      }//end z3 if statment
      if ( bm->z >-4370 && bm->z <-4110){
        main_hole1_z4->Fill(hit.x,hit.y, rate);
        main_hole1_z4_slice->Fill(hit.x,hit.y, rate);
        main_hole1_z4_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole1_polar_angle_z4->Fill(1000*part.th, rate);}}
        hole1_hite_z4->Fill(hit.e, rate);
      }//end z4 if statment
      if ( bm->z >-4110 && bm->z <-3850){
        main_hole1_z5->Fill(hit.x,hit.y, rate);
        main_hole1_z5_slice->Fill(hit.x,hit.y, rate);
        main_hole1_z5_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole1_polar_angle_z5->Fill(1000*part.th, rate);}}
        hole1_hite_z5->Fill(hit.e, rate);
      }//end z5 if statment
    }


    if ((hit.det == 28 && hole_2 && hit.trid==1)||(hit.det == 28 && hole_2 && hit.trid==2)) {
      // hits main detector and has passes through hole 2
      main_hole2 -> Fill(hit.x,hit.y, rate);
      main_hole2_slice->Fill(hit.x,hit.y, rate);
      maindet_1D_square_hole2->Fill(hit.r, rate);
      for (size_t ipart = 0; ipart < parts->size(); ipart++) {
          remollEventParticle_t  part = parts->at(ipart);
      if(part.trid==hit.trid){
      hole2_polar_angle ->Fill(1000*part.th, rate);}}
      //hits within z region
      if ( bm->z < -4890){
        main_hole2_z1->Fill(hit.x,hit.y, rate);
        main_hole2_z1_slice->Fill(hit.x,hit.y, rate);
        main_hole2_z1_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole2_polar_angle_z1->Fill(1000*part.th, rate);}}
        hole2_hite_z1->Fill(hit.e, rate);
      }//end z1 if statment
      if ( bm->z > -4890 && bm->z < -4630){
        main_hole2_z2->Fill(hit.x,hit.y, rate);
        main_hole2_z2_slice->Fill(hit.x,hit.y, rate);
        main_hole2_z2_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole2_polar_angle_z2->Fill(1000*part.th, rate);}}
        hole2_hite_z2->Fill(hit.e, rate);
      }//end z2 if statment
      if ( bm->z > -4630 && bm->z <-4370){
        main_hole2_z3->Fill(hit.x,hit.y, rate);
        main_hole2_z3_slice->Fill(hit.x,hit.y, rate);
        main_hole2_z3_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole2_polar_angle_z3->Fill(1000*part.th, rate);}}
        hole2_hite_z3->Fill(hit.e, rate);
      }//end z3 if statment
      if (bm->z >-4370 && bm->z <-4110){
        main_hole2_z4->Fill(hit.x,hit.y, rate);
        main_hole2_z4_slice->Fill(hit.x,hit.y, rate);
        main_hole2_z4_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole2_polar_angle_z4->Fill(1000*part.th, rate);}}
        hole2_hite_z4->Fill(hit.e, rate);
      }//end z4 if statment
      if (bm->z >-4110 && bm->z <-3850){
        main_hole2_z5->Fill(hit.x,hit.y, rate);
        main_hole2_z5_slice->Fill(hit.x,hit.y, rate);
        main_hole2_z5_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole2_polar_angle_z5->Fill(1000*part.th, rate);}}
        hole2_hite_z5->Fill(hit.e, rate);
      }//end z5 if statment
    }


    if ((hit.det == 28 && hole_3 && hit.trid==1)||(hit.det == 28 && hole_3 && hit.trid==2)) {
      // hits main detector and has passes through hole 3
      main_hole3 -> Fill(hit.x,hit.y, rate);
      main_hole3_slice->Fill(hit.x,hit.y, rate);
      maindet_1D_square_hole3->Fill(hit.r, rate);
      for (size_t ipart = 0; ipart < parts->size(); ipart++) {
          remollEventParticle_t  part = parts->at(ipart);
      if(part.trid==hit.trid){
      hole3_polar_angle ->Fill(1000*part.th, rate);}}
      //hits within z region
      if ( bm->z < -4890){
        main_hole3_z1->Fill(hit.x,hit.y, rate);
        main_hole3_z1_slice->Fill(hit.x,hit.y, rate);
        main_hole3_z1_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole3_polar_angle_z1->Fill(1000*part.th, rate);}}
        hole3_hite_z1->Fill(hit.e, rate);
      }//end z1 if statment
      if ( bm->z > -4890 && bm->z < -4630){
        main_hole3_z2->Fill(hit.x,hit.y, rate);
        main_hole3_z2_slice->Fill(hit.x,hit.y, rate);
        main_hole3_z2_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole3_polar_angle_z2->Fill(1000*part.th, rate);}}
        hole3_hite_z2->Fill(hit.e, rate);
      }//end z2 if statment
      if ( bm->z > -4630 && bm->z <-4370){
        main_hole3_z3->Fill(hit.x,hit.y, rate);
        main_hole3_z3_slice->Fill(hit.x,hit.y, rate);
        main_hole3_z3_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole3_polar_angle_z3->Fill(1000*part.th, rate);}}
        hole3_hite_z3->Fill(hit.e, rate);
      }//end z3 if statment
      if ( bm->z >-4370 && bm->z <-4110){
        main_hole3_z4->Fill(hit.x,hit.y, rate);
        main_hole3_z4_slice->Fill(hit.x,hit.y, rate);
        main_hole3_z4_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole3_polar_angle_z4->Fill(1000*part.th, rate);}}
        hole3_hite_z4->Fill(hit.e, rate);
      }//end z4 if statment
      if ( bm->z >-4110 && bm->z <-3850){
        main_hole3_z5->Fill(hit.x,hit.y, rate);
        main_hole3_z5_slice->Fill(hit.x,hit.y, rate);
        main_hole3_z5_r->Fill(hit.r, rate);
        for (size_t ipart = 0; ipart < parts->size(); ipart++) {
            remollEventParticle_t  part = parts->at(ipart);
        if(part.trid==hit.trid){
        hole3_polar_angle_z5->Fill(1000*part.th, rate);}}
        hole3_hite_z5->Fill(hit.e, rate);
      }//end z5 if statment
    }

  }  // end 2nd loop over hits

}    //end loop over events


//----------------------------------------------------------------------
  // Draw and save the histograms into png files in images subdirectory
  //   demonstrates dividing a canvas so multiple plots on one canvas



  TCanvas *c4 = new TCanvas("c4","Standard Plots");
  c4->Divide(2,3);
  c4->cd(1);
  maindet_1D->Draw();
  c4->cd(2);
    maindet_1D_square->Draw();
  c4->cd(3);
  maindet_2D->Draw();
  c4->cd(4);
  maindet_2D->Draw("COLZ");
  c4->cd(5);
  maindet_2D_slice->Draw();
  c4->cd(6);
  maindet_2D_slice->Draw("COLZ");
  c4->Print("remoll_plots_01_newpos.png");
  delete c4;


  TCanvas *c6 = new TCanvas("c6","Hole Plots");
  c6->Divide(2,2);
  c6->cd(1);
  main_hole1->Draw();
  c6->cd(2);
  main_hole2->Draw();
  c6->cd(3);
  main_hole3->Draw();
  c6->cd(4);
  main_hole1->Draw();
  main_hole3->Draw("SAME");
  main_hole2->Draw("SAME");
  c6->Print("remoll_plots_holes_01_newpos.png");
  delete c6;

  TCanvas *c5 = new TCanvas("c5","Hole Plots Slice");
  c5->Divide(2,2);
  c5->cd(1);
  main_hole1_slice->Draw();
  c5->cd(2);
  main_hole2_slice->Draw();
  c5->cd(3);
  main_hole3_slice->Draw();
  c5->cd(4);
  main_hole1_slice->Draw();
  main_hole3_slice->Draw("SAME");
  main_hole2_slice->Draw("SAME");
  c5->Print("remoll_plots_holes_slice_01_newpos.png");
  delete c5;

  TCanvas *c3 = new TCanvas("c3","Hole Plots Square");
  c3->Divide(2,2);
  c3->cd(1);
  maindet_1D_square_hole1->Draw();
  c3->cd(2);
  maindet_1D_square_hole2->Draw();
  c3->cd(3);
  maindet_1D_square_hole3->Draw();
  c3->cd(4);
  maindet_1D_square_hole1->Draw();
  maindet_1D_square_hole3->Draw("SAME");
  maindet_1D_square_hole2->Draw("SAME");
  c3->Print("remoll_plots_holes_square_01_newpos.png");
  delete c3;

  TCanvas *c2 = new TCanvas("c2","Hole Plots polar angle");
  c2->Divide(2,2);
  c2->cd(1);
  hole1_polar_angle->Draw();
  c2->cd(2);
  hole2_polar_angle->Draw();
  c2->cd(3);
  hole3_polar_angle->Draw();
  c2->cd(4);
  hole1_polar_angle->Draw();
  hole3_polar_angle->Draw("SAME");
  hole2_polar_angle->Draw("SAME");
  c2->Print("remoll_plots_holes_polar_angle_01_newpos.png");
  delete c2;


  TCanvas *c7 = new TCanvas("c7","Z1 hole plots");
  c7->Divide(2,2);
  c7->cd(1);
  main_hole1_z1->Draw();
  c7->cd(2);
  main_hole2_z1->Draw();
  c7->cd(3);
  main_hole3_z1->Draw();
  c7->cd(4);
  main_hole1_z1->Draw();
  main_hole3_z1->Draw("SAME");
  main_hole2_z1->Draw("SAME");
  c7->Print("remoll_plots_holes_z1_01_newpos.png");
  delete c7;

  TCanvas *c72 = new TCanvas("c72","Z2 hole plots");
  c72->Divide(2,2);
  c72->cd(1);
  main_hole1_z2->Draw();
  c72->cd(2);
  main_hole2_z2->Draw();
  c72->cd(3);
  main_hole3_z2->Draw();
  c72->cd(4);
  main_hole1_z2->Draw();
  main_hole3_z2->Draw("SAME");
  main_hole2_z2->Draw("SAME");
  c72->Print("remoll_plots_holes_z2_01_newpos.png");
  delete c72;

  TCanvas *c73 = new TCanvas("c73","Z3 hole plots");
  c73->Divide(2,2);
  c73->cd(1);
  main_hole1_z3->Draw();
  c73->cd(2);
  main_hole2_z3->Draw();
  c73->cd(3);
  main_hole3_z3->Draw();
  c73->cd(4);
  main_hole1_z3->Draw();
  main_hole3_z3->Draw("SAME");
  main_hole2_z3->Draw("SAME");
  c73->Print("remoll_plots_holes_z3_01_newpos.png");
  delete c73;

  TCanvas *c74 = new TCanvas("c74","Z4 hole plots");
  c74->Divide(2,2);
  c74->cd(1);
  main_hole1_z4->Draw();
  c74->cd(2);
  main_hole2_z4->Draw();
  c74->cd(3);
  main_hole3_z4->Draw();
  c74->cd(4);
  main_hole1_z4->Draw();
  main_hole3_z4->Draw("SAME");
  main_hole2_z4->Draw("SAME");
  c74->Print("remoll_plots_holes_z4_01_newpos.png");
  delete c74;

  TCanvas *c75 = new TCanvas("c75","Z5 hole plots");
  c75->Divide(2,2);
  c75->cd(1);
  main_hole1_z5->Draw();
  c75->cd(2);
  main_hole2_z5->Draw();
  c75->cd(3);
  main_hole3_z5->Draw();
  c75->cd(4);
  main_hole1_z5->Draw();
  main_hole3_z5->Draw("SAME");
  main_hole2_z5->Draw("SAME");
  c75->Print("remoll_plots_holes_z5_01_newpos.png");
  delete c75;



  TCanvas *c8 = new TCanvas("c8","Z1 square hole plots");
  c8->Divide(2,2);
  c8->cd(1);
  main_hole1_z1_r->Draw();
  c8->cd(2);
  main_hole2_z1_r->Draw();
  c8->cd(3);
  main_hole3_z1_r->Draw();
  c8->cd(4);
  main_hole1_z1_r->Draw();
  main_hole3_z1_r->Draw("SAME");
  main_hole2_z1_r->Draw("SAME");
  gPad->BuildLegend();
  c8->Print("remoll_plots_holes_z1_r_01_newpos.png");
  delete c8;

  TCanvas *c81 = new TCanvas("c81","Z2 square hole plots");
  c81->Divide(2,2);
  c81->cd(1);
  main_hole1_z2_r->Draw();
  c81->cd(2);
  main_hole2_z2_r->Draw();
  c81->cd(3);
  main_hole3_z2_r->Draw();
  c81->cd(4);
  main_hole1_z2_r->Draw();
  main_hole3_z2_r->Draw("SAME");
  main_hole2_z2_r->Draw("SAME");
  gPad->BuildLegend();
  c81->Print("remoll_plots_holes_z2_r_01_newpos.png");
  delete c8;

  TCanvas *c83 = new TCanvas("c83","Z3 square hole plots");
  c83->Divide(2,2);
  c83->cd(1);
  main_hole1_z3_r->Draw();
  c83->cd(2);
  main_hole2_z3_r->Draw();
  c83->cd(3);
  main_hole3_z3_r->Draw();
  c83->cd(4);
  main_hole1_z3_r->Draw();
  main_hole3_z3_r->Draw("SAME");
  main_hole2_z3_r->Draw("SAME");
  gPad->BuildLegend();
  c83->Print("remoll_plots_holes_z3_r_01_newpos.png");
  delete c83;

  TCanvas *c84 = new TCanvas("c84","Z4 square hole plots");
  c84->Divide(2,2);
  c84->cd(1);
  main_hole1_z4_r->Draw();
  c84->cd(2);
  main_hole2_z4_r->Draw();
  c84->cd(3);
  main_hole3_z4_r->Draw();
  c84->cd(4);
  main_hole1_z4_r->Draw();
  main_hole3_z4_r->Draw("SAME");
  main_hole2_z4_r->Draw("SAME");
  gPad->BuildLegend();
  c84->Print("remoll_plots_holes_z4_r_01_newpos.png");
  delete c84;

  TCanvas *c85 = new TCanvas("c85","Z5 square hole plots");
  c85->Divide(2,2);
  c85->cd(1);
  main_hole1_z5_r->Draw();
  c85->cd(2);
  main_hole2_z5_r->Draw();
  c85->cd(3);
  main_hole3_z5_r->Draw();
  c85->cd(4);
  main_hole1_z5_r->Draw();
  main_hole3_z5_r->Draw("SAME");
  main_hole2_z5_r->Draw("SAME");
  gPad->BuildLegend();
  c85->Print("remoll_plots_holes_z5_r_01_newpos.png");
  delete c85;




  TCanvas *c91 = new TCanvas("c91","Z1 slice hole plots");
  c91->Divide(2,2);
  c91->cd(1);
  main_hole1_z1_slice->Draw();
  c91->cd(2);
  main_hole2_z1_slice->Draw();
  c91->cd(3);
  main_hole3_z1_slice->Draw();
  c91->cd(4);
  main_hole1_z1_slice->Draw();
  main_hole3_z1_slice->Draw("SAME");
  main_hole2_z1_slice->Draw("SAME");
  gPad->BuildLegend();
  c91->Print("remoll_plots_holes_z1_slice_01_newpos.png");
  delete c91;

  TCanvas *c92 = new TCanvas("c92","Z2 slice hole plots");
  c92->Divide(2,2);
  c92->cd(1);
  main_hole1_z2_slice->Draw();
  c92->cd(2);
  main_hole2_z2_slice->Draw();
  c92->cd(3);
  main_hole3_z2_slice->Draw();
  c92->cd(4);
  main_hole1_z2_slice->Draw();
  main_hole3_z2_slice->Draw("SAME");
  main_hole2_z2_slice->Draw("SAME");
  gPad->BuildLegend();
  c92->Print("remoll_plots_holes_z2_slice_01_newpos.png");
  delete c92;

  TCanvas *c93 = new TCanvas("c93","Z3 slice hole plots");
  c93->Divide(2,2);
  c93->cd(1);
  main_hole1_z3_slice->Draw();
  c93->cd(2);
  main_hole2_z3_slice->Draw();
  c93->cd(3);
  main_hole3_z3_slice->Draw();
  c93->cd(4);
  main_hole1_z3_slice->Draw();
  main_hole3_z3_slice->Draw("SAME");
  main_hole2_z3_slice->Draw("SAME");
  gPad->BuildLegend();
  c93->Print("remoll_plots_holes_z3_slice_01_newpos.png");
  delete c93;

  TCanvas *c94 = new TCanvas("c94","Z4 slice hole plots");
  c94->Divide(2,2);
  c94->cd(1);
  main_hole1_z4_slice->Draw();
  c94->cd(2);
  main_hole2_z4_slice->Draw();
  c94->cd(3);
  main_hole3_z4_slice->Draw();
  c94->cd(4);
  main_hole1_z4_slice->Draw();
  main_hole3_z4_slice->Draw("SAME");
  main_hole2_z4_slice->Draw("SAME");
  gPad->BuildLegend();
  c94->Print("remoll_plots_holes_z4_slice_01_newpos.png");
  delete c94;

  TCanvas *c95 = new TCanvas("c95","Z5 slice hole plots");
  c95->Divide(2,2);
  c95->cd(1);
  main_hole1_z5_slice->Draw();
  c95->cd(2);
  main_hole2_z5_slice->Draw();
  c95->cd(3);
  main_hole3_z5_slice->Draw();
  c95->cd(4);
  main_hole1_z5_slice->Draw();
  main_hole3_z5_slice->Draw("SAME");
  main_hole2_z5_slice->Draw("SAME");
  gPad->BuildLegend();
  c95->Print("remoll_plots_holes_z5_slice_01_newpos.png");
  delete c95;




  TCanvas *c111 = new TCanvas("c111","polar angle z1 plots");
  c111->Divide(2,2);
  c111->cd(1);
  hole1_polar_angle_z1->Draw();
  hole3_polar_angle_z1->Draw("SAME");
  hole2_polar_angle_z1->Draw("SAME");
  c111->cd(2);
  hole1_polar_angle_z1->Draw();
  c111->cd(3);
  hole2_polar_angle_z1->Draw();
  c111->cd(4);
  hole3_polar_angle_z1->Draw();
  c111->Print("remoll_plots_holes_polar_angle_z1_01_newpos.png");
  delete c111;

  TCanvas *c112 = new TCanvas("c112","polar angle z2 plots");
  c112->Divide(2,2);
  c112->cd(1);
  hole1_polar_angle_z2->Draw();
  hole3_polar_angle_z2->Draw("SAME");
  hole2_polar_angle_z2->Draw("SAME");
  c112->cd(2);
  hole1_polar_angle_z2->Draw();
  c112->cd(3);
  hole2_polar_angle_z2->Draw();
  c112->cd(4);
  hole3_polar_angle_z2->Draw();
  c112->Print("remoll_plots_holes_polar_angle_z2_01_newpos.png");
  delete c112;

  TCanvas *c113 = new TCanvas("c113","polar angle z3 plots");
  c113->Divide(2,2);
  c113->cd(1);
  hole1_polar_angle_z3->Draw();
  hole3_polar_angle_z3->Draw("SAME");
  hole2_polar_angle_z3->Draw("SAME");
  c113->cd(2);
  hole1_polar_angle_z3->Draw();
  c113->cd(3);
  hole2_polar_angle_z3->Draw();
  c113->cd(4);
  hole3_polar_angle_z3->Draw();
  c113->Print("remoll_plots_holes_polar_angle_z3_01_newpos.png");
  delete c113;

  TCanvas *c114 = new TCanvas("c114","polar angle z4 plots");
  c114->Divide(2,2);
  c114->cd(1);
  hole1_polar_angle_z4->Draw();
  hole3_polar_angle_z4->Draw("SAME");
  hole2_polar_angle_z4->Draw("SAME");
  c114->cd(2);
  hole1_polar_angle_z4->Draw();
  c114->cd(3);
  hole2_polar_angle_z4->Draw();
  c114->cd(4);
  hole3_polar_angle_z4->Draw();
  c114->Print("remoll_plots_holes_polar_angle_z4_01_newpos.png");
  delete c114;

  TCanvas *c115 = new TCanvas("c115","polar angle z5 plots");
  c115->Divide(2,2);
  c115->cd(1);
  hole1_polar_angle_z5->Draw();
  hole3_polar_angle_z5->Draw("SAME");
  hole2_polar_angle_z5->Draw("SAME");
  c115->cd(2);
  hole1_polar_angle_z5->Draw();
  c115->cd(3);
  hole2_polar_angle_z5->Draw();
  c115->cd(4);
  hole3_polar_angle_z5->Draw();
  c115->Print("remoll_plots_holes_polar_angle_z5_01_newpos.png");
  delete c115;


  TCanvas *c10 = new TCanvas("c10","Energy Plots");
  c10->Divide(1,2);
  c10->cd(1);
  maindet_2D_energy_500_below->Draw();
  c10->cd(2);
  maindet_2D_energy_500_above->Draw();
  c10->Print("remoll_plots_energy_01_newpos.png");
  delete c10;


  TCanvas *c12 = new TCanvas("c12","polar angle Plots");
  c12->Divide(3,1);
  c12->cd(1);
  target_z->Draw();
  c12->cd(2);
  polar_angle->Draw();
  c12->cd(3);
  hit_e->Draw();
  c12->Print("remoll_plots_extra_01_newpos.png");
  delete c12;

  TCanvas *c13 = new TCanvas("c13","Polar Angle plots");
  c13->Divide(2,3);
  c13->cd(1);
  polar_angle_z1->Draw();
  c13->cd(2);
  polar_angle_z2->Draw();
  c13->cd(3);
  polar_angle_z3->Draw();
  c13->cd(4);
  polar_angle_z4->Draw();
  c13->cd(5);
  polar_angle_z5->Draw();
  c13->cd(6);
  polar_angle_z1->Draw();
  polar_angle_z2->Draw("SAME");
  polar_angle_z3->Draw("SAME");
  polar_angle_z4->Draw("SAME");
  polar_angle_z5->Draw("SAME");
  c13->Print("remoll_plots_polar_angle_01_newpos.png");
  delete c13;

  TCanvas *c14 = new TCanvas("c14","Polar Angle plots");
  c14->Divide(2,3);
  c14->cd(1);
  target_z1->Draw();
  c14->cd(2);
  target_z2->Draw();
  c14->cd(3);
  target_z3->Draw();
  c14->cd(4);
  target_z4->Draw();
  c14->cd(5);
  target_z5->Draw();
  c14->cd(6);
  target_z1->Draw();
  target_z2->Draw("SAME");
  target_z3->Draw("SAME");
  target_z4->Draw("SAME");
  target_z5->Draw("SAME");
  gPad->BuildLegend();
  c14->Print("remoll_plots_target_z_01_newpos.png");
  delete c14;

  TCanvas *c15 = new TCanvas("c15","Main det energy Z1");
  c15->Divide(2,2);
  c15->cd(1);
  hole1_hite_z1->Draw();
  c15->cd(2);
  hole2_hite_z1->Draw();
  c15->cd(3);
  hole3_hite_z1->Draw();
  c15->cd(4);
  hole1_hite_z1->Draw();
  hole3_hite_z1->Draw("SAME");
  hole2_hite_z1->Draw("SAME");
  c15->Print("remoll_plots_energy_z1_01_newpos.png");
  delete c15;

  TCanvas *c152 = new TCanvas("c152","Main det energy Z2");
  c152->Divide(2,2);
  c152->cd(1);
  hole1_hite_z2->Draw();
  c152->cd(2);
  hole2_hite_z2->Draw();
  c152->cd(3);
  hole3_hite_z2->Draw();
  c152->cd(4);
  hole1_hite_z2->Draw();
  hole3_hite_z2->Draw("SAME");
  hole2_hite_z2->Draw("SAME");
  c152->Print("remoll_plots_energy_z2_01_newpos.png");
  delete c152;

  TCanvas *c153 = new TCanvas("c153","Main det energy Z3");
  c153->Divide(2,2);
  c153->cd(1);
  hole1_hite_z3->Draw();
  c153->cd(2);
  hole2_hite_z3->Draw();
  c153->cd(3);
  hole3_hite_z3->Draw();
  c153->cd(4);
  hole1_hite_z3->Draw();
  hole3_hite_z3->Draw("SAME");
  hole2_hite_z3->Draw("SAME");
  c153->Print("remoll_plots_energy_z3_01_newpos.png");
  delete c153;

  TCanvas *c154 = new TCanvas("c154","Main det energy Z4");
  c154->Divide(2,2);
  c154->cd(1);
  hole1_hite_z4->Draw();
  c154->cd(2);
  hole2_hite_z4->Draw();
  c154->cd(3);
  hole3_hite_z4->Draw();
  c154->cd(4);
  hole1_hite_z4->Draw();
  hole3_hite_z4->Draw("SAME");
  hole2_hite_z4->Draw("SAME");
  c154->Print("remoll_plots_energy_z4_01_newpos.png");
  delete c154;

  TCanvas *c155 = new TCanvas("c155","Main det energy Z5");
  c155->Divide(2,2);
  c155->cd(1);
  hole1_hite_z5->Draw();
  c155->cd(2);
  hole2_hite_z5->Draw();
  c155->cd(3);
  hole3_hite_z5->Draw();
  c155->cd(4);
  hole1_hite_z5->Draw();
  hole3_hite_z5->Draw("SAME");
  hole2_hite_z5->Draw("SAME");
  c155->Print("remoll_plots_energy_z5_01_newpos.png");
  delete c155;

  TCanvas *c156 = new TCanvas("c156","Z energy plots");
  c156->Divide(2,3);
  c156->cd(1);
  hite_z1->Draw();
  c156->cd(2);
  hite_z2->Draw();
  c156->cd(3);
  hite_z3->Draw();
  c156->cd(4);
  hite_z4->Draw();
  c156->cd(5);
  hite_z5->Draw();
  c156->cd(6);
  hite_z1->Draw();
  hite_z2->Draw("SAME");
  hite_z3->Draw("SAME");
  hite_z4->Draw("SAME");
  hite_z5->Draw("SAME");
  c156->Print("remoll_plots_energy_z_01_newpos.png");
  delete c156;
}
