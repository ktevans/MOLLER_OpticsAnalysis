#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/David4/elasticC12_sieve_5.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_6.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_7.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_8.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_9.root macros/David4_Optics1_sieve.mac
