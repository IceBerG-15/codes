from flask import Flask, render_template, request
import requests
import datetime
import smtplib
import os
from dotenv import load_dotenv

# loading .env file 
load_dotenv('.env')
my_email=os.getenv('EMAIL')
password=os.getenv('PASSOWRD')
# requesting json from the api
posts = requests.get("https://api.npoint.io/c790b4d5cab58020d391").json()
# author details
author='Sidhant Sharma'
now=datetime.datetime.now()
#current date
date=now.date()

# initialising app 
app=Flask(__name__)

#main home page route
@app.route('/')
def intro():
    return render_template('index.html',posts=posts,author=author,date=date)

# about section
@app.route("/about")
def about():
    return render_template("about.html")

# contact section when its method is get
@app.route("/contact",methods=["GET"])
def contact():
    return render_template("contact.html",method=True)

# post section 
@app.route("/post/<int:num>")
def post(num):
    for post in posts:
        if post['id']==num:
            selected_post=post
    return render_template("post.html",post=selected_post,author=author,date=date)

# contact section when its method is post
@app.route("/contact",methods=["POST"])
def data_entry():
    
    name=request.form['name']
    email=request.form['email']
    number=request.form['number']
    message=request.form['message']
    send_email(name, email, number, message)
    return render_template("contact.html",method=False)


# check this function before doing anything
def send_email(name, email, phone, message):
    email_message = f"Subject:New Message\n\nName: {name}\nEmail: {email}\nPhone: {phone}\nMessage:{message}"
    with smtplib.SMTP("smtp.gmail.com",port=587) as connection:
        connection.starttls()
        connection.login(my_email, password)
        connection.sendmail(
            from_addr=my_email,
            to_addrs=email,
            msg=email_message
        )

# compiler will start reading from here 
if __name__ == '__main__':
    app.run(debug=True)
