#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=24:00:00

build/remoll -o sieveC12_moller_100k_100mm_test.root macros/runexample_C12_test.mac
