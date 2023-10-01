import pandas as pd
data=pd.read_csv('.\\day-25\\2018_Central_Park_Squirrel_Census_-_Squirrel_Data.csv')

gray_data=data[data['Primary Fur Color']=='Gray']
gray_count=len(gray_data)

red_data=data[data['Primary Fur Color']=='Red']
red_count=len(red_data)

black_data=data[data['Primary Fur Color']=='Black']
black_count=len(black_data)

data_dict={
    'Fur Color':['Gray', 'Red', 'Black'],
    'Count':[gray_count, red_count,black_count]
}

data=pd.DataFrame(data_dict)

print(data)

data.to_csv('.\\day-25\\squirrel_count.csv')