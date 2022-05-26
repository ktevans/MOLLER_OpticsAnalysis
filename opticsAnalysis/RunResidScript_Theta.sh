#!/bin/bash
#SBATCH --nodes=1
#SBATCH --account=halla
#SBATCH --mem-per-cpu=250
#SBATCH --ntasks=2
#SBATCH --exclude=farm19104,farm19105,farm19106,farm19107,farm1996,farm19101
#SBATCH --partition=production
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=2:00:00

#Section 1

#r
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "11", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_11.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "12", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_12.csv"); gSystem->Exit(0);' | build/reroot -b -l

#rp
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "11", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_11.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "12", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_12.csv"); gSystem->Exit(0);' | build/reroot -b -l

#phi
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "11", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_11.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "12", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_12.csv"); gSystem->Exit(0);' | build/reroot -b -l

#php
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "11", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_11.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "12", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_12.csv"); gSystem->Exit(0);' | build/reroot -b -l


#Section 2

#r
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "21", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_21.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "22", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_22.csv"); gSystem->Exit(0);' | build/reroot -b -l

#rp
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "21", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_21.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "22", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_22.csv"); gSystem->Exit(0);' | build/reroot -b -l

#ph
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "21", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_21.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "22", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_22.csv"); gSystem->Exit(0);' | build/reroot -b -l

#php
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "21", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_21.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "22", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_22.csv"); gSystem->Exit(0);' | build/reroot -b -l


#Section 3

#r
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "31", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_31.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "32", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_32.csv"); gSystem->Exit(0);' | build/reroot -b -l

#rp
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "31", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_31.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "32", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_32.csv"); gSystem->Exit(0);' | build/reroot -b -l

#ph
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "31", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_31.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "32", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_32.csv"); gSystem->Exit(0);' | build/reroot -b -l

#php
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "31", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_31.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "32", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_32.csv"); gSystem->Exit(0);' | build/reroot -b -l


#Section 4

#r
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "41", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_41.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "42", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_42.csv"); gSystem->Exit(0);' | build/reroot -b -l

#rp
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "41", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_41.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "42", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_42.csv"); gSystem->Exit(0);' | build/reroot -b -l

#ph
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "41", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_41.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "42", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_42.csv"); gSystem->Exit(0);' | build/reroot -b -l

#php
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "41", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_41.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "42", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_42.csv"); gSystem->Exit(0);' | build/reroot -b -l


#Section 5

#r
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "51", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_51.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "52", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_52.csv"); gSystem->Exit(0);' | build/reroot -b -l

#rp
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "51", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_51.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "52", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_52.csv"); gSystem->Exit(0);' | build/reroot -b -l

#ph
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "51", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_51.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "52", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_52.csv"); gSystem->Exit(0);' | build/reroot -b -l

#php
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "51", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_51.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "52", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_52.csv"); gSystem->Exit(0);' | build/reroot -b -l


#Section 6

#r
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "61", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_61.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "62", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_62.csv"); gSystem->Exit(0);' | build/reroot -b -l

#rp
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "61", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_61.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "62", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_62.csv"); gSystem->Exit(0);' | build/reroot -b -l

#ph
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "61", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_61.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "62", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_62.csv"); gSystem->Exit(0);' | build/reroot -b -l

#php
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "61", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_61.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "62", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_62.csv"); gSystem->Exit(0);' | build/reroot -b -l


#Section 7 

#r
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "71", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_71.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "72", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_72.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemr.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "73", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_73.csv"); gSystem->Exit(0);' | build/reroot -b -l

#rp
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "71", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_71.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "72", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_72.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemrp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "73", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_73.csv"); gSystem->Exit(0);' | build/reroot -b -l

#ph
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "71", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_71.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "72", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_72.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemph.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "73", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_73.csv"); gSystem->Exit(0);' | build/reroot -b -l

#php
echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "71", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_71.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "72", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_72.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/theta_residuals_gemphp.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "1DS", "p3", "73", "opticsAnalysis/opticsMatrix/dataFiles/output/optics1DS/optics1DS_p3_73.csv"); gSystem->Exit(0);' | build/reroot -b -l
