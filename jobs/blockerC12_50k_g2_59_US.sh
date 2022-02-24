#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_US_g2_5.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g2_US.mac
build/remoll -o rootfilesPT/blocker_beamC12_US_g2_6.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g2_US.mac
build/remoll -o rootfilesPT/blocker_beamC12_US_g2_7.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g2_US.mac
build/remoll -o rootfilesPT/blocker_beamC12_US_g2_8.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g2_US.mac
build/remoll -o rootfilesPT/blocker_beamC12_US_g2_9.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g2_US.mac
