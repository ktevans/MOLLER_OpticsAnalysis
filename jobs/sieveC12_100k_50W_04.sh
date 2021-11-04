#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_50mm0.root macros/PT/runexample_Optics1_sieve_50W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_50mm1.root macros/PT/runexample_Optics1_sieve_50W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_50mm2.root macros/PT/runexample_Optics1_sieve_50W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_50mm3.root macros/PT/runexample_Optics1_sieve_50W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_50mm4.root macros/PT/runexample_Optics1_sieve_50W.mac
