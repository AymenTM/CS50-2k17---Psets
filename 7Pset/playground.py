
import datetime
import pytz

dt = datetime.datetime.strptime(date_string, format)

dt_str = 'July 26, 2016'
dt = datetime.datetime.strptime(dt_str, '%B %d, %Y')

print(dt)
