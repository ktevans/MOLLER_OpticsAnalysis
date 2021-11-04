#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=24:00:00

build/remoll -o rootfiles/PrimAnalysis/moller_test_100k_100mm16.root macros/moller_test_100mm.mac
