#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_120mm20.root macros/PT/runexample_Optics1_sieve_120W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_120mm21.root macros/PT/runexample_Optics1_sieve_120W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_120mm22.root macros/PT/runexample_Optics1_sieve_120W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_120mm23.root macros/PT/runexample_Optics1_sieve_120W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_120mm24.root macros/PT/runexample_Optics1_sieve_120W.mac
