#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_40mm0.root macros/PT/runexample_Optics1_sieve_40W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_40mm1.root macros/PT/runexample_Optics1_sieve_40W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_40mm2.root macros/PT/runexample_Optics1_sieve_40W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_40mm3.root macros/PT/runexample_Optics1_sieve_40W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_40mm4.root macros/PT/runexample_Optics1_sieve_40W.mac
