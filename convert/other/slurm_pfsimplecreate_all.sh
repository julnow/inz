#!/bin/bash

#remote work on AnalysisTree
source /cvmfs/fairsoft.gsi.de/debian10/fairsoft/jun19p2/bin/thisroot.sh
export AnalysisTree_DIR=/lustre/cbm/users/lubynets/soft/AnalysisTree_2/install_cpp11_debian10/lib/cmake/AnalysisTree/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lustre/cbm/users/lubynets/soft/AnalysisTree_2/install_cpp11_debian10/lib/
export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:/lustre/cbm/users/lubynets/soft/AnalysisTree_2/install_cpp11_debian10/include/AnalysisTree
#for Pf_simple
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lustre/cbm/users/$USER/pf_simple/external/lib/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lustre/cbm/users/$USER/pf_simple/lib/

INDEX=${SLURM_ARRAY_TASK_ID}
WORK=/lustre/cbm/users/$USER
#path to pf simpled
pfpath=$WORK/pf_simple/main_all
#path to simulated files

#splitting into 500 fileslist with 10 files
mkdir -p $PWD/fileslists
list=$PWD/fileslists/filelist_${INDEX}.txt
: >  $list
#for ((i=1+5*(INDEX-1); i<=5*INDEX; i++)); do
#  echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/urqmd_pluto/auau/3.3agev/mbias/sis100_electron_target_25_mkm_psd_v18e_p3.3_56/AT2/${i}/${i}.analysistree.root >>  $list
  #echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/dcmqgsm_smm_pluto/auau/12agev/mbias/sis100_electron_target_25_mkm/AT2/$i/$i.analysistree.root >>  $list
#done
echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/dcmqgsm_smm_pluto/auau/12agev/mbias/sis100_electron_target_25_mkm/AT2/${INDEX}/${INDEX}.analysistree.root >>  $list
#echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/dcmqgsm_smm_pluto/auau/3.3agev/mbias/sis100_electron_target_25_mkm_psd_v18e_p3.3_56/AT2/${INDEX}/${INDEX}.analysistree.root >>  $list
# 27.5% magnetic field
#cho /lustre/cbm/users/iselyuzh/mc/cbmsim/apr20_fr_18.2.1_fs_jun19p1/dcmqgsm_smm_pluto_w/auau/3.3agev/mbias/sis100_electron_target_25_mkm_MF_27.5/TGeant4/atree/${INDEX}.analysistree.root >>  $list
#57.5% magnetic field
#echo /lustre/cbm/users/iselyuzh/mc/cbmsim/apr20_fr_18.2.1_fs_jun19p1/dcmqgsm_smm/auau/3.3agev/mbias/sis100_electron_target_25_mkm_psd_v18e_p3.3_56_MF_56/TGeant4/atree/${INDEX}.analysistree.root >>  $list
#echo /lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/dcmqgsm_smm_pluto/auau/12agev/mbias/sis100_electron_target_25_mkm/AT2/${INDEX}/${INDEX}.analysistree.root >>  $list
mkdir -p $PWD/pfsimple/${INDEX}/all
cd $PWD/pfsimple/${INDEX}/all
#run pf_simple on each file
$pfpath $WORK/ml/fileslists/filelist_${INDEX}.txt
