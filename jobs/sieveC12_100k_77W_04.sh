#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/WSieveC12_ep_100k_77mm0.root macros/runexample_Optics1_sieve_77W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_77mm1.root macros/runexample_Optics1_sieve_77W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_77mm2.root macros/runexample_Optics1_sieve_77W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_77mm3.root macros/runexample_Optics1_sieve_77W.mac
build/remoll -o rootfilesPT/WSieveC12_ep_100k_77mm4.root macros/runexample_Optics1_sieve_77W.mac
