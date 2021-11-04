#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/PunchThru/PunchThru75WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru75WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru85WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru85WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru95WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru95WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru105WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru105WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru115WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru115WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru125WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru125WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru130WepNoise.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru130WepHoles.C()'
build/reroot -l -b -q 'scripts/PunchThru/PunchThru135WepNoise.C()'
