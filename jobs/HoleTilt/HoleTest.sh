#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=24:00:00


build/remoll -o rootfiles/test_Execute_Macro.root macros/runexample_Optics1_sieve_110W_Macro.mac
