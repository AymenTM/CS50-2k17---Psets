
"""Calculates how much time it will take to pay down
an amount owed for a monthly amount paid"""

import datetime
import calendar


def time_till_repaid(total_owed=0,
                     interest_rate=0.00,
                     monthly_payement=1,
                     show_progress=False):

    today = datetime.date.today()

    # Start date is first day of next month
    days_in_month = calendar.monthrange(today.year, today.month)[1]
    days_left_in_month = days_in_month - today.day

    start_date = today + datetime.timedelta(days=days_left_in_month + 1)

    end_date = start_date

    while total_owed > 0:

        total_owed += (interest_rate / 12) * total_owed
        total_owed -= monthly_payement
        total_owed = 0 if total_owed < 0 else round(total_owed, 2)

        if show_progress is True:
            print(f'{end_date}	${total_owed:.2f}')

        # Increment 'end_date' by the amount of days in the month
        days_in_month = calendar.monthrange(end_date.year, end_date.month)[1]
        end_date = end_date + datetime.timedelta(days=days_in_month)

    # Get the difference in time between the start and end dates
    years = round((end_date - start_date).days / 365, 1)
    months = int(round(round(years - int(years), 2) * 12, 0))

    # Print amount of time it will take to pay the amount owed
    s_ = '' if months < 2 else 's'
    if years > 1:
        s = '' if years < 2 else 's'
        print(f'{years:.0f} year{s}, {months} month{s_}')
    else:
        print(f'{months:.0f} month{s_}')


# Constants to plug
total_owed = 10000
interest_rate = 0.00
monthly_payement = 100.50
show_progress = False

time_till_repaid(total_owed, interest_rate, monthly_payement, show_progress)
