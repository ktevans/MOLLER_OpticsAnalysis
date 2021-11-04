#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm5.root macros/PT/runexample_Optics1_sieve_120B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm6.root macros/PT/runexample_Optics1_sieve_120B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm7.root macros/PT/runexample_Optics1_sieve_120B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm8.root macros/PT/runexample_Optics1_sieve_120B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_120mm9.root macros/PT/runexample_Optics1_sieve_120B.mac
