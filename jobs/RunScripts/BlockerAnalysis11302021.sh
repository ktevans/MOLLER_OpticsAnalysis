#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00


  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("080"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("090"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("100"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("110"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("120"); gSystem->Exit(0);' | build/reroot -b -l

