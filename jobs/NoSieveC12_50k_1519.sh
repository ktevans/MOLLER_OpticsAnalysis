#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/David3/elasticC12_nosieve_5.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_6.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_7.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_8.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_9.root macros/David3_Optics1.mac
