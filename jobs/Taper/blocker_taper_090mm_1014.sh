#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_090mm10.root macros/PT/runexample_Optics1_sieve_090BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_090mm11.root macros/PT/runexample_Optics1_sieve_090BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_090mm12.root macros/PT/runexample_Optics1_sieve_090BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_090mm13.root macros/PT/runexample_Optics1_sieve_090BT.mac
build/remoll -o rootfilesPT/blocker/TWBlockerC12_ep_100k_090mm14.root macros/PT/runexample_Optics1_sieve_090BT.mac
