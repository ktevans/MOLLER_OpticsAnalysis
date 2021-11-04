#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru030.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru040.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru050.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru060.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru070.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru080.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru090.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru100.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru110.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPunchThru120.C()'
