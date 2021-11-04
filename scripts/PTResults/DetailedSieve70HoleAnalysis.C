#include <TF1.h>


//70 is the sieve thickness in mm
void DetailedSieve70HoleAnalysis()
{

//---Set up Chain and Tree---

  //Allow Tree to use the root files that you call. This line creates a chain of root files that you can add onto.
  TChain* T = new TChain("T");
  
  //Add files from the directory "rootfilesPT/", "70" is the sieve thickness in mm
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm0.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm1.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm2.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm3.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm4.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm5.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm6.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm7.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm8.root");
  T->Add("rootfilesPT/BWSieveC12_ep_100k_70mm9.root");

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

//---Define Histograms---

  //---Clean Pass Histograms---

  //1D histogram for primaries that cleanly pass through the sieve hole 1 and make it to the main detector on the rings (r plot)
  TH1F *radial_clean_pass_1 = new TH1F("radial_clean_pass_1","Primaries that Pass Through Sieve (70mm) Hole 1 and Hit the Main Detector", 1000, 650, 1200);
  radial_clean_pass_1 -> GetXaxis() -> SetTitle("r Position of Hits [mm]");
  radial_clean_pass_1 -> SetMarkerColor(kBlue);

  //1D histogram for primaries that cleanly pass through the sieve hole 2 and make it to the main detector on the rings (r plot)
  TH1F *radial_clean_pass_2 = new TH1F("radial_clean_pass_2","Primaries that Pass Through Sieve (70mm) Hole 2 and Hit the Main Detector", 1000, 650, 1200);
  radial_clean_pass_2 -> GetXaxis() -> SetTitle("r Position of Hits [mm]");
  radial_clean_pass_2 -> SetMarkerColor(kRed);

  //1D histogram for primaries that cleanly pass through the sieve hole 3 and make it to the main detector on the rings (r plot)
  TH1F *radial_clean_pass_3 = new TH1F("radial_clean_pass_3","Primaries that Pass Through Sieve (70mm) Hole 3 and Hit the Main Detector", 1000, 650, 1200);
  radial_clean_pass_3 -> GetXaxis() -> SetTitle("r Position of Hits [mm]");
  radial_clean_pass_3 -> SetMarkerColor(kGreen);

  //---Sieve Hole Showers---

  //1D histogram for charged particles that result from primaries entering the sieve holes and showering and make it to the main detector on the rings (r plot)
  TH1F *radial_hole_shower = new TH1F("radial_hole_shower","Charged Particles that Result from Primaries Hitting a Sieve Hole and then Showering Through Sieve (70mm) and Hit the Main Detector", 1000, 650, 1200);
  radial_hole_shower -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

  //---Sieve Surface Showers---

  //1D histogram for charged particles that result from primaries hitting the sieve surface and showering into one of the sieve holes and then make it to the main detector on the rings (r plot)
  TH1F *radial_hit_shower = new TH1F("radial_hit_shower","Charged Particles that Result from Primaries Hitting the Sieve Surface and then Showering into a Sieve (70mm) Hole and Hit the Main Detector", 1000, 650, 1200);
  radial_hit_shower -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

  //---True Punch-Through---

  //1D histogram for primaries that hit the sieve surface and punch through into a hole and then make it to the main detector on the rings (r plot)
  TH1F *radial_punch_through = new TH1F("radial_punch_through","Primaries that Hit the Sieve (70mm) Surface and Punch Through into One of the Holes and then Hit the Main Detector", 1000, 650, 1200);
  radial_punch_through -> GetXaxis() -> SetTitle("r Position of Hits [mm]");

  //---Color Histograms---

  //These are dummy histograms that I will use to help make the Legends later. They are filled with the colors that I want to grab. The histograms of interest (created above) are all points. When points are shown in a legend, they're hard to see, so I'm using a fill color in order to put a box of color in the legend. If your plots are filled or are lines, this step is unnecessary.

  auto h1color = new TH1F("h1color","TLegend help",1,-1,1);
  h1color->FillRandom("gaus",3); //This fills the histogram with a random function. I've chosen to fill it with a Gaussian ("gaus"), and it will fill 3 times. These choices are arbitrary as I'm only using the histogram to grab the fill color from it.
  h1color->SetFillColor(kBlue); //This will color in the histogram blue.

  auto h2color = new TH1F("h2color","TLegend help",1,-1,1);
  h2color->FillRandom("gaus",3);
  h2color->SetFillColor(kRed);

  auto h3color = new TH1F("h3color","TLegend help",1,-1,1);
  h3color->FillRandom("gaus",3);
  h3color->SetFillColor(kGreen);

//----------------------------------------------------------------------------

//---Define LLogical Flags---

  //Test if a primary hit the upstream surface of the sieve hole detectors, i.e., if a primary entered one of the sieve holes.
  bool in_hole_1 = false;
  bool in_hole_2 = false;
  bool in_hole_3 = false;

  //Test if a primary hit the downstream surface of the sieve hole detectors, i.e., if a primary exited one of the sieve holes.
  bool prim_out_hole_1 = false;
  bool prim_out_hole_2 = false;
  bool prim_out_hole_3 = false; 

  //Test if any charged particle hit the downstream surface of the sieve hole detectors, i.e., if a charged particle exited one of the sieve holes.
  bool any_out_hole_1 = false;
  bool any_out_hole_2 = false;
  bool any_out_hole_3 = false; 

  //Test if a primary cleanly passed through one of the sieve holes.
  //in_hole_# && prim_out_hole_#
  bool clean_pass_1 = false;
  bool clean_pass_2 = false;
  bool clean_pass_3 = false;

  //Test if a primary entered a hole and then caused a shower.
  //in_hole_# && !prim_out_hole_# 
  bool hole_shower_1 = false;
  bool hole_shower_2 = false;
  bool hole_shower_3 = false;

  //Test if a primary hit the sieve surface and then caused a shower. This is shower leakage.
  //!in_hole_# && any_out_hole_# 
  bool hit_shower_1 = false;
  bool hit_shower_2 = false;
  bool hit_shower_3 = false;

  //Test if a primary hit the sieve surface and then punched through the sieve and left through another hole. This is true punch-through.
  //!in_hole_# && prim_out_hole_# 
  bool hit_pt_1 = false;
  bool hit_pt_2 = false;
  bool hit_pt_3 = false;
 
//----------------------------------------------------------------------------

  //Loop over all events 
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {

    T->GetEntry(iev);
    
    in_hole_1 = false;
    in_hole_2 = false;
    in_hole_3 = false;

    prim_out_hole_1 = false;
    prim_out_hole_2 = false;
    prim_out_hole_3 = false;

    any_out_hole_1 = false;
    any_out_hole_2 = false;
    any_out_hole_3 = false;

    clean_pass_1 = false;
    clean_pass_2 = false;
    clean_pass_3 = false;

    hole_shower_1 = false;
    hole_shower_2 = false;
    hole_shower_3 = false;

    hit_shower_1 = false;
    hit_shower_2 = false;
    hit_shower_3 = false;

    hit_pt_1 = false;
    hit_pt_2 = false;
    hit_pt_3 = false;


    //Process hits, i.e., loop over all the hits in this event
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //Test if the primaries entered the holes.
      if(hit.trid == 1 && hit.det == 1001 && abs(hit.z - 590) < 0.1 && hit.pz >= 0)
      {
        in_hole_1 = true;
      }

      if(hit.trid == 1 && hit.det == 1002 && abs(hit.z - 590) < 0.1 && hit.pz >= 0)
      {
        in_hole_2 = true;
      }

      if(hit.trid == 1 && hit.det == 1003 && abs(hit.z - 590) < 0.1 && hit.pz >= 0)
      {
        in_hole_3 = true;
      }

      //Test if the primaries exited the holes. We don't need to process over the hits again because these booleans are not dependent on the previous ones.
      if(hit.trid == 1 && hit.det == 1001 && abs(hit.z - 660) < 0.1 && hit.pz >= 0)
      {
        prim_out_hole_1 = true;
      }

      if(hit.trid == 1 && hit.det == 1002 && abs(hit.z - 660) < 0.1 && hit.pz >= 0)
      {
        prim_out_hole_2 = true;
      }

      if(hit.trid == 1 && hit.det == 1003 && abs(hit.z - 660) < 0.1 && hit.pz >= 0)
      {
        prim_out_hole_3 = true;
      }

      //Test if any charged particles exited the holes. We don't need to process over the hits again because these booleans are not dependent on the previous ones.
      if((hit.pid == 11 || hit.pid == -11) && hit.det == 1001 && abs(hit.z - 660) < 0.1 && hit.pz >= 0)
      {
        any_out_hole_1 = true;
      }

      if((hit.pid == 11 || hit.pid == -11) && hit.det == 1002 && abs(hit.z - 660) < 0.1 && hit.pz >= 0)
      {
        any_out_hole_2 = true;
      }

      if((hit.pid == 11 || hit.pid == -11) && hit.det == 1003 && abs(hit.z - 660) < 0.1 && hit.pz >= 0)
      {
        any_out_hole_3 = true;
      }

    }//end loop over hits

    //Process hits again because the booleans we will flag here will be dependent on the previous ones.
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //Test if primaries cleanly passed through the holes.
      if(in_hole_1 && prim_out_hole_1)
      {
        clean_pass_1 = true;
      }

      if(in_hole_2 && prim_out_hole_2)
      {
        clean_pass_2 = true;
      }

      if(in_hole_3 && prim_out_hole_3)
      {
        clean_pass_3 = true;
      }

      //Test if primaries entered a hole and then caused a shower.
      if(in_hole_1 && !prim_out_hole_1)
      {
        hole_shower_1 = true;
      }

      if(in_hole_2 && !prim_out_hole_2)
      {
        hole_shower_2 = true;
      }

      if(in_hole_3 && !prim_out_hole_3)
      {
        hole_shower_3 = true;
      }

      //Test if primaries hits the sieve surface and then caused a shower to exit out of the hole.
      if(!in_hole_1 && any_out_hole_1)
      {
        hit_shower_1 = true;
      }

      if(!in_hole_2 && any_out_hole_2)
      {
        hit_shower_2 = true;
      }

      if(!in_hole_3 && any_out_hole_3)
      {
        hit_shower_3 = true;
      }

      //Test if primaries hits the sieve surface and then punched through the sieve to exit out of a hole.
      if(!in_hole_1 && prim_out_hole_1)
      {
        hit_pt_1 = true;
      }

      if(!in_hole_2 && prim_out_hole_2)
      {
        hit_pt_2 = true;
      }

      if(!in_hole_3 && prim_out_hole_3)
      {
        hit_pt_3 = true;
      }

    }//end second loop over hits

  }//end loop over events


  //Loop over all events 
  for (size_t iev = 0; iev < T->GetEntries(); iev++)
  {

    T->GetEntry(iev);

    //Process hits again because we will now be filling histograms.
    for (size_t ihit = 0; ihit < hits->size(); ihit++)
    {

      remollGenericDetectorHit_t hit = hits->at(ihit);

      //Look at clean passes.
      if(hit.trid == 1 && hit.pz >= 0 && hit.det == 28 && hit.r>=650 && hit.r<=1200)
      {
        //fill histogram for primaries that cleanly passed through the sieve holes and made it to the rings on the main detector.

        if(clean_pass_1)
        {
          radial_clean_pass_1 -> Fill(hit.r, rate);
        }

        if(clean_pass_2)
        {
          radial_clean_pass_2 -> Fill(hit.r, rate);
        }

        if(clean_pass_3)
        {
          radial_clean_pass_3 -> Fill(hit.r, rate);
        }

      }

      //Look at shower from primaries entering sieve holes.
      if((hit.pid == 11 || hit.pid == -11) && (hole_shower_1 || hole_shower_2 || hole_shower_3) && hit.pz >= 0 && hit.det == 28 && hit.r>=650 && hit.r<=1200)
      {
        //fill histogram for charged particles from sieve hole showers that made it to the rings on the main detector.
        radial_hole_shower -> Fill(hit.r, rate);
      }

      //Look at shower from primaries hitting sieve surface.
      if((hit.pid == 11 || hit.pid == -11) && (hit_shower_1 || hit_shower_2 || hit_shower_3) && hit.pz >= 0 && hit.det == 28 && hit.r>=650 && hit.r<=1200)
      {
        //fill histogram for charged particles from sieve surface showers that made it to the rings on the main detector.
        radial_hit_shower -> Fill(hit.r, rate);
      }

      //Look at true punch-through.
      if(hit.trid == 1 && (hit_pt_1 || hit_pt_2 || hit_pt_3) && hit.pz >= 0 && hit.det == 28 && hit.r>=650 && hit.r<=1200)
      {
        //fill histogram for primaries that punched through the sieve and out of one of the holes and made it to the rings on the main detector.
        radial_punch_through -> Fill(hit.r, rate);
      }

    }//end third loop over hits

  }//end loop over events

//--------------------------------------------------------------------------------

//---Draw and Save Histograms---

//---Clean Pass---

  TCanvas *cleanpass = new TCanvas("cleanpass", "Primaries that Cleanly Pass Through", 100, 100, 500, 500);

  gStyle -> SetOptTitle(0);

  radial_clean_pass_1 -> Draw();
  radial_clean_pass_2 -> Draw("SAMES");
  radial_clean_pass_3 -> Draw("SAMES");

  auto titleCleanPass = new TPaveLabel(0.1, 0.92, 0.9, 1.0, "Primaries that Cleanly Pass Through a Sieve (70mm) Hole and Hit the Main Detector", "brNDC");
  titleCleanPass -> Draw();

  gPad -> Update();

  TPaveStats *st1 = (TPaveStats*)radial_clean_pass_1 -> GetListOfFunctions() -> FindObject("stats");
  st1 -> SetY1NDC(0.9);
  st1 -> SetY2NDC(0.65);

  TPaveStats *st2 = (TPaveStats*)radial_clean_pass_2 -> GetListOfFunctions() -> FindObject("stats");
  st2 -> SetY1NDC(0.65);
  st2 -> SetY2NDC(0.4);

  TPaveStats *st3 = (TPaveStats*)radial_clean_pass_3 -> GetListOfFunctions() -> FindObject("stats");
  st3 -> SetY1NDC(0.4);
  st3 -> SetY2NDC(0.15);

  auto legend = new TLegend ();
  legend -> AddEntry(h1color, "Primaries from Hole 1", "f");
  legend -> AddEntry(h2color, "Primaries from Hole 2", "f");
  legend -> AddEntry(h3color, "Primaries from Hole 3", "f");
  legend -> Draw();

  cleanpass -> SaveAs("images/PTResults/Clean_Pass_Sieve_70.png");

//---Hole Showers---

  TCanvas *holeshower = new TCanvas("holeshower", "Hole Shower Charged Particles", 100, 100, 500, 500);

  radial_hole_shower -> Draw();

  holeshower -> SaveAs("images/PTResults/Hole_Shower_Sieve_70.png");

//---Hit Showers---

  TCanvas *hitshower = new TCanvas("hitshower", "Hit Shower Charged Particles", 100, 100, 500, 500);

  radial_hit_shower -> Draw();

  hitshower -> SaveAs("images/PTResults/Hit_Shower_Sieve_70.png");


//---True Punch-Through---

  TCanvas *truePT = new TCanvas("truePT", "Primaries True Punch-Through", 100, 100, 500, 500);

  radial_punch_through -> Draw();

  truePT -> SaveAs("images/PTResults/True_Punch_Through_Sieve_70.png");


}//end DetailedSieve70HoleAnalysis()
