#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_10.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_11.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_12.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_13.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_14.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
