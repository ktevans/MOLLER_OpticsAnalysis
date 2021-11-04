#!/bin/bash
#SBATCH --mem=1G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=00:10:00

echo "Hello, World!" 

# specify a specific geometry and output file name. Make sure those aren't specified in the macro.
build/remoll -o remollout_${1}.root -g geometry/${1}.gdml macros/runexample_Optics1.mac
