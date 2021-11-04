#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm10.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm11.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm12.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm13.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_90mm14.root macros/PT/runexample_Optics1_sieve_90W.mac
