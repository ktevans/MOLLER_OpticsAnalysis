#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm15.root macros/PT/runexample_Optics1_sieve_95W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm16.root macros/PT/runexample_Optics1_sieve_95W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm17.root macros/PT/runexample_Optics1_sieve_95W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm18.root macros/PT/runexample_Optics1_sieve_95W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm19.root macros/PT/runexample_Optics1_sieve_95W.mac
