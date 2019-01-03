
# To understand

my_list = [1, 2, 3, 4, 5]

for i in my_list:
    print(i)
    if i == 7:
        break
else:
    print("Didnt hit the 'break' statement :/")


# Example

from random import choice


def find_index(to_search, target):

    for i, value in enumerate(to_search):
        if value == target:
            break
    else:
        return 'not found'
    return f'index at {i}'


all_users = ['Steve', 'Rick', 'David', 'Maurice', 'Samantha', 'Derek']
valid_users = ['Steve', 'Rick', 'David']
name = choice(all_users)

print(f'{name.upper()} is {find_index(valid_users, name)}')
