#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm10.root macros/PT/runexample_Optics1_sieve_100BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm11.root macros/PT/runexample_Optics1_sieve_100BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm12.root macros/PT/runexample_Optics1_sieve_100BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm13.root macros/PT/runexample_Optics1_sieve_100BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm14.root macros/PT/runexample_Optics1_sieve_100BT.mac
