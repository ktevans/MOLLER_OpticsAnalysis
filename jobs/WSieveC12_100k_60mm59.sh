#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o WSieveC12_ep_100k_60mm_TightDets5.root macros/runexample_Optics1_WSieve_60mm.mac
build/remoll -o WSieveC12_ep_100k_60mm_TightDets6.root macros/runexample_Optics1_WSieve_60mm.mac
build/remoll -o WSieveC12_ep_100k_60mm_TightDets7.root macros/runexample_Optics1_WSieve_60mm.mac
build/remoll -o WSieveC12_ep_100k_60mm_TightDets8.root macros/runexample_Optics1_WSieve_60mm.mac
build/remoll -o WSieveC12_ep_100k_60mm_TightDets9.root macros/runexample_Optics1_WSieve_60mm.mac
