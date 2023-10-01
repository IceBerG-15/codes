def func(d):                     #function which will give the output
    l=[]
    k=''
    for i in d:
        c=[]
        c.append(i)              #appending key 
        if type(d[i]) is list:   #appending the key value of the key when value is list
            for j in d[i]:
                c.append(j)
        else:
            c.append(d[i])       #appending the key value
            if d[i] in d:        #checking whether key-value of some element is an element or not
                k=d[i]
                c.append(d[d[i]])    #appending the key-value of the element which is also an element
        l.append(c)                 #appending list in result list
    for i in l:
        if i[0]==k:
            l.remove(i)
    print(l)                       #wanted output

#driver function
def main():
    d={}
    n=input()
    for _ in range(int(n)):
        x,y=map(str,input().split('-'))  #split will be done by using '-'
        if x not in d:
            d[x]=y
        else:
            c=[]                 #key value becomes list if multiple value of key is given
            c.append(d[x])       #appending the existing value of key
            c.append(y)          #appending new value
            d[x]=c
    func(d)                      #calling the function


if __name__=='__main__':
    main()
    
    
        
