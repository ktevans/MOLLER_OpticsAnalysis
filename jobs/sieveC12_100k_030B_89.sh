#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_030mm8.root macros/PT/runexample_Optics1_sieve_030B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_030mm9.root macros/PT/runexample_Optics1_sieve_030B.mac
