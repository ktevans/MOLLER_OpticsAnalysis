#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/David4/elasticC12_sieve_15.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_16.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_17.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_18.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_19.root macros/David4_Optics1_sieve.mac
