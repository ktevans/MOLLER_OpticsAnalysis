#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm0.root macros/PT/runexample_Optics1_sieve_1W.mac
build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm1.root macros/PT/runexample_Optics1_sieve_1W.mac
build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm2.root macros/PT/runexample_Optics1_sieve_1W.mac
build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm3.root macros/PT/runexample_Optics1_sieve_1W.mac
build/remoll -o rootfiles/TEST_WSieveC12_ep_100k_1mm4.root macros/PT/runexample_Optics1_sieve_1W.mac

