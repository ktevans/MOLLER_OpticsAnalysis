#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru030.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru040.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru050.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru060.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru070.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru080.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru090.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru100.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru110.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerPrimaryPunchThru120.C()'
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
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru030.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru040.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru050.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru060.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru070.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru080.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru090.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru100.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru110.C()'
build/reroot -l -b -q 'scripts/Blocker/BlockerGammaPunchThru120.C()'
