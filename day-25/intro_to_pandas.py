#with open('C:\Python310\codes\day-25\weather_data.csv') as file:
#    data =file.readlines()
#    print(data)

#import csv
#
#with open('C:\Python310\codes\day-25\weather_data.csv') as file:
#    data=csv.reader(file)
#    temparatures=[]
#    for i in data:
#        if i[1]!='temp':
#            temparatures.append(int(i[1]))
#    print(temparatures)

import pandas as pd

data=pd.read_csv('C:\Python310\codes\day-25\weather_data.csv')
#print(type(data['temp']))
#data_dict=data.to_dict()
#print(data_dict)
#temp_data=data['temp'].to_list()
#print(temp_data)

#print(data['temp'].mean())

#print(data['temp'].max())

#print(data.keys())

#print(data.day) #is equivalent to data['day']

#print(data[data.day=='Wednesday'])

#print(data[data.temp==data.temp.max()])

#t=int(data[data.day=='Monday'].temp)
#t=9/5+32
#print(t)


#creating dataframe from scratch
data_dict={
    'students':['Amy','John','Soap'],
    'scores':[75,56,95]
}

new_data=pd.DataFrame(data_dict)

print(new_data)

new_data.to_csv('C:\Python310\codes\day-25\new_data.csv')

