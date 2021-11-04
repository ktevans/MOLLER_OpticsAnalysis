#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/PunchThru/PunchThru90WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru90WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru95WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru95WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru100WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru100WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru105WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru105WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru110WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru110WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru115WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru115WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru120WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru120WepHoles.C()'
