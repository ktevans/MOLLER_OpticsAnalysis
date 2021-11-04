#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -q 'scripts/PunchThru/ShortPunchThruNoise100Wep.C()'
build/reroot -l -q 'scripts/PunchThru/ShortPunchThruNoise110Wep.C()'
build/reroot -l -q 'scripts/PunchThru/ShortPunchThruNoise120Wep.C()'
