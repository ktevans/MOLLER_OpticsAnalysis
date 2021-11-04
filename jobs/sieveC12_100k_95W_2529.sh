#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm25.root macros/PT/runexample_Optics1_sieve_95W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm26.root macros/PT/runexample_Optics1_sieve_95W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm27.root macros/PT/runexample_Optics1_sieve_95W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm28.root macros/PT/runexample_Optics1_sieve_95W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_95mm29.root macros/PT/runexample_Optics1_sieve_95W.mac
