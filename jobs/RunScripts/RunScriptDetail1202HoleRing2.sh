#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve12HoleAnalysisRing2.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve10HoleAnalysisRing2.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve08HoleAnalysisRing2.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve06HoleAnalysisRing2.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve04HoleAnalysisRing2.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve02HoleAnalysisRing2.C()'
