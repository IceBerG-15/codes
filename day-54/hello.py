from flask import Flask
app = Flask(__name__)


def make_bold(function):
    def wrapper():
        return f'<b>{function()}</b>'
    return wrapper

def make_emphasis(function):
    def wrapper():
        return f'<em>{function()}</em>'
    return wrapper

def make_underline(function):
    def wrapper():
        return f'<u>{function()}</u>'
    return wrapper

@app.route('/')
def hello_world():
    return '<h1><center>Hello, World!</h1>\
            <p>Welcome,Bitches</p>\
            <img src="https://media3.giphy.com/media/VcASuZBH0FtllFYIKJ/giphy.gif?cid=790b76113911b6b563274d33930f5abcb00e526764642b1a&rid=giphy.gif&ct=g" width="480" height="480" frameBorder="0" class="giphy-embed" allowFullScreen></img>'


@app.route('/bye')
@make_bold
@make_emphasis
@make_underline
def bye():
    return 'bye!!'

@app.route('/<name>/<int:age>')
def greet(name,age):
    return f'Hello, {name}, you are {age} years old'





def main():
    app.run(debug=True)

if __name__ == '__main__':
    main()

