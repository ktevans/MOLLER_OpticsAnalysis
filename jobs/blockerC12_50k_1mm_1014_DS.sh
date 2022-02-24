#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_10.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_11.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_12.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_13.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_14.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
