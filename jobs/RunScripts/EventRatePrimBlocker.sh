#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

#echo 'gROOT->LoadMacro("scripts/EventRatePrimBlocker.C"); Analysis("g1"); gSystem -> Exit(0);' | build/reroot -b -l
#echo 'gROOT->LoadMacro("scripts/EventRatePrimMainNoSieve.C"); Analysis(); gSystem -> Exit(0);' | build/reroot -b -l
echo 'gROOT->LoadMacro("scripts/EventRatePrimMainWithSieve.C"); Analysis(); gSystem -> Exit(0);' | build/reroot -b -l
