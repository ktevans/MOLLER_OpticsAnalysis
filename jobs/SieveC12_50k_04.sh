#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/David4/elasticC12_sieve_0.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_1.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_2.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_3.root macros/David4_Optics1_sieve.mac
build/remoll -o rootfilesPT/David4/elasticC12_sieve_4.root macros/David4_Optics1_sieve.mac
