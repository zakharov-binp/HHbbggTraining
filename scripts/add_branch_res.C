void add_branch_res()
{  
   TString indirFT = "/afs/cern.ch/work/i/ivovtin/Hggbb/legacy_branch_flattrees/flattrees_2018_withdR/";
   TString outdirFT = "/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/rho_rew_2018_v2/";
   //TString outdirFT = "/eos/user/i/ivovtin/HHggbb/";
   TString indirtrMVA = "/afs/cern.ch/work/i/ivovtin/Hggbb/";
   TString fnameAll = indirtrMVA + "legacy_branch_flattrees/reduceTree_rho_rew_2018/Total_preselection_diffNaming_transformedMVA.root"; 

   //2016
   //TString GJet_Pt1 = "output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root";
   //TString GJet_Pt2 = "output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root";
   //2017 and 2018
   TString GJet_Pt1 = "output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root";
   TString GJet_Pt2 = "output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root";

   //==========================================

   TFile *inputAll = TFile::Open(fnameAll);
   TTree *sigtree = (TTree*)inputAll->Get("reducedTree_sig");            //MC signal                                    121837
   TTree *datatree = (TTree*)inputAll->Get("reducedTree_bkg");           //data                                         269198
   //MC BkGs                        
   TTree *bkg0tree = (TTree*)inputAll->Get("reducedTree_bkg_0");     //DiPhotonJetsBox                                   1482238     
   //TTree *bkg1tree = (TTree*)inputAll->Get("reducedTree_bkg_1");     // not                                            
   TTree *bkg2tree = (TTree*)inputAll->Get("reducedTree_bkg_2");     //GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8 + GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8                                                     75721
   TTree *bkg3tree = (TTree*)inputAll->Get("reducedTree_bkg_3");     //GluGluHToGG_M-125_13TeV_powheg_pythia8            33021                   
   TTree *bkg4tree = (TTree*)inputAll->Get("reducedTree_bkg_4");     //VBFHToGG_M-125_13TeV_powheg_pythia8               47547                 
   TTree *bkg5tree = (TTree*)inputAll->Get("reducedTree_bkg_5");     //VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8   105490                           
   TTree *bkg6tree = (TTree*)inputAll->Get("reducedTree_bkg_6");     //bHToGG_M-125_4FS_yb2_13TeV_amcatnlo               11250                  
   TTree *bkg7tree = (TTree*)inputAll->Get("reducedTree_bkg_7");     //ttHToGG_M125_13TeV_powheg_pythia8                414581                     
   TTree *bkg9tree = (TTree*)inputAll->Get("reducedTree_bkg_8");    //GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8               1262           
   TTree *bkg10tree = (TTree*)inputAll->Get("reducedTree_bkg_9");  //GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8             74459             
   TTree *bkg11tree = (TTree*)inputAll->Get("reducedTree_bkg_10");  //bbHToGG_M-125_4FS_ybyt_13TeV_amcatnlo                    

   float MVASig,MVAData,MVA0,MVA1,MVA2,MVA3,MVA4,MVA5,MVA6,MVA7,MVA8,MVA9,MVA10,MVA11;
   float MVAoldSig,MVAoldData,MVAold0,MVAold1,MVAold2,MVAold3,MVAold4,MVAold5,MVAold6,MVAold7,MVAold8,MVAold9,MVAold10,MVAold11;
   float MVASigTr,MVADataTr,MVA0Tr,MVA1Tr,MVA2Tr,MVA3Tr,MVA4Tr,MVA5Tr,MVA6Tr,MVA7Tr,MVA8Tr,MVA9Tr,MVA10Tr,MVA11Tr;
   float MVAoldSigTr,MVAoldDataTr,MVAold0Tr,MVAold1Tr,MVAold2Tr,MVAold3Tr,MVAold4Tr,MVAold5Tr,MVAold6Tr,MVAold7Tr,MVAold8Tr,MVAold9Tr,MVAold10Tr,MVAold11Tr;
   
   //TString fnameSig = indirFT + "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root"; 
   //TString fnameSig = indirFT + "output_GluGluToHHTo2B2G_allnodes.root"; 
   TString fnameSig = indirFT + "output_GluGluToHHTo2B2G_allnodes_2018_no_unit_norm.root"; 
   TString fnamedata = indirFT + "Data.root"; 
   //bkg
   TString fname0 = indirFT + "output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root"; 
   TString fname3 = indirFT + "output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root"; 
   TString fname4 = indirFT + "output_VBFHToGG_M-125_13TeV_powheg_pythia8.root"; 
   TString fname5 = indirFT + "output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"; 
   TString fname6 = indirFT + "output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo.root";           
   TString fname7 = indirFT + "output_ttHToGG_M125_13TeV_powheg_pythia8.root"; 
   TString fname9 = indirFT + GJet_Pt1; 
   TString fname10 = indirFT + GJet_Pt2;
   TString fname11 = indirFT + "output_bbHToGG_M-125_4FS_ybyt_13TeV_amcatnlo.root"; 
   
   
   TFile *inputSig = TFile::Open(fnameSig);
   TTree *MCSigTree1 = (TTree*)inputSig->Get("bbggSelectionTree");                                     
  
   TFile *inputData = TFile::Open(fnamedata);
   TTree *Daratree1 = (TTree*)inputData->Get("bbggSelectionTree");                                     

   //0 - DiPhotonJetsBox
   TFile *input0 = TFile::Open(fname0);
   TTree *MCBkgTree0 = (TTree*)input0->Get("bbggSelectionTree");                                     
   //2 -  GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8 + GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8                                  
   TChain* MCBkgTree2 = new TChain("MCBkgTree8","MCBkgTree8");

   MCBkgTree2->Add(indirFT + GJet_Pt1 + "/bbggSelectionTree");    
   MCBkgTree2->Add(indirFT + GJet_Pt2 + "/bbggSelectionTree");                                                                             
   //3 - GluGluHToGG_M-125_13TeV_powheg_pythia8
   TFile *input3 = TFile::Open(fname3);
   TTree *MCBkgTree3 = (TTree*)input3->Get("bbggSelectionTree");  
   //4 - VBFHToGG_M-125_13TeV_powheg_pythia8
   TFile *input4 = TFile::Open(fname4);
   TTree *MCBkgTree4 = (TTree*)input4->Get("bbggSelectionTree");                                     
   //5 - VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8
   TFile *input5 = TFile::Open(fname5);
   TTree *MCBkgTree5 = (TTree*)input5->Get("bbggSelectionTree");                                        
   //6 - bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo
   TFile *input6 = TFile::Open(fname6);
   TTree *MCBkgTree6 = (TTree*)input6->Get("bbggSelectionTree");                                        
   //7 - ttHToGG_M125_13TeV_powheg_pythia8
   TFile *input7 = TFile::Open(fname7);
   TTree *MCBkgTree7 = (TTree*)input7->Get("bbggSelectionTree");                                        
   //9 - GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8
   TFile *input9 = TFile::Open(fname9);
   TTree *MCBkgTree9 = (TTree*)input9->Get("bbggSelectionTree");                                     
   //10 - GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8
   TFile *input10 = TFile::Open(fname10);
   TTree *MCBkgTree10 = (TTree*)input10->Get("bbggSelectionTree");                                     
   //11 - output_bbHToGG_M-125_4FS_ybyt_13TeV_amcatnlo.root
   TFile *input11 = TFile::Open(fname11);
   TTree *MCBkgTree11 = (TTree*)input11->Get("bbggSelectionTree");                                     
   

   //3 change
   //Signal
   //TFile *newfileSig = new TFile(outdirFT + "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root","recreate");   
   TFile *newfileSig = new TFile(outdirFT + "output_GluGluToHHTo2B2G_allnodes_no_unit_norm.root","recreate");   
   TTree *newtreeSig = MCSigTree1->CloneTree();   
   TBranch *brMVASig = newtreeSig->Branch("MVAOutputTransformed",&MVASig,"MVAOutputTransformed/F"); 
   sigtree->SetBranchAddress("MVAOutputTransformed",&MVAoldSig); 
   Long64_t nentriesSig = newtreeSig->GetEntries(); 
   for (Long64_t i=0; i<nentriesSig; i++) 
   { 
     newtreeSig->GetEntry(i); 
     sigtree->GetEntry(i); 
     
     MVASig=MVAoldSig;      
     brMVASig->Fill();  
   }     
   newtreeSig->Print();       
   newfileSig->Write();
   newfileSig->Close();

   //Data
   TFile *newfileData = new TFile(outdirFT + "Data.root","recreate");   
   TTree *newtreeData = Daratree1->CloneTree();   
   TBranch *brMVAData = newtreeData->Branch("MVAOutputTransformed",&MVAData,"MVAOutputTransformed/F"); 
   datatree->SetBranchAddress("MVAOutputTransformed",&MVAoldData); 
   Long64_t nentriesData = newtreeData->GetEntries(); 
   for (Long64_t i=0; i<nentriesData; i++) 
   { 
     newtreeData->GetEntry(i); 
     datatree->GetEntry(i); 
     
     MVAData=MVAoldData;      
     brMVAData->Fill();  
   }     
   newtreeData->Print();       
   newfileData->Write();
   newfileData->Close();

   //BkG 0 - DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa
   TFile *newfile0 = new TFile(outdirFT + "output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root","recreate");   
   TTree *newtree0 = MCBkgTree0->CloneTree();   
   TBranch *brMVA0 = newtree0->Branch("MVAOutputTransformed",&MVA0,"MVAOutputTransformed/F"); 
   bkg0tree->SetBranchAddress("MVAOutputTransformed",&MVAold0); 
   Long64_t nentries0 = newtree0->GetEntries(); 
   for (Long64_t i=0; i<nentries0; i++) 
   { 
     newtree0->GetEntry(i); 
     bkg0tree->GetEntry(i); 
     
     MVA0=MVAold0;      
     brMVA0->Fill();  
   }     
   newtree0->Print();       
   newfile0->Write();
   newfile0->Close();
   
   //BkG 2 - GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8
   TFile *newfile2 = new TFile(outdirFT + "output_GJet_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root","recreate");   
   TTree *newtree2 = MCBkgTree2->CloneTree();   
   TBranch *brMVA2 = newtree2->Branch("MVAOutputTransformed",&MVA2,"MVAOutputTransformed/F"); 
   bkg2tree->SetBranchAddress("MVAOutputTransformed",&MVAold2); 
   Long64_t nentries2 = newtree2->GetEntries(); 
   for (Long64_t i=0; i<nentries2; i++) 
   { 
     newtree2->GetEntry(i); 
     bkg2tree->GetEntry(i); 
     
     MVA2=MVAold2;      
     brMVA2->Fill();  
   }     
   newtree2->Print();       
   newfile2->Write();
   newfile2->Close();
   
   //BkG 3 - GluGluHToGG_M-125_13TeV_powheg_pythia8
   TFile *newfile3 = new TFile(outdirFT + "output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root","recreate");   
   TTree *newtree3 = MCBkgTree3->CloneTree();   
   TBranch *brMVA3 = newtree3->Branch("MVAOutputTransformed",&MVA3,"MVAOutputTransformed/F"); 
   bkg3tree->SetBranchAddress("MVAOutputTransformed",&MVAold3); 
   Long64_t nentries3 = newtree3->GetEntries(); 
   for (Long64_t i=0; i<nentries3; i++) 
   { 
     newtree3->GetEntry(i); 
     bkg3tree->GetEntry(i); 
     
     MVA3=MVAold3;      
     brMVA3->Fill();  
   }     
   newtree3->Print();       
   newfile3->Write();
   newfile3->Close();

   //BkG 4 - VBFHToGG_M-125_13TeV_powheg_pythia8
   TFile *newfile4 = new TFile(outdirFT + "output_VBFHToGG_M-125_13TeV_powheg_pythia8.root","recreate");   
   TTree *newtree4 = MCBkgTree4->CloneTree();   
   TBranch *brMVA4 = newtree4->Branch("MVAOutputTransformed",&MVA4,"MVAOutputTransformed/F"); 
   bkg4tree->SetBranchAddress("MVAOutputTransformed",&MVAold4); 
   Long64_t nentries4 = newtree4->GetEntries(); 
   for (Long64_t i=0; i<nentries4; i++) 
   { 
     newtree4->GetEntry(i); 
     bkg4tree->GetEntry(i); 
     
     MVA4=MVAold4;      
     brMVA4->Fill();  
   }     
   newtree4->Print();       
   newfile4->Write();
   newfile4->Close();

   //BkG 5 - VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8
   TFile *newfile5 = new TFile(outdirFT + "output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root","recreate");   
   TTree *newtree5 = MCBkgTree5->CloneTree();   
   TBranch *brMVA5 = newtree5->Branch("MVAOutputTransformed",&MVA5,"MVAOutputTransformed/F"); 
   bkg5tree->SetBranchAddress("MVAOutputTransformed",&MVAold5); 
   Long64_t nentries5 = newtree5->GetEntries(); 
   for (Long64_t i=0; i<nentries5; i++) 
   { 
     newtree5->GetEntry(i); 
     bkg5tree->GetEntry(i); 
     
     MVA5=MVAold5;      
     brMVA5->Fill();  
   }     
   newtree5->Print();       
   newfile5->Write();
   newfile5->Close();

   //BkG 6 - bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo
   TFile *newfile6 = new TFile(outdirFT + "output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo.root","recreate");   
   TTree *newtree6 = MCBkgTree6->CloneTree();   
   TBranch *brMVA6 = newtree6->Branch("MVAOutputTransformed",&MVA6,"MVAOutputTransformed/F"); 
   bkg6tree->SetBranchAddress("MVAOutputTransformed",&MVAold6); 
   Long64_t nentries6 = newtree6->GetEntries(); 
   for (Long64_t i=0; i<nentries6; i++) 
   { 
     newtree6->GetEntry(i); 
     bkg6tree->GetEntry(i); 
     
     MVA6=MVAold6;      
     brMVA6->Fill();  
   }     
   newtree6->Print();       
   newfile6->Write();
   newfile6->Close();

   //BkG 7 - ttHToGG_M125_13TeV_powheg_pythia8
   TFile *newfile7 = new TFile(outdirFT + "output_ttHToGG_M125_13TeV_powheg_pythia8.root","recreate");   
   TTree *newtree7 = MCBkgTree7->CloneTree();   
   TBranch *brMVA7 = newtree7->Branch("MVAOutputTransformed",&MVA7,"MVAOutputTransformed/F"); 
   bkg7tree->SetBranchAddress("MVAOutputTransformed",&MVAold7); 
   Long64_t nentries7 = newtree7->GetEntries(); 
   for (Long64_t i=0; i<nentries7; i++) 
   { 
     newtree7->GetEntry(i); 
     bkg7tree->GetEntry(i); 
     
     MVA7=MVAold7;      
     brMVA7->Fill();  
   }     
   newtree7->Print();       
   newfile7->Write();
   newfile7->Close();

  //BkG 9 - GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8 
   TFile *newfile9 = new TFile(outdirFT + GJet_Pt1,"recreate");   
   TTree *newtree9 = MCBkgTree9->CloneTree();   
   TBranch *brMVA9 = newtree9->Branch("MVAOutputTransformed",&MVA9,"MVAOutputTransformed/F"); 
   bkg9tree->SetBranchAddress("MVAOutputTransformed",&MVAold9); 
   Long64_t nentries9 = newtree9->GetEntries(); 
   for (Long64_t i=0; i<nentries9; i++) 
   { 
     newtree9->GetEntry(i); 
     bkg9tree->GetEntry(i); 
     
     MVA9=MVAold9;      
     brMVA9->Fill();  
   }     
   newtree9->Print();       
   newfile9->Write();
   newfile9->Close();

   //BkG 10 - GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8
   TFile *newfile10 = new TFile(outdirFT + GJet_Pt2,"recreate");   
   TTree *newtree10 = MCBkgTree10->CloneTree();   
   TBranch *brMVA10 = newtree10->Branch("MVAOutputTransformed",&MVA10,"MVAOutputTransformed/F"); 
   bkg10tree->SetBranchAddress("MVAOutputTransformed",&MVAold10); 
   Long64_t nentries10 = newtree10->GetEntries(); 
   for (Long64_t i=0; i<nentries10; i++) 
   { 
     newtree10->GetEntry(i); 
     bkg10tree->GetEntry(i); 
     
     MVA10=MVAold10;      
     brMVA10->Fill();  
   }     
   newtree10->Print();       
   newfile10->Write();
   newfile10->Close();

   //BkG 11 - output_bbHToGG_M-125_4FS_ybyt_13TeV_amcatnlo.root
   TFile *newfile11 = new TFile(outdirFT + "output_bbHToGG_M-125_4FS_ybyt_13TeV_amcatnlo.root","recreate");   
   TTree *newtree11 = MCBkgTree11->CloneTree();   
   TBranch *brMVA11 = newtree11->Branch("MVAOutputTransformed",&MVA11,"MVAOutputTransformed/F"); 
   bkg11tree->SetBranchAddress("MVAOutputTransformed",&MVAold11); 
   Long64_t nentries11 = newtree11->GetEntries(); 
   for (Long64_t i=0; i<nentries11; i++) 
   { 
     newtree11->GetEntry(i); 
     bkg11tree->GetEntry(i); 
     
     MVA11=MVAold11;      
     brMVA11->Fill();  
   }     
   newtree11->Print();       
   newfile11->Write();
   newfile11->Close();

}
