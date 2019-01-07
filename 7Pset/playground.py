
from bs4 import BeautifulSoup
from robobrowser import RoboBrowser

import re
import csv

import config
from piscine import USERNAMES


# Logging Into a 42 Account — — — — — — — — — — — — — — — — — — —

browser = RoboBrowser(parser='html5lib')
browser.open('https://signin.intra.42.fr/users/sign_in')

form = browser.get_form()
form['user[login]'] = config.USER
form['user[password]'] = config.PASS

browser.submit_form(form)


# Retrieve and Store User Info — — — — — — — — — — — — — — — — — —

all_user_info = []

for username in USERNAMES:

    source = browser.open(f'https://profile.intra.42.fr/users/{username}')
    source = str(browser.parsed())
    soup = BeautifulSoup(source, 'html5lib')

    match = re.search(r'"Piscine C":{"level":\d\.\d\d?', str(soup))
    level = re.search(r'\d\.\d\d?', match[0])

    all_user_info.append(
        {
            'username': username,
            'level': float(level[0])
        }
    )


# Sort the Users by Level — — — — — — — — — — — — — — — — — — — —

def get_user_lvl(user):
    return user['level']

all_user_info.sort(key=get_user_lvl, reverse=True)


# Write to file the Result — — — — — — — — — — — — — — — — — — — —

with open('oct2018.csv', 'w') as f:

    n = 1

    csv_writer = csv.writer(f, delimiter=',')

    csv_writer.writerow(['Rank', 'Username', 'Level'])

    for user in all_user_info:
        csv_writer.writerow([str(n), user['username'], user['level']])
        n += 1

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
