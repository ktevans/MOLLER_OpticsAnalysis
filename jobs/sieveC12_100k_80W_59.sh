#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_80mm5.root macros/PT/runexample_Optics1_sieve_80W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_80mm6.root macros/PT/runexample_Optics1_sieve_80W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_80mm7.root macros/PT/runexample_Optics1_sieve_80W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_80mm8.root macros/PT/runexample_Optics1_sieve_80W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_80mm9.root macros/PT/runexample_Optics1_sieve_80W.mac
