from flask import Flask
import random
app=Flask(__name__)

R=random.randint(0,9)

@app.route('/')
def intro():
    return '<h1>Guess a number between 0-9</h1>\
        <img src="https://media.giphy.com/media/3o7aCSPqXE5C6T8tBC/giphy.gif?cid=790b76113911b6b563274d33930f5abcb00e526764642b1a&rid=giphy.gif&ct=g" width="480" height="480" frameBorder="0" class="giphy-embed" allowFullScreen></img>'

@app.route('/<int:number>')
def check(number):
    global R
    if R==number:
        return '<h1>Right Guess</h1>\
            <img src="https://media.giphy.com/media/4T7e4DmcrP9du/giphy.gif" width="480" height="480" ></img>'
    elif number>R:
        return '<h1>Your Guess is too high</h1>\
            <img src="https://media.giphy.com/media/3o6ZtaO9BZHcOjmErm/giphy.gif" width="480" height="480" ></img>'
    else:
        return '<h1>Your Guess is too low</h1>\
            <img src="https://media.giphy.com/media/jD4DwBtqPXRXa/giphy.gif" width="480" height="480" ></img>'



def main():
    app.run(debug=True)

if __name__ == '__main__':
    main()

