#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm0.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm1.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm2.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm3.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm4.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm5.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm6.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm7.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm8.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm9.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm10.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm11.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm12.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm13.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm14.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm15.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm16.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm17.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm18.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryAnalysis100mm19.C()'
