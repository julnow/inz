#!/bin/bash

#remote work on AnalysisTree
source /lustre/cbm/users/lubynets/soft/root-6/install-cpp11/bin/thisroot.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lustre/cbm/users/$USER/AnalysisTree/install/lib/
export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:/lustre/cbm/users/$USER/AnalysisTree/install/include/AnalysisTree
#for Pf_simple
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lustre/cbm/users/$USER/pf_simple/install/external/lib/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lustre/cbm/users/$USER/pf_simple/install/lib/
export AnalysisTree_DIR=/lustre/cbm/users/$USER/AnalysisTree/install/lib/cmake/AnalysisTree

INDEX=${SLURM_ARRAY_TASK_ID}
WORK=/lustre/cbm/users/$USER
#path to pf simpled
pfpath=$WORK/pf_simple/main_bckgr
#path to simulated files

#splitting into 500 fileslist with 10 files
mkdir -p $PWD/fileslists
list=$PWD/fileslists/filelist_${INDEX}.txt
: >  $list
#for ((i=1+2*(INDEX-1); i<=1+2*INDEX; i++)); do
  #echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/urqmd_pluto/auau/12agev/mbias/sis100_electron_target_25_mkm/AT2/${i}/${i}.analysistree.root >>  $list
#  echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/urqmd_pluto/auau/3.3agev/mbias/sis100_electron_target_25_mkm_psd_v18e_p3.3_56/AT2/${i}/${i}.analysistree.root >>  $list
  #echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/dcmqgsm_smm_pluto/auau/12agev/mbias/sis100_electron_target_25_mkm/AT2/$i/$i.analysistree.root >>  $list
#done
echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/urqmd_pluto/auau/3.3agev/mbias/sis100_electron_target_25_mkm_psd_v18e_p3.3_56/AT2/${INDEX}/${INDEX}.analysistree.root >>  $list
mkdir -p $PWD/pfsimple/${INDEX}/bckgr
cd $PWD/pfsimple/${INDEX}/bckgr
#run pf_simple on each file
$pfpath $WORK/ml/fileslists/filelist_${INDEX}.txt
