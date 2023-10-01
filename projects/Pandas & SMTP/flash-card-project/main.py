from tkinter import *
import pandas as pd
import random
import time

BACKGROUND_COLOR = "#B1DDC6"
current_card ={}
to_learn={}

#--------reading data from the csv file -----------#
try:
    data=pd.read_csv('C:\\Python310\\codes\\projects\\flash-card-project\data\\words_to_learn.csv')
except FileNotFoundError:
    original_data=pd.read_csv('C:\\Python310\\codes\\projects\\flash-card-project\data\\french_words.csv')
    to_learn=original_data.to_dict(orient='records')
else:
    to_learn=data.to_dict(orient='records')


#function to show next word
def next_card():
    global current_card, flip_timer
    window.after_cancel(flip_timer)
    current_card=random.choice(to_learn)
    canvas.itemconfig(title,text='French',fill='black')
    canvas.itemconfig(word,text=current_card['French'],fill='black')
    canvas.itemconfig(img,image=front_img)
    flip_timer=window.after(3000,func=flip_card)

#function to flip card ..... which will happen after 3sec 
def flip_card():
    canvas.itemconfig(title,text='English',fill='white')
    canvas.itemconfig(word,text=current_card['English'],fill='white')
    canvas.itemconfig(img,image=back_img)

#function to remove known card from the rest of the card
def remove_card():
    to_learn.remove(current_card)
    data=pd.DataFrame(to_learn)
    data.to_csv('C:\\Python310\\codes\\projects\\flash-card-project\data\\words_to_learn.csv',index=False)
    next_card()

#------------UI setup----------------#
#window#
window=Tk()
window.title('Flash-Card')
window.config(padx=50,pady=50,bg=BACKGROUND_COLOR)

flip_timer=window.after(3000,func=flip_card)

#canvas#
canvas=Canvas(width=800,height=526,highlightthickness=0,bg=BACKGROUND_COLOR)
front_img=PhotoImage(file='C:\\Python310\\codes\\projects\\flash-card-project\\images\\card_front.png')
back_img=PhotoImage(file='C:\\Python310\\codes\\projects\\flash-card-project\\images\\card_back.png')
img=canvas.create_image(400,260,image=front_img)
title=canvas.create_text(400,150,text='',font=('Arial',40,'italic'))
word=canvas.create_text(400,263,text='',font=('Arial',60,'bold'))
canvas.grid(column=0,row=0,columnspan=2)

#button#
right_img=PhotoImage(file='C:\\Python310\\codes\\projects\\flash-card-project\images\\right.png')
right_button=Button(image=right_img,highlightthickness=0,bg=BACKGROUND_COLOR,command=remove_card)
right_button.grid(column=1,row=1)

wrong_img=PhotoImage(file='C:\\Python310\\codes\\projects\\flash-card-project\\images\\wrong.png')
wrong_button=Button(image=wrong_img,highlightthickness=0,bg=BACKGROUND_COLOR,command=next_card)
wrong_button.grid(column=0,row=1)

next_card() # calling next_card function to get next card

window.mainloop()