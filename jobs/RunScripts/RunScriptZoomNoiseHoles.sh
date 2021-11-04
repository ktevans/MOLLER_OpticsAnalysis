#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru70WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru70WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru75WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru75WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru80WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru80WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru85WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru85WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru90WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru90WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru95WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru95WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru100WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru100WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru105WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru105WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru110WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru110WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru115WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru115WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru120WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru120WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru125WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru125WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru130WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru130WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru135WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/ZoomPunchThru135WepHoles.C()'
