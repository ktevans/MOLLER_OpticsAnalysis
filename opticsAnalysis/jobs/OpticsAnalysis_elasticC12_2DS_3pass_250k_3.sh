#!/bin/bash
#SBATCH --account=halla
#SBATCH --mem-per-cpu=5000
#SBATCH --exclude=farm19104,farm19105,farm19106,farm19107,farm1996,farm19101
#SBATCH --partition=production
#SBATCH --mail-user=ktevans@jlab.org
#SBATCH --mail-type=END

#build/remoll -o rootfilesPT/Optics2DS_3pass_elasticC12_250k_0.root opticsAnalysis/macros/3pass_Optics2DS_sieve_250k.mac
#build/remoll -o rootfilesPT/Optics2DS_3pass_elasticC12_250k_1.root opticsAnalysis/macros/3pass_Optics2DS_sieve_250k.mac
#build/remoll -o rootfilesPT/Optics2DS_3pass_elasticC12_250k_2.root opticsAnalysis/macros/3pass_Optics2DS_sieve_250k.mac
build/remoll -o rootfilesPT/Optics2DS_3pass_elasticC12_250k_3.root opticsAnalysis/macros/3pass_Optics2DS_sieve_250k.mac
#build/remoll -o rootfilesPT/Optics2DS_3pass_elasticC12_250k_4.root opticsAnalysis/macros/3pass_Optics2DS_sieve_250k.mac

