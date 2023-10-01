'''Here we will check the highest runtime of the movie and print the movie name with runtime'''
import requests
import lxml
from bs4 import BeautifulSoup

# getting data from website
response=requests.get('https://www.imdb.com/list/ls091520106/')
response.encoding='utf-8'
#scrapping data to find relevant information
soup=BeautifulSoup(response.text,'lxml')
names=soup.find_all(name='h3',class_='lister-item-header')
times=soup.find_all(name='span',class_='runtime')
#storing the values in the list, which we'll use further 
runtimes=[int(time.text.split()[0]) for time in times]
movie_names=[]
for name in names:
    movie_names.append(name.find(name='a').text)
#finding the index of movie with highest runtime
highest_runtime=runtimes.index(max(runtimes))
print(movie_names[highest_runtime],runtimes[highest_runtime])
