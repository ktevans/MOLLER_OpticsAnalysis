#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/remoll -o sieveLH_moller_100k_60mm_W8.root macros/runexample_moller_W_60mm.mac
