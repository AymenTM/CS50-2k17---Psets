
from bs4 import BeautifulSoup
import requests
import csv

source = requests.get('http://coreyms.com/').text

soup = BeautifulSoup(source, 'lxml')

articles = soup.find_all('article')

with open('coreyschafer_articles.csv', 'w') as csv_file:

    csv_writer = csv.writer(csv_file, delimiter=',')

    csv_writer.writerow(['header', 'summary', 'video_link'])

    for article in articles:

        header = article.a.text
        summary = article.div.p.text

        try:
            vid_src = article.find('iframe', class_='youtube-player')['src']
            vid_src = vid_src.split('?')[0].split('/')[-1]
        except TypeError:
            yt_link = None
        else:
            yt_link = f'https://www.youtube.com/watch?v={vid_src}'

        csv_writer.writerow([header, summary, yt_link])

# Credits: Corey Schafer - Youtube
