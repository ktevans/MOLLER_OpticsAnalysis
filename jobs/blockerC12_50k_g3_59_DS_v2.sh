#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_5_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_6_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_7_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_8_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_9_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
