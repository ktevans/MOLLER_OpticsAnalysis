#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_0.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_1.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_2.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_3.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_1mm_4.root macros/run_Optics1_blocker_beamC12_50k_1mm_DS.mac
