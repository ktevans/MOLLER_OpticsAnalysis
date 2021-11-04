#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve12HoleAnalysisAllCP.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve10HoleAnalysisAllCP.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve08HoleAnalysisAllCP.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve06HoleAnalysisAllCP.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve04HoleAnalysisAllCP.C()'
build/reroot -l -b -q 'scripts/HoleAnalysis/DetailedSieve02HoleAnalysisAllCP.C()'
