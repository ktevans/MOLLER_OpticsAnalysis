#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_60mm5.root macros/PT/runexample_Optics1_sieve_60W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_60mm6.root macros/PT/runexample_Optics1_sieve_60W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_60mm7.root macros/PT/runexample_Optics1_sieve_60W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_60mm8.root macros/PT/runexample_Optics1_sieve_60W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_60mm9.root macros/PT/runexample_Optics1_sieve_60W.mac
