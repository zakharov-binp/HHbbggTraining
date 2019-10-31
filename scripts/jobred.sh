#!/bin/bash
cd /afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_10_2_0/src/
#eval `cmsenv`
eval `scramv1 runtime -sh`
echo "CMSSW: "$CMSSW_BASE
cd /afs/cern.ch/user/i/ivovtin/HHggbb/HHbbggTraining/scripts/
#Run your program
ipython createReducedTrees_st_2016.py