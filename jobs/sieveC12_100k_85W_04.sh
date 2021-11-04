#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_85mm0.root macros/PT/runexample_Optics1_sieve_85W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_85mm1.root macros/PT/runexample_Optics1_sieve_85W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_85mm2.root macros/PT/runexample_Optics1_sieve_85W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_85mm3.root macros/PT/runexample_Optics1_sieve_85W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_85mm4.root macros/PT/runexample_Optics1_sieve_85W.mac
