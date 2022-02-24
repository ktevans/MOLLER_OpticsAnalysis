#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamLH2_US_1mm_10.root macros/run_Optics1_blocker_beamLH2_50k_1mm_US.mac
build/remoll -o rootfilesPT/blocker_beamLH2_US_1mm_11.root macros/run_Optics1_blocker_beamLH2_50k_1mm_US.mac
build/remoll -o rootfilesPT/blocker_beamLH2_US_1mm_12.root macros/run_Optics1_blocker_beamLH2_50k_1mm_US.mac
build/remoll -o rootfilesPT/blocker_beamLH2_US_1mm_13.root macros/run_Optics1_blocker_beamLH2_50k_1mm_US.mac
build/remoll -o rootfilesPT/blocker_beamLH2_US_1mm_14.root macros/run_Optics1_blocker_beamLH2_50k_1mm_US.mac
