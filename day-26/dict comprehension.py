#import random

#names=['Alex','Beth','Caroline','Dave','Eleanor','Freddie']
#students_scores={
#    item:random.randint(1,100) for item in names
#}

#print(students_scores)

#passed_students={
#    key:value for (key,value) in students_scores.items() if value>60
#}
#
#print(students_scores,passed_students)

student_dict={
    'students':['John','James','Lily'],
    'score':[56,76,98]
}

import pandas as pd

student_data_frame=pd.DataFrame(student_dict)
#print(student_data_frame)

#loop through the dataframe
#for (key,value) in student_data_frame.items():
#    print(value)
print(student_data_frame)
#loop through the rows of dataframe
for (index,row) in student_data_frame.iterrows():
    print(row.score)