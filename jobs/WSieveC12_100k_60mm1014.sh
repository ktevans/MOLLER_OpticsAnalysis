#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o WSieveC12_ep_100k_60mm_TightDets10.root macros/runexample_Optics1_WSieve_60mm.mac
build/remoll -o WSieveC12_ep_100k_60mm_TightDets11.root macros/runexample_Optics1_WSieve_60mm.mac
build/remoll -o WSieveC12_ep_100k_60mm_TightDets12.root macros/runexample_Optics1_WSieve_60mm.mac
build/remoll -o WSieveC12_ep_100k_60mm_TightDets13.root macros/runexample_Optics1_WSieve_60mm.mac
build/remoll -o WSieveC12_ep_100k_60mm_TightDets14.root macros/runexample_Optics1_WSieve_60mm.mac
