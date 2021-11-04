#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm0.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm1.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm3.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm4.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm5.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm6.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm7.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm8.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm9.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm10.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm11.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm12.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm13.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm14.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm15.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm16.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm17.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm18.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/MollerPrimaryAnalysis100mm19.C()'

build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm0.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm1.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm2.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm3.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm4.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm5.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm6.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm7.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm8.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm9.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm10.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm11.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm12.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm13.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm14.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm15.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm16.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm17.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm18.C()'
build/reroot -l -b -q 'scripts/PrimAnalysis/ElasticPrimaryAnalysis100mm19.C()'

