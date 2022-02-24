#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_070mm10.root macros/PT/runexample_Optics1_sieve_070B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_070mm11.root macros/PT/runexample_Optics1_sieve_070B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_070mm12.root macros/PT/runexample_Optics1_sieve_070B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_070mm13.root macros/PT/runexample_Optics1_sieve_070B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_070mm14.root macros/PT/runexample_Optics1_sieve_070B.mac
