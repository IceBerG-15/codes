import random
import string
import goto


words=['ironman','thor','hawkeye','hulk']
word=words[random.randint(0,len(words))]
print(word)
attempts=5
gap="_"*len(word)
print(gap,"  --",len(gap))


def check():
    global words 
    global gap 
    global attempts
    global word 
    label:
    a=input("Guess an aplabet--")
    if len(a)>2 or len(a)<0 and a<='9':
        print("invalid character-- enter again")
        goto label
    for i in range(len(word)):
        if word[i]==a:
            gap=string.replace("_","a")
        else:
            attempts=attempts-1
    print(gap)
    if word==gap:
        print("---you won--")
    elif attempts==0:
        print("---you lose---")
    else:
        return check()
        
    return gap

print(check())
