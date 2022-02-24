#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

#echo 'gROOT->LoadMacro("scripts/PowerDep_g1_NT.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g2_NT.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g3_NT.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_1mm_USDS.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l

echo 'gROOT->LoadMacro("scripts/PowerDep_g1_DS_v2_LH2.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g2_US.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g3_US.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_1mm_US.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l

#echo 'gROOT->LoadMacro("scripts/PowerDep_g1_DS_v2.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g2_DS_v2.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g3_DS_v2.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_1mm_DS_v2.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
