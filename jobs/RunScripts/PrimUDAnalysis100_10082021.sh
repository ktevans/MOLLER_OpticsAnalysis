#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm0.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm1.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm2.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm3.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm4.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm5.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm6.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm7.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm8.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm9.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm10.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm11.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm12.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm13.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm14.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm15.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm16.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm17.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm18.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/PrimaryUDAnalysis100mm19.C()'
