
import itertools

# counter = itertools.count(start=0, step=1)

# >>> print(next(counter))
# >>> print(next(counter))
# >>> print(next(counter))
# >>> print(next(counter))

# 0
# 1
# 2
# 3

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# data = [100, 200, 300, 400]

# daily_data = list(zip(itertools.count(), data))

# >>> print(daily_data)

# [(0, 100), (1, 200), (2, 300), (3, 400)]

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# cycle_counter = itertools.cycle([1, 2, 3])

# >>> print(next(cycle_counter))
# >>> print(next(cycle_counter))
# >>> print(next(cycle_counter))
# >>> print(next(cycle_counter))
# >>> print(next(cycle_counter))
# >>> print(next(cycle_counter))

# 1
# 2
# 3
# 1
# 2
# 3

# switch = itertools.cycle(['On', 'Off'])

# >>> print(next(switch))
# >>> print(next(switch))
# >>> print(next(switch))
# >>> print(next(switch))
# >>> print(next(switch))
# >>> print(next(switch))

# 'On'
# 'Off'
# 'On'
# 'Off'
# 'On'
# 'Off'


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# squares = list(map(pow, range(1, 11), itertools.repeat(2)))

# >>> print(squares)

# [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# squares = list(itertools.starmap(pow, list(zip(range(4), itertools.repeat(2)))))

# print(squares)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# perms = list(itertools.permutations(range(0, 4)))

# >>> print(perms)

# [(0, 1, 2, 3), (0, 1, 3, 2), (0, 2, 1, 3), (0, 2, 3, 1), (0, 3, 1, 2), (0, 3, 2, 1),
# (1, 0, 2, 3), (1, 0, 3, 2), (1, 2, 0, 3), (1, 2, 3, 0), (1, 3, 0, 2), (1, 3, 2, 0),
# (2, 0, 1, 3), (2, 0, 3, 1), (2, 1, 0, 3), (2, 1, 3, 0), (2, 3, 0, 1), (2, 3, 1, 0),
# (3, 0, 1, 2), (3, 0, 2, 1), (3, 1, 0, 2), (3, 1, 2, 0), (3, 2, 0, 1), (3, 2, 1, 0)]


# perms = list(itertools.permutations(range(0, 3), 2))

# >>> print(perms)

# [(0, 1), (0, 2), (1, 0), (1, 2), (2, 0), (2, 1)]

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# combs = list(itertools.combinations(range(0, 3), 2))

# >>> print(combs)

# [(0, 1), (0, 2), (1, 2)]

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# perms_with_repeats = list(itertools.product('ABCDEFGHIJKLMN0PQRSTUVWXYZabcdefghijklmnopqrstuvwxyz', repeat=5))

# for comb in perms_with_repeats:
#     print(f"{''.join(comb)}")

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# combs_with_reps = list(itertools.combinations_with_replacement('01', 4))

# >>> for comb in combs_with_reps:
# ...    print(f"{''.join(comb)}")

# 0000
# 0001
# 0011
# 0111
# 1111

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# perms_with_reps = list(itertools.product('01', repeat=4))


# >>> for comb in perms_with_reps:
# ...    print(f"{''.join(comb)}")

# 0000
# 0001
# 0010
# 0011
# 0100
# 0101
# 0110
# 0111
# 1000
# 1001
# 1010
# 1011
# 1100
# 1101
# 1110
# 1111

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# letters = ['a', 'b', 'c', 'd']
# numbers = [1, 2, 3, 4]
# names = ['Alex', 'Bob', 'Carl', 'David']

# combined = list(itertools.chain(letters, numbers, names))


# >>> print(combined)

# ['a', 'b', 'c', 'd', 1, 2, 3, 4, 'Alex', 'Bob', 'Carl', 'David']

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# Getting certain lines of a file

# with open('playground.py', mode='r') as f:

#     desired_lines = itertools.islice(f, 1, 10)

#     for line in desired_lines:
#         print(line, end='')


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# Keep only those who passed


# students = ['Tim', 'Sam', 'Becky', 'John']
# passed = [True, False, True, True]

# graduates = list(itertools.compress(students, passed))

# >>> print(graduates)

# ['Tim', 'Becky', 'John']


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# Keep only those who passed

# def selector(element):
#     if element <= 3:
#         return True
#     return False


# numbers = [2, 4, 1, 5, 3, 6]


# selected = list(filter(selector, numbers))

# >>> print(selected)

# [2, 1, 3]


# Keep only those who didn't passed

# selected = list(itertools.filterfalse(selector, numbers))

# >>> print(selected)

# [4, 5, 6]

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


# def selector(element):
#     if element <= 5:
#         return True
#     return False


# numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]


# filtered = list(itertools.takewhile(selector, numbers))
# reverse_filtered = list(itertools.dropwhile(selector, numbers))

# >>> print(filtered)
# >>> print(reverse_filtered)

# [1, 2, 3, 4, 5]
# [6, 7, 8, 9, 10]


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# Accumulate Values of an Iterable (with addition)


# numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# results = list(itertools.accumulate(numbers))

# >>> print(results)

# [1, 3, 6, 10, 15, 21, 28, 36, 45, 55]


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


# Accumulate Values of an Iterable (with multiplication)


# import operator

# numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# results = list(itertools.accumulate(numbers, operator.sub))


# >>> print(results)

# [1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800]


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# List of Dictionaries representing studtents sorted by grade
students = [
    {
        'name': 'Toby Jackson',
        'year': 'Sophmore',
        'grade': 'A'
    },
    {
        'name': 'Sam Gowchni',
        'year': 'Freshman',
        'grade': 'A'
    },
    {
        'name': 'Marc Salvi',
        'year': 'Senior',
        'grade': 'A'
    },
    {
        'name': 'Jerry Polgy',
        'year': 'Freshman',
        'grade': 'A'
    },
    {
        'name': 'Ralph Berret',
        'year': 'Senior',
        'grade': 'B'
    },
    {
        'name': 'Ralph Berret',
        'year': 'Senior',
        'grade': 'B'
    },
    {
        'name': 'Bruno Selko',
        'year': 'Sophmore',
        'grade': 'B'
    },
    {
        'name': 'Louis Philips',
        'year': 'Sophmore',
        'grade': 'C'
    },
    {
        'name': 'George Derljo',
        'year': 'Freshman',
        'grade': 'C'
    }
]


def get_grade(student):
    return student['grade']


groupings = itertools.groupby(students, key=get_grade)


for key, group in groupings:
    print(f"There are {len(list(group))} students with {key}'s.")


# # Output

# "There are 4 students with A's."
# "There are 3 students with B's."
# "There are 2 students with C's."


# for key, group in groupings:
#     for student in group:
#         if key == 'A':
#             a_ = 'an'
#         else:
#             a_ = 'a'
#         print(f'{student["name"]} is a {student["year"]} and got {a_} {key} on his finals.')
#     print()

#  # Output

# 'Toby Jackson is a Sophmore and got an A on his finals.'
# 'Sam Gowchni is a Freshman and got an A on his finals.'
# 'Marc Salvi is a Senior and got an A on his finals.'
# 'Jerry Polgy is a Freshman and got an A on his finals.'

# 'Ralph Berret is a Senior and got a B on his finals.'
# 'Ralph Berret is a Senior and got a B on his finals.'
# 'Bruno Selko is a Sophmore and got a B on his finals.'

# 'Louis Philips is a Sophmore and got a C on his finals.'
# 'George Derljo is a Freshman and got a C on his finals.'


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# Making duplicates of iterables


# numbers = [1, 2, 3, 4, 5]

# copy1, copy2, copy3, copy4, copy5 = itertools.tee(numbers, 5)


# >>> print(list(copy1))
# >>> print(list(copy2))
# >>> print(list(copy3))
# >>> print(list(copy4))
# >>> print(list(copy5))

# [1, 2, 3, 4, 5]
# [1, 2, 3, 4, 5]
# [1, 2, 3, 4, 5]
# [1, 2, 3, 4, 5]
# [1, 2, 3, 4, 5]


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
