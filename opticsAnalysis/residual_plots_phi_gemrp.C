#include <TF1.h>

//This script will analyze the target phi residuals. It will generate a plot showing the true and predicted target phi values, a plot showing the residuals vs r_gem, and a plot showing the residuals with a gaussian fit.
//You need to have already generated csv files with the proper data.

//After you've loaded the script, run it using the following command:
//residual_plots(0.5525589, 0.0, -0.00184307652, -0.564843123, 1.07449311, -492.776552, 0.00000171277466, -0.00387358949, -0.000133019035, 0.712888325, 11.7176687, 0.559668863, -1334.82125, -0.0000687340699, -0.171284693, -516.397095, "1DS", "p3", "11", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_11.csv")
//Here, the first 7 numbers are the fit parameters which come from the fitting function script.
//The constant "trgt" is the target location. Currently, the options for this are "1DS", "1US", "2DS", and "2US".
//The constant "pass" is the beam pass. The options are "p1", "p2", "p3", "p4", and "p5".
//The constant "hole_id" is the id number of the hole. The options are "11", "12", "21", "22", "31", "32", "41", "42", "51", "52", "61", "62", "71", "72", and "73".
//Finally, the last constant is the name of the CSV file you want the script to use to build its data frame. Make sure to include the path from where you run the script.

void residual_plots(double a_fit, double b0_fit, double b1_fit, double b2_fit, double b3_fit, double b4_fit, double b5_fit, double b6_fit, double b7_fit, double b8_fit, double b9_fit, double b10_fit, double b11_fit, double b12_fit, double b13_fit, double b14_fit, const TString& trgt, const TString& pass, const TString& hole_id, const char *datafile)
{
  ROOT::EnableImplicitMT(2);
  using namespace ROOT::RDF;

  //Assigning variables for fit coefficients.
  auto a = a_fit;
  auto b0 = b0_fit;
  auto b1 = b1_fit;
  auto b2 = b2_fit;
  auto b3 = b3_fit;
  auto b4 = b4_fit;
  auto b5 = b5_fit;
  auto b6 = b6_fit;
  auto b7 = b7_fit;
  auto b8 = b8_fit;
  auto b9 = b9_fit;
  auto b10 = b10_fit;
  auto b11 = b11_fit;
  auto b12 = b12_fit;
  auto b13 = b13_fit;
  auto b14 = b14_fit;

  //Create a Root DataFrame that will read from a CSV file.
  auto df = ROOT::RDF::MakeCsvDataFrame(datafile);

//------------------------------------------------------------------------------

  //Create new DataFrame that includes a new column. This new column will contain the target phi predicted by the fit.

  //Define formula to calculate predicted phi from fit.
  auto res_formula = [a, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14] (double r, double rp, double phi, double phip) {return a + b0 + (b1 * r) + (b2 * rp) + (b3 * phi) + (b4 * phip) + (b5 * r * r) + (b6 * r * rp) + (b7 * r * phi) + (b8 * r * phip) + (b9 * rp * rp) + (b10 * rp * phi) + (b11 * rp * phip) + (b12 * phi * phi) + (b13 * phi * phip) + (b14 * phip * phip); };
  //Create new column with predicted phi.
  auto df_with_fit = df.Define("tg_ph_pred", res_formula, {"gem1_r", "gem1_rp", "gem1_ph", "gem1_php"});

  //Create a column for residual values. This takes the target phi predicted by the fit and compares it to the target phi measures at the sieve in the simulation.
  auto df_with_resid = df_with_fit.Define("residuals_ph", "tg_ph_pred-tg_ph");

  //Create a column for the square of the residuals.
  auto df_resid_sqr = df_with_fit.Define("residuals_ph_sq","(tg_ph_pred-tg_ph)*(tg_ph_pred-tg_ph)");

  //Get the sum of the squares. This is also the variable u.
  double resid_ph_sum = *(double*)df_resid_sqr.Sum("residuals_ph_sq").GetPtr();

  //Generate doubles that correspond to the maximum and minimum values in certain comlumns. These can be used later to define axis ranges.
  //Define max and min for radial position at GEM1 plane.
  double rMax_d = *(double*)df_with_resid.Max("gem1_r").GetPtr();
  double rMin_d = *(double*)df_with_resid.Min("gem1_r").GetPtr();

  //Define max and min for sieve phi residuals.
  double residMax_d = *(double*)df_with_resid.Max("residuals_ph").GetPtr();
  double residMin_d = *(double*)df_with_resid.Min("residuals_ph").GetPtr();

  //Get the average residual value.
  double resid_ph_avg = *(double*)df_with_resid.Mean("residuals_ph").GetPtr();

  //Get average value of target phi.
  double tg_ph_avg = *(double*)df_resid_sqr.Mean("tg_ph").GetPtr();

  auto v_formula = [tg_ph_avg] (double tg_ph) {return (tg_ph-tg_ph_avg)*(tg_ph-tg_ph_avg); };

  //Define new dataframe with column for which the sum is a variable needed to find residual value for each hole.
  auto df_resid = df_resid_sqr.Define("tg_ph_v", v_formula, {"tg_ph"});

  //Generate variable v for residual value.
  double resid_v = *(double*)df_resid.Sum("tg_ph_v").GetPtr();

  //Calculate residual value via R=1-u/v where u and v are calculated above.
  double R= 1-(resid_ph_sum/resid_v);

//------------------------------------------------------------------------------

  //----TGraphs----

  //Plot radius [mm] at gem1 plane vs. predected target phi at sieve.
  auto pred_tgraph = df_with_resid.Graph("gem1_rp","tg_ph_pred");
  //Sets markers to be blue.
  pred_tgraph -> SetMarkerColorAlpha(kBlue, 1);
  //Set marker style to 7 - medium filled in circle.
  pred_tgraph -> SetMarkerStyle(7);
  //Currently pred_tgraph is not a TGraph but a ROOT::RDF::RResultPtr<TGraph>. We can use a smart pointer, GetPtr, to access the TGraph.
  auto pred_tgraph_ptr = pred_tgraph.GetPtr();

  //Plot radius [mm] at gem1 plane vs. measured target phi at sieve.
  auto true_tgraph = df_with_resid.Graph("gem1_rp","tg_ph");
  //Sets markers to be red.
  true_tgraph -> SetMarkerColorAlpha(kRed, 1);
  true_tgraph -> SetMarkerStyle(7);
  auto true_tgraph_ptr = true_tgraph.GetPtr();

  //Plot radius [mm] at gem1 plane vs. target phi residuals.
  auto residuals_tgraph = df_with_resid.Graph("gem1_rp","residuals_ph");
  residuals_tgraph -> SetMarkerColorAlpha(kRed, 1);
  residuals_tgraph -> SetMarkerStyle(7);
  auto residuals_tgraph_ptr = residuals_tgraph.GetPtr();

//------------------------------------------------------------------------------

  //----Draw and save TGraphs----

  //Define canvas to draw graphs on.
  auto graphC = new TCanvas();
  //Make a multiGraph that will hold both plots.
  auto multigraphC = new TMultiGraph();
  //Add each plot to the multigraph and draw. A = axis drawn P = marker is plotted at each point
  multigraphC -> Add(pred_tgraph_ptr);
  multigraphC -> Add(true_tgraph_ptr);
  multigraphC -> Draw("AP");
  //Set title of the graph.
  multigraphC -> SetTitle("True (red) and predected (blue) values for target phi vs GEM1 radius prime");
  //Changed title, so update gPad on which canvas is made.
  gPad -> Modified();
  gPad -> Update();
  //Set x and y axis titles.
  multigraphC -> GetXaxis() -> SetTitle("R' value of hits on GEM1 plane [mm/s]");
  multigraphC -> GetYaxis() -> SetTitle("Phi at sieve plane [radians]");
  gPad -> Modified();
  gPad -> Update();
  //Save canvas as a PDF in "remoll/opticsAnalysis/opticsMatrix/ResidualPlots/"
  graphC->SaveAs("opticsAnalysis/opticsMatrix/ResidualPlots/phi/tg_ph_vs_gem1_rp_"+trgt+"_"+pass+"_"+hole_id+".pdf");


  //Draw residual plot on canvas and save as pdf.
  auto resid_can = new TCanvas();

  //Set the fitting style. Options are (pcev), where p=1 pronts the probability, c-1 prints the degrees of freedom, e=1 prints the errors (if e=1, v must be 1), and v=1 prints the name/values of parameters.
  gStyle -> SetOptFit(1111);

  auto resid_multi = new TMultiGraph();
  //The two plots on this multiGraph need different options ("L" for the line and "P" for the scatterplot). We can define these separately in the Add function.
  //resid_multi -> Add(line, "L");
  resid_multi -> Add(residuals_tgraph_ptr, "P");
  resid_multi -> Draw("A");

  //Add a first degree polynomial fit to the plot. Q does minimum printing for the fit.
  resid_multi -> Fit("pol1","Q");
  gPad -> Modified();
  gPad -> Update();
  resid_multi -> SetTitle("Sieve Phi Residuals");
  gPad -> Modified();
  gPad -> Update();
  resid_multi -> GetXaxis() -> SetTitle("R' value of hits on GEM1 plane [mm/s]");
  //Create a label on the bottom of the graph that states the average residual value.
  TPaveLabel *Plab0 = new TPaveLabel(0.4, 0.15, 0.88, 0.2, Form("R value = %5.4f     Residual sum = %5.8f", R, resid_ph_sum), "NDC");
  Plab0 -> Draw();
  gPad -> Modified();
  gPad -> Update();
  resid_can -> SaveAs("opticsAnalysis/opticsMatrix/ResidualPlots/phi/residuals_ph_vs_gem1_rp_"+trgt+"_"+pass+"_"+hole_id+".pdf");

}
