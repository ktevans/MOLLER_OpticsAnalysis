#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=30:00:00

build/reroot -l -b -q 'scripts/Lauren/ElectronsMain_taper_03_min_Ring2.C()'
build/reroot -l -b -q 'scripts/Lauren/ElectronsMain_taper_03_max_Ring2.C()'
build/reroot -l -b -q 'scripts/Lauren/PrimariesMain_taper_03_min_Ring2.C()'
build/reroot -l -b -q 'scripts/Lauren/PrimariesMain_taper_03_max_Ring2.C()'
