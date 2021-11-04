#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/PunchThru/NewPunchThru40Wep.C()'
build/reroot -l -b -q 'scripts/PunchThru/NewPunchThru50Wep.C()'
build/reroot -l -b -q 'scripts/PunchThru/NewPunchThru60Wep.C()'
build/reroot -l -b -q 'scripts/PunchThru/NewPunchThru70Wep.C()'
build/reroot -l -b -q 'scripts/PunchThru/NewPunchThru80Wep.C()'
build/reroot -l -b -q 'scripts/PunchThru/NewPunchThru90Wep.C()'
build/reroot -l -b -q 'scripts/PunchThru/NewPunchThru100Wep.C()'
build/reroot -l -b -q 'scripts/PunchThru/NewPunchThru110Wep.C()'
build/reroot -l -b -q 'scripts/PunchThru/NewPunchThru120Wep.C()'
