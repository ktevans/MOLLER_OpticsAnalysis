#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/HoleAnalysis/NewDetailedSieve12HoleAnalysisRing2x.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/NewDetailedSieve10HoleAnalysisRing2x.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/NewDetailedSieve08HoleAnalysisRing2x.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/NewDetailedSieve06HoleAnalysisRing2x.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/NewDetailedSieve04HoleAnalysisRing2x.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/NewDetailedSieve02HoleAnalysisRing2x.C()'
