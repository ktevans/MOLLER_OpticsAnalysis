#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/PunchThru/PunchThru100WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru110WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru120WepNoise.C()'
