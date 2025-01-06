import pandas as pd

df = pd.read_csv('/home/rustam/Downloads/archive/data.csv', header=None)

df_women = df[df[3] == 'Ж'].drop(columns=[3], axis=1)
df_men = df[df[3] == 'М'].drop(columns=[3], axis=1)

pd.DataFrame(df_women[0].unique()).to_csv('data/women/surnames.txt', sep='\t', index=False)
pd.DataFrame(df_women[1].unique()).to_csv('data/women/names.txt', sep='\t', index=False)
pd.DataFrame(df_women[2].unique()).to_csv('data/women/patronymic.txt', sep='\t', index=False)

pd.DataFrame(df_men[0].unique()).to_csv('data/men/surnames.txt', sep='\t', index=False)
pd.DataFrame(df_men[1].unique()).to_csv('data/men/names.txt', sep='\t', index=False)
pd.DataFrame(df_men[2].unique()).to_csv('data/men/patronymic.txt', sep='\t', index=False)
