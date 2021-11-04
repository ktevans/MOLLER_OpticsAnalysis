#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve12HoleAnalysis.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve10HoleAnalysis.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve08HoleAnalysis.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve06HoleAnalysis.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve04HoleAnalysis.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve02HoleAnalysis.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve12HoleAnalysisSep.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve10HoleAnalysisSep.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve08HoleAnalysisSep.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve06HoleAnalysisSep.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve04HoleAnalysisSep.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve02HoleAnalysisSep.C()'
