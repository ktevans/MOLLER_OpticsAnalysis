
#include <TF1.h>
void TargetTest()
{

  // Allow Tree to use the root files you call

  TChain* T1 = new TChain("T");
  T1->Add("./test_sieve_in*");

  TChain* T2 = new TChain("T");
  T2->Add("./test_C12*");

// What does this line do?
gROOT -> SetBatch(kTRUE);

//Here is me defining histograms and setting the axis titles:

  TH1F* hltarget = new TH1F("hltarget", "Liquid Hydrogen Target", 40, -5200, -3800);
  hltarget -> SetMarkerColor(kBlue);

  TH1F* c12target = new TH1F("hltarget", "Thin Carbon Target", 40, -5200, -3800);
  c12target -> SetMarkerColor(kRed);


 //These are dummy histograms that I will use to help make the Legends later. They are filled with the colors that I want to grab.

 auto h1color = new TH1F("h1color","TLegend help",1,-1,1);
 h1color->FillRandom("gaus",3);
 h1color->SetFillColor(kBlue);

 auto h2color = new TH1F("h2color","TLegend help",1,-1,1);
 h2color->FillRandom("gaus",3);
 h2color->SetFillColor(kRed);


//----------------------------------------------------------------------
  // Draw and save the histograms

  TCanvas *c1 = new TCanvas("c1","Liquid Hydrogen Target vs Thin Carbon 12 Target",100,100,500,500);

  gStyle->SetOptTitle(0);

  T1 -> Draw("bm.z");
  T2 -> Draw("bm.z","sames");

  auto titl = new TPaveLabel(0.1,0.92,0.8,1.0,"Liquid Hydrogen Target vs Thin Carbon 12 Target","brNDC");
  titl->Draw();

  gPad -> Update();

  TPaveStats *s1 = (TPaveStats*)hltarget->GetListOfFunctions()->FindObject("stats");
  s1->SetY1NDC(0.9);
  s1->SetY2NDC(0.6);

  TPaveStats *s2 = (TPaveStats*)c12target->GetListOfFunctions()->FindObject("stats");
  s2->SetY1NDC(0.6);
  s2->SetY2NDC(0.3);

  auto l = new TLegend();

  l->AddEntry(h1color,"Liquid Hydrogen","f");
  l->AddEntry(h2color,"Carbon 12","f");
  l->Draw();

}
