import sys; sys.path.append("/afs/cern.ch/user/i/ivovtin/HHggbb/HHbbggTraining/python")
#import matplotlib.pyplot as plt
import os
import random as rnd
from sklearn.utils.extmath import cartesian
import scipy.stats as stats
import random

# ---------------------------------------------------------------------------------------------------
class IO:
    #ldata = os.path.expanduser("/afs/cern.ch/work/i/ivovtin/public/Hggbb/")
    ldata = os.path.expanduser("/eos/user/i/ivovtin/HHggbb/HHbbggTraining/Training/input_files_with_cuts/")
    xdata = "/afs/cern.ch/user/i/ivovtin/HHggbb/HHbbggTraining/output_files/"
    plotFolder = os.path.expanduser("/eos/user/i/ivovtin/HHggbb/HHbbggTraining/Training/output_files/")
    signalName = []
    backgroundName = []
    dataName = []
    sigProc = []
    bkgProc = []
    dataProc = []
    nSig=0
    nBkg=0
    nData=0
    signal_df = []
    background_df = []
    data_df= []
    
    cross_sections = {}

    @staticmethod
    def add_signal(ntuples,sig, proc):
        IO.signalName.append(IO.ldata+ntuples+"/"+''.join(sig))
        IO.sigProc.append(proc)
        IO.nSig+=1
	
    @staticmethod
    def add_background(ntuples,bkg,proc):
        IO.backgroundName.append(IO.ldata+ntuples+"/"+''.join(bkg))
        IO.bkgProc.append(proc)
        IO.nBkg+=1
    
    @staticmethod
    def add_data(ntuples,data,proc):
        IO.dataName.append(IO.ldata+ntuples+"/"+''.join(data))
        IO.dataProc.append(proc)
        IO.nData+=1



    


