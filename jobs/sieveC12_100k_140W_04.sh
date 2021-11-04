#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm0.root macros/runexample_Optics1_sieve_140W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm1.root macros/runexample_Optics1_sieve_140W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm2.root macros/runexample_Optics1_sieve_140W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm3.root macros/runexample_Optics1_sieve_140W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm4.root macros/runexample_Optics1_sieve_140W.mac
