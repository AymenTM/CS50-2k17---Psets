
# DEFAULT DICTIONNARIES

from collections import defaultdict

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# >>> d_int = defaultdict(int)
# >>> d_list = defaultdict(list)
# >>> d_foo = defaultdict(lambda: '<missing>')

# >>> d_int
# defaultdict(<class 'int'>, {})

# >>> d_list
# defaultdict(<class 'list'>, {})

# >>> d_foo
# defaultdict(<function <lambda> at 0x10d9ca6a8>, {})

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# >>> d_int = defaultdict(int, a=10, b=12, c=13)
# >>> d_int
# defaultdict(<class 'int'>, {'a': 10, 'b': 12, 'c': 13})

#                         OR

# >>> d_int = defaultdict(int, {'a':10, 'b':12, 'c':13})
# >>> d_int
# defaultdict(<class 'int'>, {'a': 10, 'b': 12, 'c': 13})

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# >>> d_int['a']
# 10

# >>> d_int['d']
# 0

# >>> d_int
# defaultdict(<class 'int'>, {'a': 10, 'b': 12, 'c': 13, 'd': 0})

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# >>> d_int.default_factory = lambda: 1

# >>> d_int['f']
# 1

# >>> d_int
# defaultdict(<function <lambda> at 0x10d9ca598>, {'a': 10, 'b': 12, 'c': 13, 'd': 0, 'f': 1})

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# Counting Number of Keys (using 'defaultdict's)

# colors = ['red', 'blue', 'yellow', 'red', 'green', 'blue']

# 1) (good)

# d = {}
# for color in colors:
#     d[color] = d.get(color, 0) + 1

# print(d)

# 2) (better & faster)


colors = ['red', 'blue', 'yellow', 'red', 'green', 'blue']

d = defaultdict(int)
for color in colors:
    d[color] += 1

print(dict(d))


# {'red': 2, 'blue': 2, 'yellow': 1, 'green': 1}

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

