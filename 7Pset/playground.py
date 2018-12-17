
import datetime

date = datetime.datetime(2016, 9, 24, 12, 30, 45)

sentence = '{0:%B %d, %Y} fell on a {0:%A} and was the {0:%j} day of the year.'.format(date)

print(sentence)
