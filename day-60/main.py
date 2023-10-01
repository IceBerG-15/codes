from flask import Flask, render_template, request
app=Flask(__name__)

@app.route('/')
def intro():
    return render_template('index.html')

@app.route('/login', methods=['POST'])
def details():
    return f'<h1>{request.form["email"]}    {request.form["password"]}</h1>'


def main():
    app.run(debug=True)

if __name__ == '__main__':
    main()
