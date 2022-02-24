#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

  echo 'gROOT->LoadMacro("scripts/TBlockerCPSurfaceAnalysis.C"); Blocker("050",50); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPSurfaceAnalysis.C"); Blocker("060",60); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPSurfaceAnalysis.C"); Blocker("070",70); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPSurfaceAnalysis.C"); Blocker("080",80); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPSurfaceAnalysis.C"); Blocker("090",90); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPSurfaceAnalysis.C"); Blocker("100",100); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPSurfaceAnalysis.C"); Blocker("110",110); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPSurfaceAnalysis.C"); Blocker("120",120); gSystem->Exit(0);' | build/reroot -b -l

