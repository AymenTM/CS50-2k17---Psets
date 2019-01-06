
# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


# s1 = {1, 2, 3, 4, 5}
# s2 = {11, 12, 13, 14, 15}

# s1.add(6)
# s1.update([7, 8, 9, 10], s2)

# print(s1)


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# s1 = {1, 2, 3, 4, 5}

# s1.remove(4)
# s1.discard(5)

# print(s1)


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# s1 = {1, 2, 3}
# s2 = {2, 3, 4}
# s3 = {3, 4, 5}

# s4 = s1.intersection(s2)
# s5 = s1.intersection(s2, s3)

# print(s4)
# print(s5)


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


# s1 = {1, 2, 3}
# s2 = {2, 3, 4}
# s3 = {3, 4, 5}

# s4 = s1.difference(s2)


# print(s4)

# {1}


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# s1 = {1, 2, 3}
# s2 = {2, 3, 4}

# s3 = s1.symmetric_difference(s2)

# print(s3)

# {1, 4}


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

employees = ['Corey', 'Jim', 'Steven', 'April', 'Judy', 'Jenn', 'John', 'Jane']

gym_members = ['Corey', 'April', 'John']

developpers = ['Corey', 'Steven', 'April', 'Judy', 'Jane']


# gym member and developper
result = set(gym_members).intersection(developpers)
print(result)

# neither gym member and neither developper
result = set(employees).difference(gym_members, developpers)
print(result)


cpy = developpers.copy()
cpy.add('Lucy')

print(cpy)
print(developpers)
