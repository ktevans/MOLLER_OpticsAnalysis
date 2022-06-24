import math
import uproot
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from polygon_selector_demo import SelectFromCollection
from scipy.stats import gaussian_kde
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import PolynomialFeatures, StandardScaler
from sklearn import linear_model
import pickle
from opticsClass import OPTICS

 
if __name__=='__main__':
    
    optics=OPTICS()
      
    all_file=[["11"],["11"],["11"],["71"]]
    all_target=[["p3"],["p3"],["p3"],["p1","p2","p3"]]
    base_path = "/work/halla/moller12gev/vdoomra/optics/remoll/optics_output/optics-analysis/OpticsMatrix/"
    all_df = pd.DataFrame()
      
    varNms   =["theta","phi","momentum","sieve r"]
    fitFlag  =[1,0,0,0]
    fitPolDeg=[2,2,2,3]
    fitDataX =[2,2,2,4]
    yLocation=[1,9,2,4]
    normData=0 ##0= no normalization; 1= prePolyFeatures; 2=postPolyFeatures

    for i in range(4):
        if not fitFlag[i]:
            continue

        print("Fitting data. Collect files .. ")
        for a_pass in all_target[i]:
            for a_file in all_file[i]:
                file_new = base_path + "output_sieve_r/optics1DS_" + str(a_pass) + "_" + str(a_file)+ ".csv"
                print(file_new)
                df_new=pd.read_csv(file_new)
                all_df = pd.concat([all_df,df_new],axis=0)
        print("Start data prep for",varNms[i],"and polynomial degree of",fitPolDeg[i])
        """
        prep datasets
        """
        X=all_df.iloc[:,[5,6,7,8]].values
        y=all_df.iloc[:,[yLocation[i]]].values
        print("Initial data: (X,y)",X.shape,y.shape)
        X_train,X_test,y_train,y_test=train_test_split(X, y, 
                                                       test_size=0.33, random_state=42)

        X_trainR = X_train[:,:fitDataX[i]]
        X_testR = X_test[:,:fitDataX[i]]


        print("\t Train data: (X,y)",X_trainR.shape,y_train.shape)
        print("\t Test data: (X,y)",X_testR.shape,y_test.shape)

        #Normalize
        if normData==1:
            print("PrePolyFeatures normalization train data mean:",
                  np.mean(X_trainR,axis=0))
            scaler = StandardScaler()
            scaler.fit(X_trainR)
            print("\tTrain means:",scaler.mean_)
            print("\tTrain sigma:",scaler.var_)
            X_trainR  = scaler.transform(X_trainR)
            X_testR = scaler.transform(X_testR)
            print("\tNormalized train data mean:",np.mean(X_trainR,axis=0))
            print("\tNormalized test data mean:",np.mean(X_testR,axis=0))

        poly = PolynomialFeatures(fitPolDeg[i])
        X_train_new=poly.fit_transform(X_trainR)
        X_test_new=poly.fit_transform(X_testR)
        print("\t New Train data: (Xnew,y)",X_train_new.shape,y_train.shape)
        print("\t New Test data: (Xnew,y)",X_test_new.shape,y_test.shape)

        if normData==2:
            print("PostPolyFeatures normalization train data mean:",
                  np.mean(X_trainR,axis=0))
            scaler = StandardScaler()
            scaler.fit(X_train_new)
            print("\tTrain means:",scaler.mean_)
            print("\tTrain sigma:",scaler.var_)
            X_trainR  = scaler.transform(X_train_new)
            X_testR = scaler.transform(X_test_new)
            print("\tNormalized train data mean:",np.mean(X_train_new,axis=0))
            print("\tNormalized test data mean:",np.mean(X_test_new,axis=0))

        lrModel = linear_model.LinearRegression()
        optics.fitModel(lrModel,
                        X_train_new, y_train, 
                        "polReg_"+varNms[i]+"_deg"+str(fitPolDeg[i]))
            
        clmns = poly.get_feature_names_out()
        fct = ""
        for par,varNm in zip(lrModel.coef_[0],clmns):
            fct += "{0:.2e}*".format(par) + varNm + " + "
        print("Returned model:\n{0:.2e} + ".format(lrModel.intercept_[0]),fct)

        optics.evalModel(X_test_new, X_test, y_test,lrModel, "linReg_"+varNms[i])
          


