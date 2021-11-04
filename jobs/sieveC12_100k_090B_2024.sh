#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm20.root macros/PT/runexample_Optics1_sieve_090B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm21.root macros/PT/runexample_Optics1_sieve_090B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm22.root macros/PT/runexample_Optics1_sieve_090B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm23.root macros/PT/runexample_Optics1_sieve_090B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm24.root macros/PT/runexample_Optics1_sieve_090B.mac
