#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_elasticC12_g3_15.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g3.mac
build/remoll -o rootfilesPT/blocker_elasticC12_g3_16.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g3.mac
build/remoll -o rootfilesPT/blocker_elasticC12_g3_17.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g3.mac
build/remoll -o rootfilesPT/blocker_elasticC12_g3_18.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g3.mac
build/remoll -o rootfilesPT/blocker_elasticC12_g3_19.root macros/InnerBore/run_Optics1_blocker_elasticC12_50k_g3.mac
