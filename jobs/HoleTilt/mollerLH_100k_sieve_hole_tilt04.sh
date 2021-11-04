#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o sieveLH_moller_100k_100mm_05in_0.root macros/HoleTilt_moller_100mm.mac
build/remoll -o sieveLH_moller_100k_100mm_05in_1.root macros/HoleTilt_moller_100mm.mac
build/remoll -o sieveLH_moller_100k_100mm_05in_2.root macros/HoleTilt_moller_100mm.mac
build/remoll -o sieveLH_moller_100k_100mm_05in_3.root macros/HoleTilt_moller_100mm.mac
build/remoll -o sieveLH_moller_100k_100mm_05in_4.root macros/HoleTilt_moller_100mm.mac
