#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/David3/elasticC12_nosieve_10.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_11.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_12.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_13.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_14.root macros/David3_Optics1.mac
