import pandas as pd
import os
import requests
from requests.exceptions import HTTPError

dir_path = os.path.dirname(os.path.realpath(__file__))
df = pd.read_csv(dir_path+'\\google-10000-english-no-swears.txt', names = ['word'] )
df_count = pd.read_csv(dir_path+'\\count_1w.txt', sep = '\t', names = ['word', 'freq'])

df_fin = pd.merge(df, df_count, on="word") #, how = 'left')

df_fin = df_fin[df_fin.index<500]
minInRange = df_fin['freq'].min()
maxInRange = df_fin['freq'].max()
#df_fin['freq'].max() -- actual max is too large compared to rest of data
maxOutRange = 0
minOutRange = 0
freqNew = {}

quartile = df_fin['freq'].quantile([.25, .5, .75, 1])
#remaps 1,2,3 and 4 quartile seperately
for index,row in df_fin.iterrows():
    if (quartile[.75]<row['freq']<=quartile[1]):
        maxInRange = quartile[1]
        minInRange = quartile[.75]
        maxOutRange = 19
        minOutRange = 15
    elif(quartile[.5]<row['freq']<=quartile[.75]):
        maxInRange = quartile[.75]
        minInRange = quartile[.5]
        maxOutRange = 14
        minOutRange = 10
    elif(quartile[.25]<row['freq']<=quartile[.5]):
        maxInRange = quartile[.5]
        minInRange = quartile[.25]
        maxOutRange = 9
        minOutRange = 5
    elif(row['freq']<=quartile[.25]):
        maxInRange = quartile[.25]
        minInRange = df_fin['freq'].min()
        maxOutRange = 4
        minOutRange = 0

    inValue = row['freq']
    x = (inValue - minInRange) / (maxInRange - minInRange)
    result = (int)(minOutRange + (maxOutRange - minOutRange) * x)
    freqNew [row['word']] = result

print("const char * wordsList [] = " , list(freqNew.keys()), ";")
print("int wordsFreq []= ", list(freqNew.values()), ";")
# >words_w_count.txt
# ctrl+f (') replace all with (")
# replace brackets around lists with {}