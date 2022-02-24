#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_15.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_16.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_17.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_18.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_19.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
