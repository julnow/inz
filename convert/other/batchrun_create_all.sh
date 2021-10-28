#!/bin/bash
LOGDIR=/lustre/cbm/users/$USER/ml/log
mkdir -p $LOGDIR
mkdir -p $LOGDIR/out
mkdir -p $LOGDIR/error

sbatch --job-name=all \
        -t 01:00:00 \
        --partition main \
        --output=$LOGDIR/out/%j.out.log \
        --error=$LOGDIR/error/%j.err.log \
        --array 2051-2100 \
        -- $PWD/slurm_pfsimplecreate_all.sh
