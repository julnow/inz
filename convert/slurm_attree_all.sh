#!/bin/bash

#using cp17 root, analysis tree and my at_tree_plainer
source /lustre/cbm/users/lubynets/soft/root-6/install_6.20_cpp17_debian10/bin/thisroot.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lustre/cbm/users/jnowak/AnalysisTree/install/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lustre/cbm/users/jnowak/at_tree_plainer/install/lib/

INDEX=${SLURM_ARRAY_TASK_ID}
WORK=/lustre/cbm/users/$USER
#path to pf simpled
pfpath=$WORK/at_tree_plainer/main
#path to simulated files

#splitting into 500 fileslist with 10 files
mkdir -p $PWD/fileslists
list=$PWD/fileslists/filelist_${INDEX}.txt
: >  $list
echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/dcmqgsm_smm_pluto/auau/12agev/mbias/sis100_electron_target_25_mkm/AT2/${INDEX}/${INDEX}.analysistree.root >>  $list

mkdir -p $PWD/at_tree/${INDEX}
cd $PWD/at_tree/${INDEX}
#run pf_simple on each file
$pfpath $WORK/ml/fileslists/filelist_${INDEX}.txt
rm intermediate_tree.root filelist.txt
