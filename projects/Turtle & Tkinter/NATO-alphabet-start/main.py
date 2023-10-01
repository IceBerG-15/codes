import pandas as pd
data=pd.read_csv('.\\projects\\NATO-alphabet-start\\nato_phonetic_alphabet.csv')

dict={
    value.letter:value.code for (key,value) in data.iterrows()
}

#user input
def fun():
    word=input('enter the word--').upper()
    try:
        l=[dict[i] for i in word]
    except KeyError:
        print('sorry,only letters in the word are allowed')   
        fun()
    else:
        print(l)

fun()