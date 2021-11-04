#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/BWSieveC12_ep_100k_100mm20.root macros/PT/runexample_Optics1_sieve_100W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_100mm21.root macros/PT/runexample_Optics1_sieve_100W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_100mm22.root macros/PT/runexample_Optics1_sieve_100W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_100mm23.root macros/PT/runexample_Optics1_sieve_100W.mac
build/remoll -o rootfilesPT/BWSieveC12_ep_100k_100mm24.root macros/PT/runexample_Optics1_sieve_100W.mac
