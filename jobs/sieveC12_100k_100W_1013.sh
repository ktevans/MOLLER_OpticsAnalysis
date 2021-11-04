#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_100mm10.root macros/runexample_Optics1_sieve_100W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_100mm11.root macros/runexample_Optics1_sieve_100W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_100mm12.root macros/runexample_Optics1_sieve_100W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_100mm13.root macros/runexample_Optics1_sieve_100W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_100mm4.root macros/runexample_Optics1_sieve_100W.mac
