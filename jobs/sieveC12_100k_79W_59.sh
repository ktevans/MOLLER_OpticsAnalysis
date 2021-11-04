#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_79mm5.root macros/runexample_Optics1_sieve_79W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_79mm6.root macros/runexample_Optics1_sieve_79W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_79mm7.root macros/runexample_Optics1_sieve_79W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_79mm8.root macros/runexample_Optics1_sieve_79W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_79mm9.root macros/runexample_Optics1_sieve_79W.mac
