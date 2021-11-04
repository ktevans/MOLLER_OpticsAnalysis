#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_130mm5.root macros/PT/runexample_Optics1_sieve_130W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_130mm6.root macros/PT/runexample_Optics1_sieve_130W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_130mm7.root macros/PT/runexample_Optics1_sieve_130W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_130mm8.root macros/PT/runexample_Optics1_sieve_130W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_130mm9.root macros/PT/runexample_Optics1_sieve_130W.mac
