#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/David4/elasticC12_sieve_10.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_11.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_12.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_13.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_14.root macros/David4_Optics1_sieve.mac
