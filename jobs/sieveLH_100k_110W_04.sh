#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesHT/WSieveLH_Moller_100k_110mm0.root macros/runexample_moller_110W.mac
build/remoll -o rootfilesHT/WSieveLH_Moller_100k_110mm1.root macros/runexample_moller_110W.mac
build/remoll -o rootfilesHT/WSieveLH_Moller_100k_110mm2.root macros/runexample_moller_110W.mac
build/remoll -o rootfilesHT/WSieveLH_Moller_100k_110mm3.root macros/runexample_moller_110W.mac
build/remoll -o rootfilesHT/WSieveLH_Moller_100k_110mm4.root macros/runexample_moller_110W.mac
