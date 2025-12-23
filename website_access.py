import requests
from bs4 import BeautifulSoup

url = "https://buffstreams.plus/nflstreams2"
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')

soup.find_all('a')