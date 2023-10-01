import requests
import lxml
from bs4 import BeautifulSoup
import spotipy
from spotipy.oauth2 import SpotifyOAuth
import os
from dotenv import load_dotenv
load_dotenv('projects\Web Scrapping\spotify playlist maker\.env')


''' asking user which year they want to visit'''
date=input('Which year do you want to travel to? YYYY-MM-DD')

URL=f'https://www.billboard.com/charts/hot-100/{date}'

response=requests.get(URL)
response.encoding='utf-8'

soup=BeautifulSoup(response.text,'lxml')
songs=soup.find_all(name='h3',id="title-of-a-story", class_="a-no-trucate")
song_list=[song.get_text().strip() for song in songs]


'''Spotify setup'''
Client_ID=os.getenv('CLIENT_ID')
print(Client_ID)
Client_Secret=os.getenv('CLIENT_SECRET')
redirect_uri='http://example.com'

sp = spotipy.Spotify(
    auth_manager=SpotifyOAuth(
        scope="playlist-modify-private",
        redirect_uri=redirect_uri,
        client_id=Client_ID,
        client_secret=Client_Secret,
        show_dialog=True,
        cache_path="C:\\Python310\\codes\\projects\\spotify playlist maker\\token.txt"
    )
)
user_id = sp.current_user()["id"]
# print(user_id)

'''Searching Spotify for songs by title'''
song_uris = []
year = date.split("-")[0]
for song in song_list:
    result = sp.search(q=f"track:{song} year:{year}", type="track",limit=1)
    print(result)
    try:
        uri = result["tracks"]["items"][0]["uri"]
        song_uris.append(uri)
    except IndexError:
        print(f"{song} doesn't exist in Spotify. Skipped.")

'''Creating a new private playlist in Spotify'''
playlist = sp.user_playlist_create(user=user_id, name=f"{date} Billboard 100", public=False)
# print(playlist)

'''Adding songs found into the new playlist'''
sp.playlist_add_items(playlist_id=playlist["id"], items=song_uris)

