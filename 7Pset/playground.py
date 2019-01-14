
# MORE GENERATORS & GENERATOR EXPRESSIONS

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# def gen_nums(start=0, step=1):

#     _start = start
#     while True:
#         yield _start
#         _start += step


# stepper = gen_nums(10, 2)

# >>> for i in range(0, 6):
# ...    print(stepper.__next__())

# >>> print(stepper.__next__())
# >>> print(stepper.__next__())
# >>> print(stepper.__next__())
# >>> print(stepper.__next__())
# >>> print(stepper.__next__())
# >>> print(stepper.__next__())

#       Output:

        # 10
        # 12
        # 14
        # 16
        # 18
        # 20

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# def gen_nums(start=0, end=51, step=1):

#     _start = start
#     while _start < end:
#         yield _start
#         _start += step


# >>> stepper = gen_nums(start=10, end=51, step=2)


# >>> print(list(stepper))

# [10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50]

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# GENERATOR EXPRESSION
# stepper = (x for x in range(10, 51, 2))

# >>> print(stepper)
# >>> print(list(stepper))

# <generator object <genexpr> at 0x100a15390>
# [10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50]

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# stepper = (x for x in range(0, 11, 2))

# print(list(stepper))

# [0, 2, 4, 6, 8, 10]


# stepper = (x * 5 for x in range(0, 10))

# print(list(stepper))

# [0, 5, 10, 15, 20, 25, 30, 35, 40, 45]

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# PARTIAL Functions

# from functools import partial


# def say_my_full_name(first, last):

#     print(f'{first} {last}')


# smiths = partial(say_my_full_name, last='Smith')

# smiths('John')
# smiths('Tim')
# smiths('Casper')
# smiths('Lula')

# John Smith
# Tim Smith
# Casper Smith
# Lula Smith

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# COUNTING w/ DICTIONARY

# colors = ['red', 'green', 'red', 'blue', 'green', 'red']

# my_dict = {}
# for color in colors:
#     if color not in my_dict:
#         my_dict[color] = 0
#     my_dict[color] += 1

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# SORTING A DICTIONARY

# my_dict = {'red': 3, 'blue': 1, 'green': 2}

# sorted_dict = dict(sorted(my_dict.items(), reverse=True, key=lambda item: item[1]))

# >>> print(sorted_dict)

# {'blue': 1, 'green': 2, 'red': 3}

# {'red': 3, 'green': 2, 'blue': 1}

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —





        import collections








