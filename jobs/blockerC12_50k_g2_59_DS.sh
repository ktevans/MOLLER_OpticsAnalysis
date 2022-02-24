#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_5.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_6.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_7.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_8.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g2_9.root macros/run_Optics1_blocker_beamC12_50k_g2.mac
