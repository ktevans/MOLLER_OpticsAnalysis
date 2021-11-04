#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPrimaryPunchThru040.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPrimaryPunchThru050.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPrimaryPunchThru060.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPrimaryPunchThru070.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPrimaryPunchThru080.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPrimaryPunchThru090.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPrimaryPunchThru100.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPrimaryPunchThru110.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPrimaryPunchThru120.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPunchThru040.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPunchThru050.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPunchThru060.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPunchThru070.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPunchThru080.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPunchThru090.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPunchThru100.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPunchThru110.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/BlockerPunchThru120.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/GammaBlockerPunchThru040.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/GammaBlockerPunchThru050.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/GammaBlockerPunchThru060.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/GammaBlockerPunchThru070.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/GammaBlockerPunchThru080.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/GammaBlockerPunchThru090.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/GammaBlockerPunchThru100.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/GammaBlockerPunchThru110.C()'
build/reroot -l -b -q 'scripts/Blocker/InnerHoleTaper/GammaBlockerPunchThru120.C()'
