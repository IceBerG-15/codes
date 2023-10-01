import tkinter as t

window=t.Tk()
window.title('GUI program ')
window.minsize(width=500,height=300)
window.config(padx=20,pady=20)

#label
label=t.Label(text='Welcome', font=('Arial',24,'italic'))
label.grid(column=0,row=0)
label.config(padx=10,pady=10)



def button_click():
    input=entry.get()
    label.config(text=input)

#button
button=t.Button(text='click me',command=button_click)
button.grid(column=1,row=1)

new_button=t.Button(text='new_botton')
new_button.grid(column=2,row=0)


#entry
entry=t.Entry(width=10)
entry.grid(column=3,row=2)









window.mainloop()