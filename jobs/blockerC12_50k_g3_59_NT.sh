#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_5.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_6.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_7.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_8.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_9.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
