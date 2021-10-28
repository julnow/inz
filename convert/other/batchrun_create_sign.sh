#!/bin/bash
LOGDIR=/lustre/cbm/users/$USER/ml/log
mkdir -p $LOGDIR
mkdir -p $LOGDIR/out
mkdir -p $LOGDIR/error

sbatch --job-name=sign \
        -t 01:00:00 \
        --partition main \
        --output=$LOGDIR/out/%j.out.log \
        --error=$LOGDIR/error/%j.err.log \
        --array 3000-3400 \
        -- $PWD/slurm_pfsimplecreate_sign.sh
