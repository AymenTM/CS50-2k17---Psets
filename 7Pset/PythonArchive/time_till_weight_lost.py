
"""Calculates date at which you will reach a goal weight
and how many weeks in total it will take."""

import datetime


def time_till_weight_lost(current_weight, goal_weight, avg_weight_loss_per_week):

    start_date = datetime.date.today()
    end_date = start_date

    weeks = 0

    while goal_weight < current_weight:

        current_weight -= avg_weight_loss_per_week
        end_date += datetime.timedelta(weeks=1)

        weeks += 1

    print(end_date.strftime('%B %d, %Y'))
    print(f'Goal reached in {weeks} weeks.')



# Constants (kg)
current_weight = 130.0
goal_weight = 70.0
avg_weight_loss_per_week = 0.65

time_till_weight_lost(current_weight, goal_weight, avg_weight_loss_per_week)
