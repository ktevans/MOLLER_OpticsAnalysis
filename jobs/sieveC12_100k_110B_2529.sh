#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_110mm25.root macros/PT/runexample_Optics1_sieve_110B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_110mm26.root macros/PT/runexample_Optics1_sieve_110B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_110mm27.root macros/PT/runexample_Optics1_sieve_110B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_110mm28.root macros/PT/runexample_Optics1_sieve_110B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_110mm29.root macros/PT/runexample_Optics1_sieve_110B.mac
