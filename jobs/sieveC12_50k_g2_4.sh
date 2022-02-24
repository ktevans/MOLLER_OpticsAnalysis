#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/sieve_elasticC12_sieve_g2_4.root macros/InnerBore/run_Optics1_sieve_elasticC12_50k_g2.mac

