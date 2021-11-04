#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_70mm5.root macros/PT/runexample_Optics1_sieve_70W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_70mm6.root macros/PT/runexample_Optics1_sieve_70W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_70mm7.root macros/PT/runexample_Optics1_sieve_70W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_70mm8.root macros/PT/runexample_Optics1_sieve_70W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_70mm9.root macros/PT/runexample_Optics1_sieve_70W.mac
