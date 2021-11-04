#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o sieveLH_moller_100k_100mm_05in_5.root macros/HoleTilt_moller_100mm.mac
build/remoll -o sieveLH_moller_100k_100mm_05in_6.root macros/HoleTilt_moller_100mm.mac
build/remoll -o sieveLH_moller_100k_100mm_05in_7.root macros/HoleTilt_moller_100mm.mac
build/remoll -o sieveLH_moller_100k_100mm_05in_8.root macros/HoleTilt_moller_100mm.mac
build/remoll -o sieveLH_moller_100k_100mm_05in_9.root macros/HoleTilt_moller_100mm.mac
