#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/moller65uA_sieve_10.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_11.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_12.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_13.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_14.root macros/moller65uA_sieve.mac
