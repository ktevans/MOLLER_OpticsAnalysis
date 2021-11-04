#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm5.root macros/runexample_Optics1_sieve_140W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm6.root macros/runexample_Optics1_sieve_140W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm7.root macros/runexample_Optics1_sieve_140W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm8.root macros/runexample_Optics1_sieve_140W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_140mm9.root macros/runexample_Optics1_sieve_140W.mac
