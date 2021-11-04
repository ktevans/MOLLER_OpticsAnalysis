#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm5.root macros/PT/runexample_Optics1_sieve_1W.mac
build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm6.root macros/PT/runexample_Optics1_sieve_1W.mac
build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm7.root macros/PT/runexample_Optics1_sieve_1W.mac
build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm8.root macros/PT/runexample_Optics1_sieve_1W.mac
build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm9.root macros/PT/runexample_Optics1_sieve_1W.mac

