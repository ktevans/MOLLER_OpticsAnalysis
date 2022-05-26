#include <TF1.h>

//This script will analyze the target theta residuals. It will generate a plot showing the true and predicted target theta values, a plot showing the residuals vs r_gem, and a plot showing the residuals with a gaussian fit.
//You need to have already generated csv files with the proper data.

//After you've loaded the script, run it using the following command:
//residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "11", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_11.csv")
//Here, the first 7 numbers are the fit parameters which come from the fitting function script.
//The constant "trgt" is the target location. Currently, the options for this are "1DS", "1US", "2DS", and "2US".
//The constant "pass" is the beam pass. The options are "p1", "p2", "p3", "p4", and "p5".
//The constant "hole_id" is the id number of the hole. The options are "11", "12", "21", "22", "31", "32", "41", "42", "51", "52", "61", "62", "71", "72", and "73".
//Finally, the last constant is the name of the CSV file you want the script to use to build its data frame. Make sure to include the path from where you run the script.

void residual_plots(double a_fit, double b0_fit, double b1_fit, double b2_fit, double b3_fit, double b4_fit, double b5_fit, const TString& trgt, const TString& pass, const TString& hole_id, const char *datafile)
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

  //auto datafile = "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_11.csv";

  //Create a Root DataFrame that will read from a CSV file.
  auto df = ROOT::RDF::MakeCsvDataFrame(datafile);

//------------------------------------------------------------------------------

  //Create new DataFrame that includes a new column. This new column will contain the target theta predicted by the fit.

  //Define formula to calculate predicted theta from fit.
  auto res_formula = [a, b0, b1, b2, b3, b4, b5] (double r, double rp) {return a + (b1 * r) + (b2 * rp) + (b3 * (r * r)) + (b4 * r * rp) + (b5 * (rp * rp)); };
  //Create new column with predicted theta.
  auto df_with_fit = df.Define("tg_th_pred", res_formula, {"gem1_r", "gem1_rp"});

  //Create a column for residual values. This takes the target theta predicted by the fit and compares it to the target theta measures at the sieve in the simulation.
  auto df_with_resid = df_with_fit.Define("residuals_th", "tg_th_pred-tg_th");

  //Create a column for the square of the residuals.
  auto df_resid_sqr = df_with_fit.Define("residuals_th_sq","(tg_th_pred-tg_th)*(tg_th_pred-tg_th)");

  //Get the sum of the squares. This is also the variable u.
  double resid_th_sum = *(double*)df_resid_sqr.Sum("residuals_th_sq").GetPtr();

  //Generate doubles that correspond to the maximum and minimum values in certain comlumns. These can be used later to define axis ranges.
  //Define max and min for radial position at GEM1 plane.
  double rMax_d = *(double*)df_with_resid.Max("gem1_r").GetPtr();
  double rMin_d = *(double*)df_with_resid.Min("gem1_r").GetPtr();

  //Define max and min for sieve theta residuals.
  double residMax_d = *(double*)df_with_resid.Max("residuals_th").GetPtr();
  double residMin_d = *(double*)df_with_resid.Min("residuals_th").GetPtr();

  //Get the average residual value.
  double resid_th_avg = *(double*)df_with_resid.Mean("residuals_th").GetPtr();

  //Get average value of target theta.
  double tg_th_avg = *(double*)df_resid_sqr.Mean("tg_th").GetPtr();

  auto v_formula = [tg_th_avg] (double tg_th) {return (tg_th-tg_th_avg)*(tg_th-tg_th_avg); };

  //Define new dataframe with column for which the sum is a variable needed to find residual value for each hole.
  auto df_resid = df_resid_sqr.Define("tg_th_v", v_formula, {"tg_th"});

  //Generate variable v for residual value.
  double resid_v = *(double*)df_resid.Sum("tg_th_v").GetPtr();

  //Calculate residual value via R=1-u/v where u and v are calculated above.
  double R= 1-(resid_th_sum/resid_v);

//------------------------------------------------------------------------------

  //----TGraphs----

  //Plot radius [mm] at gem1 plane vs. predected target theta at sieve.
  auto pred_tgraph = df_with_resid.Graph("gem1_ph","tg_th_pred");
  //Sets markers to be blue.
  pred_tgraph -> SetMarkerColorAlpha(kBlue, 1);
  //Set marker style to 7 - medium filled in circle.
  pred_tgraph -> SetMarkerStyle(7);
  //Currently pred_tgraph is not a TGraph but a ROOT::RDF::RResultPtr<TGraph>. We can use a smart pointer, GetPtr, to access the TGraph.
  auto pred_tgraph_ptr = pred_tgraph.GetPtr();

  //Plot radius [mm] at gem1 plane vs. measured target theta at sieve.
  auto true_tgraph = df_with_resid.Graph("gem1_ph","tg_th");
  //Sets markers to be red.
  true_tgraph -> SetMarkerColorAlpha(kRed, 1);
  true_tgraph -> SetMarkerStyle(7);
  auto true_tgraph_ptr = true_tgraph.GetPtr();

  //Plot radius [mm] at gem1 plane vs. target theta residuals.
  auto residuals_tgraph = df_with_resid.Graph("gem1_ph","residuals_th");
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
  multigraphC -> SetTitle("True (red) and predected (blue) values for target theta vs GEM1 phi");
  //Changed title, so update gPad on which canvas is made.
  gPad -> Modified();
  gPad -> Update();
  //Set x and y axis titles.
  multigraphC -> GetXaxis() -> SetTitle("Phi value of hits on GEM1 plane [radians]");
  multigraphC -> GetYaxis() -> SetTitle("Theta at sieve plane [radians]");
  gPad -> Modified();
  gPad -> Update();
  //Save canvas as a PDF in "remoll/opticsAnalysis/opticsMatrix/ResidualPlots/"
  graphC->SaveAs("opticsAnalysis/opticsMatrix/ResidualPlots/theta/tg_th_vs_gem1_ph_"+trgt+"_"+pass+"_"+hole_id+".pdf");


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
  resid_multi -> SetTitle("Sieve Theta Residuals");
  gPad -> Modified();
  gPad -> Update();
  resid_multi -> GetXaxis() -> SetTitle("Phi value of hits on GEM1 plane [radians]");
  //Create a label on the bottom of the graph that states the average residual value.
  TPaveLabel *Plab0 = new TPaveLabel(0.4, 0.15, 0.88, 0.2, Form("R value = %5.4f     Residual sum = %5.8f", R, resid_th_sum), "NDC");
  Plab0 -> Draw();
  gPad -> Modified();
  gPad -> Update();
  resid_can -> SaveAs("opticsAnalysis/opticsMatrix/ResidualPlots/theta/residuals_th_vs_gem1_ph_"+trgt+"_"+pass+"_"+hole_id+".pdf");

}
