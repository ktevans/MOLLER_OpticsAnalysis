#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=24:00:00
 
build/remoll -o rootfilesHA/HD02_sieveC12_ep_100k_100mm3.root macros/HoleAnalysis/Optics1_sieve100mm_100k_ep_HD02.mac
