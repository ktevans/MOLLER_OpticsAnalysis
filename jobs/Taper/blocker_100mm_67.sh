#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_100mm6.root macros/PT/runexample_Optics1_sieve_100B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_100mm7.root macros/PT/runexample_Optics1_sieve_100B.mac
