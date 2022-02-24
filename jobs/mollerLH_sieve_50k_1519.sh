#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/moller65uA_sieve_15.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_16.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_17.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_18.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_19.root macros/moller65uA_sieve.mac
