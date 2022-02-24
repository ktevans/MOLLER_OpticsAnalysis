#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_5.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_6.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_7.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_8.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_elasticC12_sieve_g2_9.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g2.mac
