#list comprehension learning

numbers=[1,2,3]

##mapping method 
add_1=lambda x:x+1
numbers_1=list(map(add_1, numbers))
#print(numbers_1)

##list comprehension method
numbers_2=[n+1 for n in numbers]
#print(numbers_2)

name='Sidhant'
letters=[letter for letter in name]
#print(letters)

l=[i*2 for i in range(1,5)]
#print(l)

l=[i*2 for i in l if i==8]
#print(l)

names=['Alex','Beth','Caroline','Dave','Eleanor','Freddie','Jack']
upper_names=[i.upper() for i in names if len(i)>=5]
#print(upper_names)

numbers=[1,1,2,3,5,8,13,21,34,55]
squarred_numbers=[i*i for i in numbers]
#print(squarred_numbers)

even_nums=[i for i in numbers if i%2==0]
#print(even_nums)

