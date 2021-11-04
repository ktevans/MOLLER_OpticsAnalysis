#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=24:00:00

build/remoll -o rootfilesPT/NoSieveC12_ep_100k_100mm17.root macros/PT/runexample_Optics1_no_sieve_100.mac
