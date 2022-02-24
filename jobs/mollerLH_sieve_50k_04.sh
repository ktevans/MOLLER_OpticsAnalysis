#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/moller65uA_sieve_0.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_1.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_2.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_3.root macros/moller65uA_sieve.mac
build/remoll -o rootfilesPT/moller65uA_sieve_4.root macros/moller65uA_sieve.mac
