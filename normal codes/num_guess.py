import random

print('----Welcome-----')
print('Difficulty Levels--\n 1-easy \n 2-medium \n 3-difficult')
c=int(input('which level do u want to select?? '))
if c==1:
    at=10
elif c==2:
    at=7
else:
    at=5
print(at)

#random generation of the number
ran=random.randint(1,50)

#function that'll ask the user for number
def ask():
    ch=int(input('guess the number--'))
    return ch

#function that'll check the number
def check(r,a):
    ch=ask()
    if ch==r:
        print('right guess..u won..')
    elif a==0:
        print('attempts over.. u lose...better luck next time..')
    elif ch<r:
        print(f'guess a number higher than {ch}')
        a=a-1
        print(f'ur remaining attempts-{a}')
        check(r,a)
    else:
        print(f'guess a number lower than {ch}')
        a=a-1
        print(f'ur remaining attempts-{a}')
        check(r,a)

check(ran,at)
    