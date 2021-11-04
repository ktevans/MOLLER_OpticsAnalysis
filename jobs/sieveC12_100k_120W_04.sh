#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_120mm0.root macros/PT/runexample_Optics1_sieve_120W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_120mm1.root macros/PT/runexample_Optics1_sieve_120W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_120mm2.root macros/PT/runexample_Optics1_sieve_120W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_120mm3.root macros/PT/runexample_Optics1_sieve_120W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_120mm4.root macros/PT/runexample_Optics1_sieve_120W.mac
