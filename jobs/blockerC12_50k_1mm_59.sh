#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_elasticC12_1mm_5.root macros/run_Optics1_blocker_elasticC12_50k_1mm.mac
build/remoll -o rootfilesPT/blocker_elasticC12_1mm_6.root macros/run_Optics1_blocker_elasticC12_50k_1mm.mac
build/remoll -o rootfilesPT/blocker_elasticC12_1mm_7.root macros/run_Optics1_blocker_elasticC12_50k_1mm.mac
build/remoll -o rootfilesPT/blocker_elasticC12_1mm_8.root macros/run_Optics1_blocker_elasticC12_50k_1mm.mac
build/remoll -o rootfilesPT/blocker_elasticC12_1mm_9.root macros/run_Optics1_blocker_elasticC12_50k_1mm.mac
