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
from matplotlib.backends.backend_pdf import PdfPages

class OPTICS:

    def __init__(self):
        self.orig = pd.DataFrame()        # data before cut
        self.sec1 = pd.DataFrame()        # sector1 data before cut
        self.sec2 = pd.DataFrame()        # sector2 data before cut
        self.sec3 = pd.DataFrame()        # sector3 data before cut
        self.sec4 = pd.DataFrame()        # sector4 data before cut
        self.sec5 = pd.DataFrame()        # sector5 data before cut
        self.sec6 = pd.DataFrame()        # sector6 data before cut
        self.sec7 = pd.DataFrame()        # sector7 data before cut

        self.selected = pd.DataFrame()    # data of selected holes

    def GenNumpyArray(self,filename):
  
        file = uproot.open(filename)
        T=file["newT"]

        geo = T.arrays(["gem1_x", "gem1_y","gem1_r","gem1_ph","gem1_px","gem1_py","gem1_pz","tg_th","tg_ph","tg_vz","tg_p","rate","sieve_r"],library="pd")  # panda dictionary
        geo = geo.loc[geo["gem1_r"]>300]

        geo["tg_ph"] = [i+2*math.pi if i<0 else i for i in geo.tg_ph]
        geo["gem1_ph"] = [i+2*math.pi if i<0 else i for i in geo.gem1_ph] 

        self.orig=geo

    def DefineSectors(self):
        rot_angle=0        # put the GEM rotation angle here

        angle_lo=[]
        angle_up=[]

        for i in range(7):
            angle_lo.append(i*2*math.pi/7 +rot_angle)
            angle_up.append((i+1)*2*math.pi/7 +rot_angle)

        print(angle_lo)
        print(angle_up)
        geo=self.orig

        self.sec1=geo.loc[(geo["gem1_ph"]<=angle_up[6]) & (geo["gem1_ph"]>=angle_lo[6])]
        self.sec2=geo.loc[(geo["gem1_ph"]<=angle_up[5]) & (geo["gem1_ph"]>=angle_lo[5])]
        self.sec3=geo.loc[(geo["gem1_ph"]<=angle_up[4]) & (geo["gem1_ph"]>=angle_lo[4])]
        self.sec4=geo.loc[(geo["gem1_ph"]<=angle_up[3]) & (geo["gem1_ph"]>=angle_lo[3])]
        self.sec5=geo.loc[(geo["gem1_ph"]<=angle_up[2]) & (geo["gem1_ph"]>=angle_lo[2])]
        self.sec6=geo.loc[(geo["gem1_ph"]<=angle_up[1]) & (geo["gem1_ph"]>=angle_lo[1])]
        self.sec7=geo.loc[(geo["gem1_ph"]<=angle_up[0]) & (geo["gem1_ph"]>=angle_lo[0])]

    def DrawHistAllSectors(self):
        fig, axs = plt.subplots(2, 4, figsize=(20,20))

        axs[0,0].hist2d(self.orig.gem1_r, self.orig.gem1_ph,(200,200),cmap=plt.cm.jet, cmin=1)
		
        axs[0,1].hist2d(self.sec1.gem1_r,self.sec1.gem1_ph,(200,200),cmap=plt.cm.jet, cmin=1)
        axs[0,1].set_title('sec1')
        axs[0,2].hist2d(self.sec2.gem1_r,self.sec2.gem1_ph,(200,200),cmap=plt.cm.jet, cmin=1)
        axs[0,2].set_title('sec2')
        axs[0,3].hist2d(self.sec3.gem1_r,self.sec3.gem1_ph,(200,200),cmap=plt.cm.jet, cmin=1)
        axs[0,3].set_title('sec3')
        axs[1,0].hist2d(self.sec4.gem1_r,self.sec4.gem1_ph,(200,200),cmap=plt.cm.jet, cmin=1)
        axs[1,0].set_title('sec4')
        axs[1,1].hist2d(self.sec5.gem1_r,self.sec5.gem1_ph,(200,200),cmap=plt.cm.jet, cmin=1)
        axs[1,1].set_title('sec5')
        axs[1,2].hist2d(self.sec6.gem1_r,self.sec6.gem1_ph,(200,200),cmap=plt.cm.jet, cmin=1)
        axs[1,2].set_title('sec6')
        axs[1,3].hist2d(self.sec7.gem1_r,self.sec7.gem1_ph,(200,200),cmap=plt.cm.jet, cmin=1)
        axs[1,3].set_title('sec7')

        plt.show()



    def SelectOneHole(self, df):

        fig, ax = plt.subplots(figsize=(10,7))

        pts=ax.scatter(df.gem1_r,df.gem1_ph)

        y_max=df.gem1_ph.max()
        y_min=df.gem1_ph.min()
        dy = (y_max-y_min)*0.1

        x_max=df.gem1_r.max()
        x_min=df.gem1_r.min()
        dx = (x_max-x_min)*0.1

        ax.set_ylim(y_min-dy, y_max+dy)
        ax.set_xlim(x_min-dx, x_max+dx)


        selector = SelectFromCollection(ax, pts)

        print("Select points in the figure by enclosing them within a polygon.")
        print("Press the 'esc' key to start a new polygon.")
        print("Try holding the 'shift' key to move all of the vertices.")
        print("Try holding the 'ctrl' key to move a single vertex.")

        plt.show()

        selector.disconnect()
        self.selected=df.loc[df.index[selector.ind]]

    def GenCSV(self, hole_id, filename):

        df=self.selected
        df["gem1_rp"] = (df.gem1_x*df.gem1_px+df.gem1_y*df.gem1_py)/(df.gem1_r*df.gem1_pz)     
        df["gem1_php"] = (-df.gem1_y*df.gem1_px+df.gem1_x*df.gem1_py)/(df.gem1_r*df.gem1_pz)    

        header=["tg_th","tg_ph","tg_vz","tg_p","gem1_r","gem1_rp","gem1_ph","gem1_php","sieve_r"]
        df.to_csv(filename,columns=header)

    def fitModel(self, model , X_train,y_train,modNm):  
 
        model.fit(X_train, y_train)
        print("Fitting ",model)
        print("\twith name ",modNm," on data shape",X_train.shape)

        params = model.coef_
        intercept = model.intercept_
        print("Fit result:")
        print("\t",intercept,params)
        print("\t Training score:",model.score(X_train,y_train))

        pkl_fNm = "./"+modNm+".pkl"
        with open(pkl_fNm,'wb') as file:
            pickle.dump(model,file)
        print("\t","saved to file:",pkl_fNm)

        
    def loadModel(self, modNm):  
        model = pickle.load(open(filename, 'rb'))
        print("Loaded model",model)
        return model

    def evalModel(self, X_test, X_plot, y_test, model,varTitle):  

        plt.rcParams["figure.figsize"] = [12.00, 7.00]

        score = model.score(X_test, y_test)
        y_pred = model.predict(X_test)

        varNms=["GEM r [mm]","GEM rp","GEM phi [rad]", "GEM php"]

        fig1, ax1 = plt.subplots(2,2)
        fig1.canvas.manager.set_window_title(varTitle+"_compare")
        ax1[0,0].set_title("Overall test-score: {0:.2f}".format(score))
        for i in range(2):
            for j in range(2):
                ax1[i,j].scatter( X_plot[:,[i*2+j]], y_test[:,[0]], cmap='Greens') 
                ax1[i,j].scatter( X_plot[:,[i*2+j]], y_pred[:,[0]], cmap='Reds')
                ax1[i,j].set_xlabel(varNms[i*2+j])
                ax1[i,j].set_ylabel(varTitle)
                ax1[i,j].grid(visible=True, axis='both')
        
        fig2, ax2 = plt.subplots()
        fig2.canvas.manager.set_window_title(varTitle+"_residual")
        yRes = y_test[:,[0]]-y_pred[:,[0]]
        mean = np.mean(yRes)
        std = np.std(yRes)
        ax2.hist(yRes,bins=50,histtype='step')
        ax2.set_title("Mean: {0:.2e}".format(mean)+" std: {0:.2e}".format(std))
        ax2.grid(visible=True, axis='both')

        fig3, ax3 = plt.subplots(2,2)
        fig3.canvas.manager.set_window_title(varTitle+"_residualVar")
        for i in range(2):
            for j in range(2):
                ax3[i,j].scatter( X_plot[:,[i*2+j]], yRes, cmap='Blues') 
                ax3[i,j].set_xlabel(varNms[i*2+j])
                ax3[i,j].set_ylabel(varTitle+" residual (y-ytrue)")
                ax3[i,j].grid(visible=True, axis='both')
        
        ##save figures
        pp = PdfPages(varTitle+".pdf")
        fig_nums = plt.get_fignums()
        figs = [plt.figure(n) for n in fig_nums]
        for fig in figs:
            fig.savefig(pp, format='pdf')
        pp.close()

        plt.show()
