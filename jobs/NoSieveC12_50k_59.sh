#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/David3/elasticC12_nosieve_15.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_16.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_17.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_18.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_19.root macros/David3_Optics1.mac
