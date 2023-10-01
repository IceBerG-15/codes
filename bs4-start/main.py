from bs4 import BeautifulSoup
import requests
import lxml

'''scrapping from my cv-website'''
# with open('C:\\Python310\\codes\\websites\\final-cv-website folder\\index.html') as file:
#     content=file.read()

# soup=BeautifulSoup(content, 'html.parser')
# # print(soup.title)
# # print(soup.title.string)
# # print(soup.prettify())
# # print(soup.a)

# all_anchor_tags=list(soup.find_all('a'))

# # for tag in all_anchor_tags:
#     # print(tag.get_text())
#     # print(tag.get('href'))

# # all_divs=soup.find_all(name='div',class_='top-container')
# print(all_divs)

'''Scrapping from the live website'''
response=requests.get('https://news.ycombinator.com/')
yc_webpage=response.text

soup=BeautifulSoup(yc_webpage,'lxml')
articles=soup.find_all(name='span',class_='titleline')
article_scores=soup.find_all(name='span',class_='score')

headlines=[]        #article headlines
links=[]            #article links
points=[]           #article points
for i in range(len(articles)):
    headlines.append(articles[i].find('a').getText())
    links.append(articles[i].find('a').get('href'))
    points.append(int(article_scores[i].getText().split(' ')[0]))


highest_point_index=points.index(max(points))
print(headlines[highest_point_index])
print(links[highest_point_index])

