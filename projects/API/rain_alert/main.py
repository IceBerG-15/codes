import requests
from twilio.rest import Client
import os
from dotenv import load_dotenv
load_dotenv("projects\\API\\rain_alert\\.env") 


#twilio settings
my_twilio_no=+12512701295

account_sid=os.getenv('ACCOUNT_SID')
auth_token=os.getenv('AUTH_TOKEN')

#name of place--- Republic of Singapore
my_lat=1.300070
my_long=103.864723
api_key=os.getenv('API_KEY')
api_link=f'https://api.openweathermap.org/data/2.5/weather?lat={my_lat}&lon={my_long}&appid={api_key}'
will_rain=False
response = requests.get(api_link)
data=response.json()
# print(data['weather'][0]['main'])
weather_data=data['weather'][0]['main']
if weather_data.__eq__('Clouds'): 
    will_rain=True
# for hour in hourly_data:
#     condition=hour['weather'][0]['id']
#     if condition<700:
#         will_rain=True


if will_rain:
    client=Client(account_sid,auth_token)
    message = client.messages.create(
                    body="Its going to rain today. bring your umbrella ☂️",
                    from_=my_twilio_no,
                    to='+917478230626'
                )

    print(message.sid)


