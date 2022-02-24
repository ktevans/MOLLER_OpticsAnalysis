#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_080mm10.root macros/PT/runexample_Optics1_sieve_080BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_080mm11.root macros/PT/runexample_Optics1_sieve_080BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_080mm12.root macros/PT/runexample_Optics1_sieve_080BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_080mm13.root macros/PT/runexample_Optics1_sieve_080BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_080mm14.root macros/PT/runexample_Optics1_sieve_080BT.mac
