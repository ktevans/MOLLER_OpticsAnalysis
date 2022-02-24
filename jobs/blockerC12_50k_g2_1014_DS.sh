#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_10.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_11.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_12.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_13.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_14.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
