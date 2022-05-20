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

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "11", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_11.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "12", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_12.csv"); gSystem->Exit(0);' | build/reroot -b -l

#Section 2

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "21", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_21.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "22", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_22.csv"); gSystem->Exit(0);' | build/reroot -b -l

#Section 3

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "31", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_31.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "32", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_32.csv"); gSystem->Exit(0);' | build/reroot -b -l

#Section 4

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "41", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_41.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "42", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_42.csv"); gSystem->Exit(0);' | build/reroot -b -l

#Section 5

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "51", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_51.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "52", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_52.csv"); gSystem->Exit(0);' | build/reroot -b -l

#Section 6

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "61", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_61.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "62", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_62.csv"); gSystem->Exit(0);' | build/reroot -b -l

#Section 7

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "71", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_71.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "72", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_72.csv"); gSystem->Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("opticsAnalysis/residual_plots_just_residuals.C"); residual_plots(0.2579, 0.0, -0.00086747, 3.9527, 0.00000096143, -0.011966, 46.368, "73", "opticsAnalysis/opticsMatrix/output/output/sieveHole_p3_73.csv"); gSystem->Exit(0);' | build/reroot -b -l

