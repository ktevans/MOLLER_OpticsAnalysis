#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamLH2_DS_g1_10_v2.root macros/run_Optics1_blocker_beamLH2_50k_g1_v2.mac
build/remoll -o rootfilesPT/blocker_beamLH2_DS_g1_11_v2.root macros/run_Optics1_blocker_beamLH2_50k_g1_v2.mac
build/remoll -o rootfilesPT/blocker_beamLH2_DS_g1_12_v2.root macros/run_Optics1_blocker_beamLH2_50k_g1_v2.mac
build/remoll -o rootfilesPT/blocker_beamLH2_DS_g1_13_v2.root macros/run_Optics1_blocker_beamLH2_50k_g1_v2.mac
build/remoll -o rootfilesPT/blocker_beamLH2_DS_g1_14_v2.root macros/run_Optics1_blocker_beamLH2_50k_g1_v2.mac
