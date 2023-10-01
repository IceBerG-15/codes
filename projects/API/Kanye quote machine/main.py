from tkinter import *
import requests

api_link='https://api.kanye.rest/'

def get_quote():
    #Write your code here.
    response = requests.get(api_link)
    quote=response.json()['quote']
    canvas.itemconfig(quote_text,text=quote)
        

window = Tk()
window.title("Kanye Says...")
window.config(padx=50, pady=50,bg='pink')

canvas = Canvas(width=300, height=414,highlightthickness=0,bg='pink')
background_img = PhotoImage(file="C:\\Python310\\codes\\projects\\Kanye quote machine\\background.png")
canvas.create_image(150, 207, image=background_img)
quote_text = canvas.create_text(150, 207, text="Kanye Quote Goes HERE", width=250, font=("Arial", 25, "bold"), fill="white")
canvas.grid(row=0, column=0)

kanye_img = PhotoImage(file="C:\\Python310\\codes\\projects\\Kanye quote machine\\kanye.png")
kanye_button = Button(image=kanye_img, command=get_quote,highlightthickness=0,bg='pink')
kanye_button.grid(row=1, column=0)



window.mainloop()