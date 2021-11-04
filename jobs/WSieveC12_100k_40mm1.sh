#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=24:00:00

build/remoll -o WSieveC12_ep_100k_40mm1.root macros/runexample_Optics1_WSieve_40mm.mac
