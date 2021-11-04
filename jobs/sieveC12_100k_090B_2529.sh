#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm25.root macros/PT/runexample_Optics1_sieve_090B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm26.root macros/PT/runexample_Optics1_sieve_090B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm27.root macros/PT/runexample_Optics1_sieve_090B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm28.root macros/PT/runexample_Optics1_sieve_090B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_090mm29.root macros/PT/runexample_Optics1_sieve_090B.mac
