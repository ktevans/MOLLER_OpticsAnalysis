#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

echo 'gROOT->LoadMacro("scripts/SieveInnerHoleAnalysisRadDose12162021.C"); Analysis("sieve","g1"); gSystem->Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/SieveInnerHoleAnalysisRadDose12162021.C"); Analysis("sieve","g2"); gSystem->Exit(0);' | build/reroot -b -l


#Charged Particles

#  echo 'gROOT->LoadMacro("scripts/SieveCPAnalysisInnerBore.C"); Analysis("sieve","g1"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/SieveCPAnalysisInnerBore.C"); Analysis("sieve","g2"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/SieveCPAnalysisInnerBore.C"); Analysis("blocker","g1"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/SieveCPAnalysisInnerBore.C"); Analysis("blocker","g2"); gSystem->Exit(0);' | build/reroot -b -l

#Gammas

#  echo 'gROOT->LoadMacro("scripts/SieveGammaAnalysisInnerBore.C"); Analysis("sieve","g1"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/SieveGammaAnalysisInnerBore.C"); Analysis("sieve","g2"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/SieveGammaAnalysisInnerBore.C"); Analysis("blocker","g1"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/SieveGammaAnalysisInnerBore.C"); Analysis("blocker","g2"); gSystem->Exit(0);' | build/reroot -b -l

#Primaries

#  echo 'gROOT->LoadMacro("scripts/SievePrimAnalysisInnerBore.C"); Analysis("sieve","g1"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/SievePrimAnalysisInnerBore.C"); Analysis("sieve","g2"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/SievePrimAnalysisInnerBore.C"); Analysis("blocker","g1"); gSystem->Exit(0);' | build/reroot -b -l
#  echo 'gROOT->LoadMacro("scripts/SievePrimAnalysisInnerBore.C"); Analysis("blocker","g2"); gSystem->Exit(0);' | build/reroot -b -l
