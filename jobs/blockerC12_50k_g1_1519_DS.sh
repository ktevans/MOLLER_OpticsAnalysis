#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_DS_g1_15.root macros/run_Optics1_blocker_beamC12_50k_g1.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g1_16.root macros/run_Optics1_blocker_beamC12_50k_g1.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g1_17.root macros/run_Optics1_blocker_beamC12_50k_g1.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g1_18.root macros/run_Optics1_blocker_beamC12_50k_g1.mac
build/remoll -o rootfilesPT/blocker_beamC12_DS_g1_19.root macros/run_Optics1_blocker_beamC12_50k_g1.mac
