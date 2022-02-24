#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

  echo 'gROOT->LoadMacro("scripts/35BlockerAnalysis1.C"); Blocker("050"); gSystem->Exit(0);' | build/reroot -b -l
