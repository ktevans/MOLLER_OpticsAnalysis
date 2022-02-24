#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_10_v2.root macros/run_Optics1_blocker_beamC12_50k_g2_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_11_v2.root macros/run_Optics1_blocker_beamC12_50k_g2_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_12_v2.root macros/run_Optics1_blocker_beamC12_50k_g2_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_13_v2.root macros/run_Optics1_blocker_beamC12_50k_g2_v2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_14_v2.root macros/run_Optics1_blocker_beamC12_50k_g2_v2.mac
