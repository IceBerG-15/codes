from tkinter import *


def main():
    window=Tk()
    window.title('Mile to Km Converter')
    window.minsize(width=300,height=200)
    window.config(padx=10,pady=10)

    #label
    Mile_label=Label(text='Miles')
    Mile_label.grid(column=2,row=0)
    Mile_label.config(padx=5,pady=5)

    is_equal_label=Label(text='is equal to')
    is_equal_label.grid(column=0,row=1)
    is_equal_label.config(padx=5,pady=5)

    Km_result_label=Label(text='0')
    Km_result_label.grid(column=1,row=1)
    Km_result_label.config(padx=5,pady=5)

    Km_label=Label(text='Km')
    Km_label.grid(column=2,row=1)
    Km_label.config(padx=5,pady=5)

    #function for button
    def Calculate():
        input=float(Mile_input.get())
        input*=1.689
        Km_result_label.config(text=f"{round(input)}")


    #button
    button=Button(text='Calculate',command=Calculate)
    button.grid(column=1,row=2)
    button.config(padx=5,pady=5)

    #Mile_input
    Mile_input=Entry(width=10)
    Mile_input.grid(column=1,row=0)

    window.mainloop()

if __name__=='__main__':
    main()