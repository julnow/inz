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
        --array 2501-2510 \
        -- $PWD/slurm_attree_all.sh
