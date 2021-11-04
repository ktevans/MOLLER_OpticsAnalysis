#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis70.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis75.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis80.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis85.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis90.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis95.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis100.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis105.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis110.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis115.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis120.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis125.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis130.C()'
build/reroot -l -b -q 'scripts/EAnalysis/EnergyAnalysis135.C()'



