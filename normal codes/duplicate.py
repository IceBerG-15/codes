ch={1:'cat',2:'dog',3:'cow',4:'goat',5:'mouse'}
print(ch)
ch[6]='dog'
print(ch)
for i in range(len(ch)):
    for j in range(len(ch)):
        if i==j:
            continue
        else:
            if len(ch[i])==len(ch[j]):
                k=0
                if ch[i][k]==ch[j][k]:
                    print(i,j)
                k+=1
            