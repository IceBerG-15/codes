
a=int(input('enter the number u want to check--'))
count=0
for i in range(1,a+1):
    if a%i==0:
        count=count+1
print(count)        
if count==2:
    print(f'{a} is a prime number')
else:
    print(f'{a} is not a prime number')
