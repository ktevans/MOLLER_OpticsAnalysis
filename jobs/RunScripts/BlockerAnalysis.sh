#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

#Charged Particles

  echo 'gROOT->LoadMacro("scripts/BlockerCPAnalysis.C"); Blocker("050"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/BlockerCPAnalysis.C"); Blocker("060"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/BlockerCPAnalysis.C"); Blocker("070"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/BlockerCPAnalysis.C"); Blocker("080"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/BlockerCPAnalysis.C"); Blocker("090"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/BlockerCPAnalysis.C"); Blocker("100"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/BlockerCPAnalysis.C"); Blocker("110"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/BlockerCPAnalysis.C"); Blocker("120"); gSystem->Exit(0);' | build/reroot -b -l


  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("050"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("060"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("070"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("080"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("090"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("100"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("110"); gSystem->Exit(0);' | build/reroot -b -l
  echo 'gROOT->LoadMacro("scripts/TBlockerCPAnalysis.C"); Blocker("120"); gSystem->Exit(0);' | build/reroot -b -l

#Primaries

 # echo 'gROOT->LoadMacro("scripts/BlockerPrimAnalysis.C"); Blocker("050"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/BlockerPrimAnalysis.C"); Blocker("060"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/BlockerPrimAnalysis.C"); Blocker("070"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/BlockerPrimAnalysis.C"); Blocker("080"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/BlockerPrimAnalysis.C"); Blocker("090"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/BlockerPrimAnalysis.C"); Blocker("100"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/BlockerPrimAnalysis.C"); Blocker("110"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/BlockerPrimAnalysis.C"); Blocker("120"); gSystem->Exit(0);' | build/reroot -b -l


 # echo 'gROOT->LoadMacro("scripts/TBlockerPrimAnalysis.C"); Blocker("050"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/TBlockerPrimAnalysis.C"); Blocker("060"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/TBlockerPrimAnalysis.C"); Blocker("070"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/TBlockerPrimAnalysis.C"); Blocker("080"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/TBlockerPrimAnalysis.C"); Blocker("090"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/TBlockerPrimAnalysis.C"); Blocker("100"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/TBlockerPrimAnalysis.C"); Blocker("110"); gSystem->Exit(0);' | build/reroot -b -l
 # echo 'gROOT->LoadMacro("scripts/TBlockerPrimAnalysis.C"); Blocker("120"); gSystem->Exit(0);' | build/reroot -b -l

#Gammas

#  echo 'gROOT->LoadMacro("scripts/BlockerGammaAnalysis.C"); Blocker("050"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/BlockerGammaAnalysis.C"); Blocker("060"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/BlockerGammaAnalysis.C"); Blocker("070"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/BlockerGammaAnalysis.C"); Blocker("080"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/BlockerGammaAnalysis.C"); Blocker("090"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/BlockerGammaAnalysis.C"); Blocker("100"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/BlockerGammaAnalysis.C"); Blocker("110"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/BlockerGammaAnalysis.C"); Blocker("120"); gSystem->Exit(0);' | build/reroot -b -l


#  echo 'gROOT->LoadMacro("scripts/TBlockerGammaAnalysis.C"); Blocker("050"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/TBlockerGammaAnalysis.C"); Blocker("060"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/TBlockerGammaAnalysis.C"); Blocker("070"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/TBlockerGammaAnalysis.C"); Blocker("080"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/TBlockerGammaAnalysis.C"); Blocker("090"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/TBlockerGammaAnalysis.C"); Blocker("100"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/TBlockerGammaAnalysis.C"); Blocker("110"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/TBlockerGammaAnalysis.C"); Blocker("120"); gSystem->Exit(0);' | build/reroot -b -l  

