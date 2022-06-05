import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

all_file=["11","12","21","22","31","32","41","42","51","52","61","62","71","72","73"]
all_target=["optics1DS"]
all_df = pd.DataFrame()

for a_pass in all_target:
 for a_file in all_file:
  file_new = "output_sieve_r/" + str(a_pass) + "_p3_" + str(a_file)+ ".csv"
  print(file_new)
  df_new=pd.read_csv(file_new)
  all_df = pd.concat([all_df,df_new],axis=0)

all_df.to_csv("optics1DS_p3_allholes.csv")
corr = all_df.astype('float64').corr(method='pearson')    #Change pearson --> sprearman for non-linear correlations 

sns.heatmap(data=corr, linewidth=0.3, square=True, cmap='vlag', vmax=1, vmin=-1, center=0, annot=True)
plt.show()
