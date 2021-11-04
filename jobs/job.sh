#!/bin/bash
#SBATCH --mem=4G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=01:10:00

echo "Hello, World!" 
build/remoll -o remollout_sieve_10k_virtPlanes.root macros/runexample.mac
