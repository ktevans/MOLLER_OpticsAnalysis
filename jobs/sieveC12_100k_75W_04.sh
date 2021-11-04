#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_75mm0.root macros/PT/runexample_Optics1_sieve_75W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_75mm1.root macros/PT/runexample_Optics1_sieve_75W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_75mm2.root macros/PT/runexample_Optics1_sieve_75W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_75mm3.root macros/PT/runexample_Optics1_sieve_75W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_75mm4.root macros/PT/runexample_Optics1_sieve_75W.mac
