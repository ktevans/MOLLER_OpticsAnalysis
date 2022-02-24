#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/moller65uA_sieve_5.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_6.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_7.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_8.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_9.root macros/moller65uA_sieve.mac
