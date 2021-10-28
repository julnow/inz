#!/bin/#!/usr/bin/env bash

#compile files in list
mkdir comparison
for path in ~/pf_results/lambda/*/pfinput.root
do
  #echo $path
  folder=${path#~/pf_results/lambda/}
  folder=${folder%/pfinput.root}
  #echo $folder

  output=comparison/$folder".root"
  root -l -b -q "pfRead.c(\"$path\", \"$output\")"
done
~/comparerootfiles/build/compareRootFiles -i comparison/*
