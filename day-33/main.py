import requests
import datetime as dt

MY_LAT=24.382460
MY_LONG=87.857620

# response=requests.get(url='http://api.open-notify.org/iss-now.json')
# response.raise_for_status()

# data=response.json()['iss_position']['longitude']
# print(data)

parameters={
    'lat': MY_LAT,
    'lng': MY_LONG
}

response=requests.get(url=f'https://api.sunrise-sunset.org/json?lat={MY_LAT}&lng={MY_LONG}&formatted=0')
response.raise_for_status()
data=response.json()
result=data['results']
sunrise=result['sunrise'].split('T')[1]
sunset=result['sunset'].split('T')[1].split(':')[0]

time_now=dt.datetime.now()
print(time_now.hour)

print(sunset)


