#!/bin/bash
#SBATCH --mem=4G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=01:10:00

build/remoll -o siveC12_10k.root macros/runexample_Optics1_sieve.mac
