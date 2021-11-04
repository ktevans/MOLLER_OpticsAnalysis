#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis70.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis75.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis80.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis85.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis90.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis95.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis100.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis105.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis110.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis115.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis120.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis125.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis130.C()'
build/reroot -l -b -q 'scripts/EAnalysis/PrimaryEnergyAnalysis135.C()'


