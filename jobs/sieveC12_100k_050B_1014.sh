#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00
 
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_050mm10.root macros/PT/runexample_Optics1_sieve_050B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_050mm11.root macros/PT/runexample_Optics1_sieve_050B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_050mm12.root macros/PT/runexample_Optics1_sieve_050B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_050mm13.root macros/PT/runexample_Optics1_sieve_050B.mac
build/remoll -o rootfilesPT/blocker/WBlockerC12_ep_100k_050mm14.root macros/PT/runexample_Optics1_sieve_050B.mac
