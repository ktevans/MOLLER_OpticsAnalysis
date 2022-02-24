#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm15.root macros/PT/runexample_Optics1_sieve_120B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm16.root macros/PT/runexample_Optics1_sieve_120B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm17.root macros/PT/runexample_Optics1_sieve_120B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm18.root macros/PT/runexample_Optics1_sieve_120B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm19.root macros/PT/runexample_Optics1_sieve_120B.mac
