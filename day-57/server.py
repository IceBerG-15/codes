from flask import Flask, render_template, url_for
import random
from datetime import datetime
import requests


app=Flask(__name__)

@app.route('/')
def intro():
    random_number=random.randint(1,10)
    curr_year=datetime.now().year
    return render_template('index.html',num=random_number,year=curr_year)

@app.route('/guess/<name>')
def guess(name):
    age_response = requests.get(f'https://api.agify.io?name={name}')
    age=age_response.json()['age']
    gender_response = requests.get(f'https://api.genderize.io?name={name}')
    gender=gender_response.json()['gender']
    return render_template('age.html',age=age,gender=gender,name=name)

@app.route('/blog/<num>')
def get_blog(num):
    response=requests.get('https://api.npoint.io/c790b4d5cab58020d391')
    all_posts=response.json()
    return render_template('blog.html', posts=all_posts)


def main():
    app.run(debug=True)

if __name__ == '__main__':
    main()
