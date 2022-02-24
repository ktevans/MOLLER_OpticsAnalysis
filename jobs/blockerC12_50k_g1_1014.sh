#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g1_10.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g1.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g1_11.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g1.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g1_12.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g1.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g1_13.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g1.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g1_14.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g1.mac
