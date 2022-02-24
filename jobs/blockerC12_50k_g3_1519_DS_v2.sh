#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_15_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_16_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_17_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_18_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g3_19_v2.root macros/run_Optics1_blocker_beamC12_50k_g3_v2.mac
