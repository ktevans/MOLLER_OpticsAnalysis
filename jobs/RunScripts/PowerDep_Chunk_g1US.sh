#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("0"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("1"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("2"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("3"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("4"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("5"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("6"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("7"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("8"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("9"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("10"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("11"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("12"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("13"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("14"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("15"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("16"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("17"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("18"); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US_chunk.C"); PowerDep("19"); gSystem -> Exit(0);' | build/reroot -b -l


#echo 'gROOT->LoadMacro("scripts/PowerDep_g2.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g3.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_1mm_USDS.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l

#echo 'gROOT->LoadMacro("scripts/PowerDep_g1_US.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g2_US.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g3_US.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_1mm_US.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l

#echo 'gROOT->LoadMacro("scripts/PowerDep_g1_DS.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g2_DS.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_g3_DS.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/PowerDep_1mm_DS.C"); PowerDep(); gSystem -> Exit(0);' | build/reroot -b -l
