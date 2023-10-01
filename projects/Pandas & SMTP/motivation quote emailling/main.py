import smtplib
import datetime as dt
import random
import os
from dotenv import load_dotenv

load_dotenv('projects\Pandas\motivation quote emailling\.env')

my_email=os.getenv('MY_EMAIL')
password=os.getenv('MY_EMAIL_PASS')


with open(file='C:\\Python310\\codes\\projects\\motivation quote emailling\\quotes.txt') as file:
    data=file.readlines()

random_num=random.randint(1,102)

## getting curret datetime
now=dt.datetime.now()
if now.weekday()==6:
    with smtplib.SMTP('smtp.gmail.com',port=587) as connection:
        connection.starttls()
        connection.login(user=my_email, password=password)
        connection.sendmail(
            from_addr=my_email,
            to_addrs='sidhant.murmu@gmail.com',
            msg=f'Subject:Sunday Motivation\n\n{data[random_num]}'
        )


