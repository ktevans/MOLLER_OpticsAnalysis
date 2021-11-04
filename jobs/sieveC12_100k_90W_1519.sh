#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm15.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm16.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm17.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm18.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm19.root macros/PT/runexample_Optics1_sieve_90W.mac
