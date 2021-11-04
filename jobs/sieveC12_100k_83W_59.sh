#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_83mm5.root macros/runexample_Optics1_sieve_83W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_83mm6.root macros/runexample_Optics1_sieve_83W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_83mm7.root macros/runexample_Optics1_sieve_83W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_83mm8.root macros/runexample_Optics1_sieve_83W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_83mm9.root macros/runexample_Optics1_sieve_83W.mac
