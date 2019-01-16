
# CHAINING ITERABLES & DICTIONARIES w/ itertools.chain & collections.ChainMap

# from collections import ChainMap
# from itertools import chain

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# d1 = {'James': 'red', 'Sam' : 'blue', 'Gabriel': 'yellow'}
# d2 = {'Lulu': 1, 'Rebecca' : 2, 'Jarret': 3}
# d3 = {'James': 'french', 'Becky' : 'american', 'Nancy': 'english'}
# d4 = {'Trudeau': 'gamma', 'Sally' : 'berkley', 'Samantha': 'harvard'}

# d = dict(ChainMap(d1, d2, d3, d4))
# _d = dict(chain(d1.items(), d2.items(), d3.items(), d4.items()))

# print()
# print(d)
# print()
# print(_d)
# print()

# for i in d:
# print(i)
# print(d['Gabriel'])


# {'Trudeau': 'gamma', 'Sally': 'berkley', 'Samantha': 'harvard', 'Philip': 'french', 'Becky': 'american', 'Nancy': 'english', 'Lulu': 1, 'Rebecca': 2, 'Jarret': 3, 'James': 'red', 'Sam': 'blue', 'Gabriel': 'yellow'}

# {'James': 'red', 'Sam': 'blue', 'Gabriel': 'yellow', 'Lulu': 1, 'Rebecca': 2, 'Jarret': 3, 'Philip': 'french', 'Becky': 'american', 'Nancy': 'english', 'Trudeau': 'gamma', 'Sally': 'berkley', 'Samantha': 'harvard'}

# ================================================================================================

# {'Trudeau': 'gamma', 'Sally': 'berkley', 'Samantha': 'harvard', 'James': 'red', 'Becky': 'american', 'Nancy': 'english', 'Lulu': 1, 'Rebecca': 2, 'Jarret': 3, 'Sam': 'blue', 'Gabriel': 'yellow'}

# {'James': 'french', 'Sam': 'blue', 'Gabriel': 'yellow', 'Lulu': 1, 'Rebecca': 2, 'Jarret': 3, 'Becky': 'american', 'Nancy': 'english', 'Trudeau': 'gamma', 'Sally': 'berkley', 'Samantha': 'harvard'}


#             —— collections.ChainMap ——

#             {'Trudeau': 'gamma',
#              'Sally': 'berkley',
#              'Samantha': 'harvard',
#              'Philip': 'french',
#              'Becky': 'american',
#              'Nancy': 'english',
#              'Lulu': 1,
#              'Rebecca': 2,
#              'Jarret': 3,
#              'James': 'red',
#              'Sam': 'blue',
#              'Gabriel': 'yellow'}

# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#             —— itertools.chain ——

#             {'James': 'red',
#              'Sam': 'blue',
#              'Gabriel': 'yellow',
#              'Lulu': 1,
#              'Rebecca': 2,
#              'Jarret': 3,
#              'Philip': 'french',
#              'Becky': 'american',
#              'Nancy': 'english',
#              'Trudeau': 'gamma',
#              'Sally': 'berkley',
#              'Samantha': 'harvard'}

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# CHAINING LISTS, TUPLES & SETS


# from itertools import chain


# Example #1

# list1 = [1, 2, 3, 4, 5]
# tuple1 = (6, 7, 8, 9, 10)
# set1 = {11, 12, 13, 14, 15}

# chain = chain(list1, tuple1, set1)

# print(chain)
# print(list(chain))

# <itertools.chain object at 0x101c16e80>
# [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]


# Example #2

# letters = ['a', 'b', 'c', 'd']
# numbers = (1, 2, 3, 4)
# names = {'Alex', 'Becky', 'Carl', 'Dan'}

# chain = chain(letters, numbers, names)

# print(chain)
# print(list(chain))

# <itertools.chain object at 0x10d9b2198>
# ['a', 'b', 'c', 'd', 1, 2, 3, 4, 'Alex', 'Carl', 'Dan', 'Becky']

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# CHAINING DICTIONARIES w/ itertools.chain()


from itertools import chain

d1 = {1: 'A', 2: 'B', 3: 'C'}
d2 = {4: 'D', 5: 'E', 6: 'F'}
d3 = {7: 'G', 8: 'H', 9: 'I'}

d = chain(d1.items(), d2.items(), d3.items())

print(d)
print(dict(d))

# <itertools.chain object at 0x10ba681d0>

# {1: 'A', 2: 'B', 3: 'C', 4: 'D', 5: 'E', 6: 'F', 7: 'G', 8: 'H', 9: 'I'}

# {1: 'A', 2: 'B', 3: 'C',
#  4: 'D', 5: 'E', 6: 'F',
#  7: 'G', 8: 'H', 9: 'I'}

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# CHAINING DICTIONARIES w/ collections.ChainMap


from collections import ChainMap

d1 = {1: 'A', 2: 'B', 3: 'C'}
d2 = {4: 'D', 5: 'E', 6: 'F'}
d3 = {7: 'G', 8: 'H', 9: 'I'}

d = ChainMap(d1, d2, d3)

print(d)
print(dict(d))

# ChainMap({1: 'A', 2: 'B', 3: 'C'}, {4: 'D', 5: 'E', 6: 'F'}, {7: 'G', 8: 'H', 9: 'I'})

# {7: 'G', 8: 'H', 9: 'I',
#  4: 'D', 5: 'E', 6: 'F',
#  1: 'A', 2: 'B', 3: 'C'}

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# CHAINMAPS

from collections import ChainMap

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

d1 = {1: 'A', 2: 'B', 3: 'C'}
d2 = {4: 'D', 5: 'E', 6: 'F'}
d3 = {7: 'G', 8: 'H', 9: 'I'}

new_chain = ChainMap(d1, d2, d3)

# >>> chain
# ChainMap({1: 'A', 2: 'B', 3: 'C'},
#          {4: 'D', 5: 'E', 6: 'F'},
#          {7: 'G', 8: 'H', 9: 'I'})

# >>> dict(chain)
# {7: 'G', 8: 'H', 9: 'I',
#  4: 'D', 5: 'E', 6: 'F',
#  1: 'A', 2: 'B', 3: 'C'}

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# >>> d1 = {1: 'Jack', 2: 'Sam'}
# >>> d2 = {3: 'Paul', 4: 'Tim'}

# >>> chain = ChainMap(d1, d2)

# >>> chain
# ChainMap({1: 'Jack', 2: 'Sam'}, {3: 'Paul', 4: 'Tim'})

# >>> chain[1]
# 'Jack'
# >>> chain[2]
# 'Sam'
# >>> chain[3]
# 'Paul'
# >>> chain[4]
# 'Tim'

# >>> chain.new_child()
# ChainMap({}, {1: 'Jack', 2: 'Sam'}, {3: 'Paul', 4: 'Tim'})

# >>> chain.parents
# ChainMap({3: 'Paul', 4: 'Tim'})

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
