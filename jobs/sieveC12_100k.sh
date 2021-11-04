#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=24:00:00

build/remoll -o sieveC12_ep_100k.root macros/runexample_Optics1_sieve.mac
