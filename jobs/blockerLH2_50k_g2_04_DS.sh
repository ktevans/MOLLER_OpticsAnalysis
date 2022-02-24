#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamLH2_DS_g2_0.root macros/InnerBore/run_Optics1_blocker_beamLH2_50k_g2_DS.mac
build/remoll -o rootfilesPT/blocker_beamLH2_DS_g2_1.root macros/InnerBore/run_Optics1_blocker_beamLH2_50k_g2_DS.mac
build/remoll -o rootfilesPT/blocker_beamLH2_DS_g2_2.root macros/InnerBore/run_Optics1_blocker_beamLH2_50k_g2_DS.mac
build/remoll -o rootfilesPT/blocker_beamLH2_DS_g2_3.root macros/InnerBore/run_Optics1_blocker_beamLH2_50k_g2_DS.mac
build/remoll -o rootfilesPT/blocker_beamLH2_DS_g2_4.root macros/InnerBore/run_Optics1_blocker_beamLH2_50k_g2_DS.mac
