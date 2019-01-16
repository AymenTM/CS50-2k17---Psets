
# NAMEDTUPLES

from collections import namedtuple

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# # Creating a namedtuple (subclass)
# # __fields__
# # __doc__
# ————————————————————————————————————————————————————————————

# >>> Pigeon = namedtuple('Pigeon', ['id', 'wingspan', 'beek_size'])

# >>> Pigeon
# <class '__main__.Pigeon'>

# >>> Pigeon._fields
# ('id', 'wingspan', 'beek_size')

# >>> Pigeon.__doc__
# 'Pigeon(id, wingspan, beek_size)'


# # Creating an instance
# # _make(iterable)
# ————————————————————————————————————————————————————————————

# >>> pigeon1 = Pigeon(id=1, wingspan=13.2, beek_size=2)

#                      OR

# >>> pigeon1 = Pigeon._make([1, 13.2, 2])

#                      OR

# >>> pigeon1 = Pigeon(1, 13.2, 2)



# # __class__
# # _fields
# # __doc__
# # __repr__()
# ————————————————————————————————————————————————————————————

# >>> pigeon1.__class__
# <class '__main__.Pigeon'>

# >>> pigeon1._fields
# ('id', 'wingspan', 'beek_size')

# >>> pigeon1.__doc__
# 'Pigeon(id, wingspan, beek_size)'

#             ALSO

# >>> pigeon1.__repr__()
# 'Pigeon(id=1, wingspan=13.2, beek_size=2)'

# >>> pigeon1
# Pigeon(id=1, wingspan=13.2, beek_size=2)



# # _asdict()
# ————————————————————————————————————————————————————————————

# >>> pigeon1._asdict()
# OrderedDict([('id', 1), ('wingspan', 13.2), ('beek_size', 2)])

# >>> dict(pigeon1._asdict())
# {'id': 1, 'wingspan': 13.2, 'beek_size': 2}



# # _replace(**kwargs)
# ————————————————————————————————————————————————————————————

# >>> pigeon1._replace(wingspan=12.8, beek_size=3.1)
# Pigeon(id=1, wingspan=12.8, beek_size=3.1)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

# >>> pigeon2 = pigeon1._replace(wingspan=12.8, beek_size=3.1)

# >>> pigeon2
# Pigeon(id=1, wingspan=12.8, beek_size=3.1)



# # Lookup
# ————————————————————————————————————————————————————————————

# >>> pigeon1[0]
# 1
# >>> pigeon1[1]
# 13.2

#         OR

# >>> pigeon1.wingspan
# 13.2
# >>> pigeon1.beek_size
# 2


# # _field
# ————————————————————————————————————————————————————————————

# >>> Pigeon._fields # namedtuple class
# ('id', 'wingspan', 'beek_size')

# >>> pigeon1._fields # instance
# ('id', 'wingspan', 'beek_size')


# # __doc__
# ————————————————————————————————————————————————————————————


# >>> Pigeon.__doc__ # namedtuple class
# 'Pigeon(id, wingspan, beek_size)'

# >>> pigeon1.__doc__  # instance
# 'Pigeon(id, wingspan, beek_size)'

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# >>> Book = namedtuple('Book', ['id', 'title', 'authors'])

# >>> Book.__doc__ += ': Hardcover book in active collection'
# >>> Book.id.__doc__ = '13-digit ISBN'
# >>> Book.title.__doc__ = 'Title of first printing'
# >>> Book.authors.__doc__ = 'List of authors sorted by last name'

# >>> Book.__doc__
# 'Book(id, title, authors): Hardcover book in active collection'

# >>> Book.id.__doc__
# '13-digit ISBN'

# >>> Book.title.__doc__
# 'Title of first printing'

# >>> Book.authors.__doc__
# 'List of authors sorted by last name'

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

Color = namedtuple('RGB', ['red', 'green', 'blue'])

print(Color)
print(Color.__doc__)

print()

orange = Color(23, 243, 87)

print(orange.__str__())
print(orange.__doc__)
print(orange.__class__)

print()

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

Teacher = namedtuple('Teacher', ['name', 'gender', 'subject'])
english_teacher = Teacher('Frank Bernard', 'male', 'Math')

print(english_teacher)
print(english_teacher.__doc__)
print(english_teacher._fields)
print(dict(english_teacher._asdict()))

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
