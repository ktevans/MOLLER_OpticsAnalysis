#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_5_v2.root macros/run_Optics1_blocker_beamC12_50k_1mm_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_6_v2.root macros/run_Optics1_blocker_beamC12_50k_1mm_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_7_v2.root macros/run_Optics1_blocker_beamC12_50k_1mm_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_8_v2.root macros/run_Optics1_blocker_beamC12_50k_1mm_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_9_v2.root macros/run_Optics1_blocker_beamC12_50k_1mm_v2.mac
