import uproot
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestRegressor
from sklearn.multioutput import MultiOutputRegressor
import matplotlib.pyplot as plt
from opticsClass import OPTICS

def fitRFreg(nTrees,maxDepth,minSamplesLeaf, X_train, X_test, y_train, y_test, optics, varNms, oNm):
    pNm = "_nE"+str(nEst)+"_mD"+str(maxDepth)+"_minSampLeaf"+str(minSamplesLeaf)
    rfrModel = RandomForestRegressor(n_estimators=nTrees, max_depth=maxDepth, min_samples_leaf=minSamplesLeaf)
    trainScore= optics.fitModel(rfrModel,
                                X_train, y_train, 
                                oNm+pNm)
            
    print("Returned model:\n",rfrModel,"\n\t with training score of",trainScore)
    featImp = rfrModel.feature_importances_
    print("\t feature importance: ", featImp)

    testScore = rfrModel.score(X_test, y_test)
    yPred = rfrModel.predict(X_test)
    print("TestScore for all variables: ", testScore)
    
    for i in range(4):
        print("\tplotting ",varNms[i])
        optics.plotOneVar(X_test,y_test[:,i], yPred[:,i],
                          testScore,trainScore,varTitle="rfReg_"+varNms[i]+pNm, yTitle=varNms[i], plot=False)
    return trainScore, testScore, featImp

 
if __name__=='__main__':
    
    optics=OPTICS()
      
    holes   =[str(i)+"1" for i in range(1,8)]+[str(i)+"2" for i in range(1,8)]+["73"]
    passes  =["p1","p2","p3"]
    base_path = "/work/halla/moller12gev/vdoomra/optics/remoll/optics_output/optics-analysis/OpticsMatrix/"
    all_df = pd.DataFrame()
      
    varNms   =["theta","phi","momentum","sieveR"]
    fitFlag  =[1,1,1,1]
    yLocation=[1,9,2,4]
    normData=1 ##0= no normalization; 1= with normalization

    oNm = "rfReg_allHoles_p1p2p3_"
    yLoc=[]
    for i,fit in enumerate(fitFlag):
        if fit==1:
            yLoc.append(yLocation[i])
            oNm += varNms[i]+"_"

    print("Fitting data. Collect files .. ")
    for aPass in passes:
        for hole in holes:
            file_new = base_path + "output_sieve_r/optics1DS_" + str(aPass) + "_" + str(hole)+ ".csv"
            print(file_new)
            df_new=pd.read_csv(file_new)
            all_df = pd.concat([all_df,df_new],axis=0)
    
    print("Start data prep for",oNm)
    """
    prep datasets
    """
    X=all_df.iloc[:,[5,6,7,8]].values
    y=all_df.iloc[:,yLoc].values
    print("Initial data: (X,y)",X.shape,y.shape)
    X_train,X_test,y_train,y_test=train_test_split(X, y, 
                                                   test_size=0.20, random_state=42)

    print("\t Train data: (X,y)",X_train.shape,y_train.shape)
    print("\t Test data: (X,y)",X_test.shape,y_test.shape)

    #Normalize
    if normData==1:
        print("PreProces normalization train data mean:",
              np.mean(X_train,axis=0))
        scaler = StandardScaler()
        scaler.fit(X_train)
        print("\tTrain means:",scaler.mean_)
        print("\tTrain sigma:",scaler.var_)
        X_train  = scaler.transform(X_train)
        X_test = scaler.transform(X_test)
        print("\tNormalized train data mean:",np.mean(X_train,axis=0))
        print("\tNormalized test data mean:",np.mean(X_test,axis=0))

    maxDepth=35
    nEst = 110
    minSamplesLeaf = 1
    x=[]
    ytrS =[]
    ytestS =[]
    yPar = []
    for i in range(1,10):
        trS, testS, featImp = fitRFreg(nEst,maxDepth,i, X_train, X_test, y_train, y_test, optics, varNms, oNm)
        x.append(i)
        ytrS.append(trS)
        ytestS.append(trS)
        yPar.append(featImp)

    f1, a1 = plt.subplots()
    a1.set_title("train and test errors")
    a1.plot(x,ytrS,"b-")
    a1.plot(x,ytestS,"r-.")
    a1.grid(visible=True,axis="both")
    a1.set_yscale("log")

    f2,a2 = plt.subplots()
    a2.set_title("feature importance")
    a2.plot(x,[i[0] for i in yPar],"b-")
    a2.plot(x,[i[1] for i in yPar],"r-.")
    a2.plot(x,[i[2] for i in yPar],"g--")
    a2.plot(x,[i[3] for i in yPar],"m:")
    a2.grid(visible=True,axis="both")

    plt.show()
    

    # pNm = "_nE"+str(nEst)+"_mD"+str(maxDepth)+"_norm"+str(normData)
    # rfrModel = RandomForestRegressor(n_estimators=nEst, max_depth=maxDepth, random_state=2)
    # trainScore= optics.fitModel(rfrModel,
    #                             X_train, y_train, 
    #                             oNm+pNm)
            
    # print("Returned model:\n",rfrModel,"\n\t with training score of",trainScore)
    # print("\t feature importance: ", rfrModel.feature_importances_)

    # testScore = rfrModel.score(X_test, y_test)
    # yPred = rfrModel.predict(X_test)
    # print("TestScore for all variables: ", testScore)
    
    # for i in range(4):
    #     print("\tplotting ",varNms[i])
    #     optics.plotOneVar(X_test,y_test[:,i], yPred[:,i],
    #                       testScore,trainScore,varTitle="rfReg_"+varNms[i]+pNm, yTitle=varNms[i], plot=False)
        


#         regr_multirf = MultiOutputRegressor(
#             RandomForestRegressor(n_estimators=100, max_depth=max_depth, random_state=0)
#         )
