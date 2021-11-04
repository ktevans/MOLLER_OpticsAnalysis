#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=24:00:00
 
build/remoll -o rootfilesHA/HD06_sieveC12_ep_100k_100mm1.root macros/HoleAnalysis/Optics1_sieve100mm_100k_ep_HD06.mac
