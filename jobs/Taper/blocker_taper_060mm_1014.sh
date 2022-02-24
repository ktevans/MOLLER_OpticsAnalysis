#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_060mm10.root macros/PT/runexample_Optics1_sieve_060BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_060mm11.root macros/PT/runexample_Optics1_sieve_060BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_060mm12.root macros/PT/runexample_Optics1_sieve_060BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_060mm13.root macros/PT/runexample_Optics1_sieve_060BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_060mm14.root macros/PT/runexample_Optics1_sieve_060BT.mac
