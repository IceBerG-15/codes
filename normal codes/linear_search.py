def linear_search(arr,s):
    pos=0
    for i in range(len(arr)):
        if arr[i]==s:
            pos=i+1
            break
    return(pos)

#output function
def output(arr,s):
    d=linear_search(arr,s)
    if d==0:
        print("no. is not present in the list")
    else:
        print('no. is present at the position--',d)

def var():
    s=int(input('No. u want to search: '))
    return s

def array():
    arr=[10,20,80,30,60,50,110,100,130,170]
    print(arr)
    ch=input('do u want to add element in the list???(y/n)')
    while ch=='y':
        a=int(input('which no. u want to add in the list--'))
        arr.append(a)
        ch=input('do u want to add more--(y/n)')
    print(arr)
    return arr

#calling the function

output(array(),var())