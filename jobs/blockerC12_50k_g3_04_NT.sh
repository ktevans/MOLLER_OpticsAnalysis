#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_0.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_1.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_2.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_3.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
build/remoll -o rootfilesPT/blocker_beamC12_NT_g3_4.root macros/InnerBore/run_Optics1_blocker_beamC12_50k_g3_NT.mac
