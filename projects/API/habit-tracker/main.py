import requests
from datetime import *

TOKEN='jdjfsfhbu443i3uf'
USERNAME='iceberg'
GRAPH_ID='graph2'
#todays date
today=datetime.now()

pixela_endpoint='https://pixe.la/v1/users'

user_params={
    'token':TOKEN,
    'username':USERNAME,
    'agreeTermsOfService':'yes',
    'notMinor':'yes'
}
'''created a new user'''
# response=requests.post(url=pixela_endpoint,json=user_params)
# print(response.text)

headers={
    'X-USER-TOKEN':TOKEN
}

# graph_endpoint=f'{pixela_endpoint}/{USERNAME}/graphs'


# graph_params={
#     'id':'graph2',
#     'name':'Coding',
#     'unit':'hours',
#     'type':'int',
#     'color':'sora'
# }
# '''created a new graph'''
# response=requests.post(url=graph_endpoint,json=graph_params,headers=headers)
# print(response.text)

updated_graph_endpoint=f'{pixela_endpoint}/{USERNAME}/graphs/{GRAPH_ID}'

params={
    'date':today.strftime('%Y%m%d'),
    'quantity':input('How many hours you studied today? ')
}
'''updating the value of the given date'''
response=requests.post(url=updated_graph_endpoint,json=params,headers=headers)
print(response.text)

graph_endpoint=f'{pixela_endpoint}/{USERNAME}/graphs/{GRAPH_ID}/{params["date"]}'
# response=requests.put(url=graph_endpoint,json={'quantity':'10'},headers=headers)
# print(response.text)

'''deleting the value of the given date'''
# response=requests.delete(url=graph_endpoint,headers=headers)
# print(response.text)


