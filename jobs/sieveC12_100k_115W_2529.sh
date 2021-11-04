#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_115mm25.root macros/PT/runexample_Optics1_sieve_115W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_115mm26.root macros/PT/runexample_Optics1_sieve_115W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_115mm27.root macros/PT/runexample_Optics1_sieve_115W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_115mm28.root macros/PT/runexample_Optics1_sieve_115W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_115mm29.root macros/PT/runexample_Optics1_sieve_115W.mac
