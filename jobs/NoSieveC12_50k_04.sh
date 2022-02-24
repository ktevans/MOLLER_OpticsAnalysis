#!/bin/bash
#SBATCH --mem=2G
#SBATCH --account=halla
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END
#SBATCH --time=90:00:00

build/remoll -o rootfilesPT/David3/elasticC12_nosieve_0.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_1.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_2.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_3.root macros/David3_Optics1.mac
build/remoll -o rootfilesPT/David3/elasticC12_nosieve_4.root macros/David3_Optics1.mac
