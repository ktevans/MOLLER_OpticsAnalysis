#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_90mm0.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_90mm1.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_90mm2.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_90mm3.root macros/PT/runexample_Optics1_sieve_90W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_90mm4.root macros/PT/runexample_Optics1_sieve_90W.mac
