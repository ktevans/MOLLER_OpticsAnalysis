#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm15.root macros/PT/runexample_Optics1_sieve_100BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm16.root macros/PT/runexample_Optics1_sieve_100BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm17.root macros/PT/runexample_Optics1_sieve_100BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm18.root macros/PT/runexample_Optics1_sieve_100BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_100mm19.root macros/PT/runexample_Optics1_sieve_100BT.mac
