# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         from sys import getsizeof

#         >>> i = 0
#         >>> d = {'name': 'John', 'lname': 'Doe'}
#         >>> t = [('name', 'John'), ('lname', 'Doe')]

#         >>> print(getsizeof(i))
#         24 # bytes

#         >>> print(getsizeof(d))
#         240

#         >>> print(getsizeof(t))
#         80

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —



# SOME BUILT-IN FUNCTIONS

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> callable(int)
#         True

#         >>> int.__call__()
#         0

#         >>> int()
#         0

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> chr(97)
#         'a'

#         >>> chr(8364)
#         '€'

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> abs(-10)
#         10

#         >>> abs(-19.27364)
#         19.27364

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> l = [1, 2, 3, 0, 5]

#         >>> all(l)
#         False

#         >>> l = ['John', 'Matt', '']

#         >>> all(l)
#         False

#         >>> l = ['John', 'Matt', None]

#         >>> all(l)
#         False

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> any('a')
#         True

#         >>> any(['James', '', ''])
#         True

#         >>> any([0, 0, 1, 0])
#         True

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> bool()
#         False

#         >>> bool(0)
#         False

#         >>> bool(1)
#         True

#         >>> bool('')
#         False

#         >>> bool('a')
#         True

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         class C:
#             @classmethod
#             def func(cls, *args):
# #              ...

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# class C:
#     letter = 'c'

# delattr(instance, 'letter')

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#     >>> d = dict([('name', 'James'), ('age', 12)])

#     >>> d
#     {'name': 'James', 'age': 12}


#     >>> d = dict({'name': 'James', 'age': 12})

#     >>> d
#     {'name': 'James', 'age': 12}


#     >>> d = dict(name='James', age=12)

#     >>> d
#     {'name': 'James', 'age': 12}


#     >>> d = dict()

#     >>> d
#     {}

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#     # Brand New Python Interative Shell

#     >>> dir()
#     ['__annotations__', '__builtins__', '__doc__', '__loader__',
#      '__name__', '__package__', '__spec__']

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#     >>> class C:
#     ...     """
#     ...     Autobiographical class for the letter 'C'.
#     ...     """
#     ...
#     ...     letter = 'c'
#     ...
#     ...     def print_me():
#     ...         print('c')
#     ...

#     >>> dir(C)
#     ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__',
#     '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__',
#     '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__',
#     '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__',
#     'letter', 'print_me']

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#     >>> dir(dict)
#     ['__class__', '__contains__', '__delattr__', '__delitem__', '__dir__', '__doc__',
#     '__eq__', '__format__', '__ge__', '__getattribute__', '__getitem__', '__gt__',
#     '__hash__', '__init__', '__init_subclass__', '__iter__', '__le__', '__len__',
#     '__lt__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__',
#     '__setattr__', '__setitem__', '__sizeof__', '__str__', '__subclasshook__',
#     'clear', 'copy', 'fromkeys', 'get', 'items', 'keys', 'pop', 'popitem',
#     'setdefault', 'update', 'values']

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> import sys

#         >>> dir(sys)
#         ['__breakpointhook__', '__displayhook__', '__doc__', '__excepthook__',
#         '__interactivehook__', '__loader__', '__name__', '__package__', '__spec__',
#         '__stderr__', '__stdin__', '__stdout__', '_clear_type_cache', '_current_frames',
#         '_debugmallocstats', '_framework', '_getframe', '_git', '_home', '_xoptions',
#         'abiflags', 'api_version', 'argv', 'base_exec_prefix', 'base_prefix', 'breakpointhook',
#         'builtin_module_names', 'byteorder', 'call_tracing', 'callstats', 'copyright',
#         'displayhook', 'dont_write_bytecode', 'exc_info', 'excepthook', 'exec_prefix',
#         'executable', 'exit', 'flags', 'float_info', 'float_repr_style', 'get_asyncgen_hooks',
#         'get_coroutine_origin_tracking_depth', 'get_coroutine_wrapper', 'getallocatedblocks',
#         'getcheckinterval', 'getdefaultencoding', 'getdlopenflags',
#         'getfilesystemencodeerrors',
#         ...

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> d = divmod(342, 5)

#         >>> d
#         (68, 2)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> q, r = divmod(8712, 9)

#         >>> q
#         968

#         >>> r
#         0

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # # playground.py
        # print('Hello World!')

        # exec(
        #     compile(
        #             source=open('playground.py').read(),
        #             filename='errors.log',
        #             mode='exec'
        #     )
        # )

        # # Output:
        # Hello World!

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # exec("""

        # for i in range(5):
        #     print('This function is cool!')

        # print('\\nOk we are done!')

        #     """)

        # Output:
        # This function is cool!
        # This function is cool!
        # This function is cool!
        # This function is cool!
        # This function is cool!

        # Ok we are done!

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> code_obj = compile(
        #                         source=open('playground.py').read(),
        #                         filename='error.log',
        #                         mode='exec'
        #                 )

        # >>> code_obj
        # <code object <module> at 0x1090b1f60, file "error.log", line 245>

        # >>> exec(code_obj)
        # Hello World!

        # >>> eval(code_obj)
        # Hello World!

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> list(
        # ...     filter(
        # ...             lambda x: x % 2 is 0,
        # ...             range(1, 11)
        # ...     )
        # ... )
        # [2, 4, 6, 8, 10]

        # >>> list(itertools.filterfalse(lambda x: x % 2 is 0, range(1, 11)))
        # [1, 3, 5, 7, 9]

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # # Money
        # rich & poor dad
        # 4-hour work week

        # # Emotional, Social Skill
        # 48 Laws of Power
        # How to Win Friends and Influence People

        # # Man
        # The Way of the Superior Man
        # Man in Search of meaning - victor frankl
        # Mastery by george lenard

        # # Mind and Stoicism
        # Mindfullness for Beginners: Reclaiming the Present Moment and your Life - John Cabedsen
        # Enchiridion - Epictetus
        # The Obstacle is the Way - Ryan Holiday

        # Recommended Authors:
        # Epictetus
        # Cenyca
        # Marcus Aurelius

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> class C:
        # ...     letter = 'c'
        # ...

        # >>> getattr(C, 'letter')
        # 'c'

        # >>> C.letter
        # 'c'

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> globals()
        # {'__name__': '__main__', '__doc__': None, '__package__': None,
        # '__loader__': <class '_frozen_importlib.BuiltinImporter'>,
        # '__spec__': None, '__annotations__': {},
        # '__builtins__': <module 'builtins' (built-in)>}

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> class C:
        # ...     letter = 'c'
        # ...

        # >>> hasattr(C, 'letter')
        # True

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> hash('2019')
        # 8381135195210278961

        # >>> hash('hey John')
        # 32976569263748556

        # >>> hash(23)
        # 23

        # >>> hash(9347)
        # 9347

        # >>> hash(-298437)
        # -298437

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> help('itertools.tee')


        # Help on built-in function tee in itertools:

        # itertools.tee = tee(...)
        #     tee(iterable, n=2) --> tuple of n independent iterators.
        # (END)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> def say_hi():
        # ...     """Prints 'hi' to screen."""
        # ...     print('hi')

        # >>> help(say_hi)


        # Help on function say_hi in module __main__:

        # say_hi()
            # Prints 'hi' to screen.

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> help(list)

        # >>> help(bool)

        # >>> help(zip)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


#         >>> a = 1
#         >>> b = 0

#         >>> id(a)
#         4346801232

#         >>> id(b)
#         4346801200


#         >>> x = y = 3

#         >>> id(x)
#         4346801296

#         >>> id(y)
#         4346801296


#         >>> c = 1
#         >>> d = 0
#         >>> e = 3

#         >>> id(c)
#         4346801232

#         >>> id(d)
#         4346801200

#         >>> id(e)
#         4346801296


#         >>> L1 = [1, 2, 3, 4]
#         >>> L2 = [1, 2, 3, 4]

#         >>> id(L1)
#         4349136136

#         >>> id(L2)
#         4349136840


# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

#         >>> input('Name: ')
#         Name: _

#         >>> input('Name: ')
#         Name: Jim
#         'Jim'

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> int(10)
        # 10

        # >>> int('125')
        # 125

        # >>> int('5A', base=16)
        # 90

        # >>> int('101', base=2)
        # 5

        # >>> int('17777777777', base=8)
        # 2147483647

        # >>> int('7fffffff', base=16)
        # 2147483647

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> class C:
        # ...     letter = 'c'
        # ...

        # >>> inst = C()

        # >>> inst
        # <__main__.C object at 0x10373fb70>

        # >>> isinstance(inst, C)
        # True

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

        # >>> class Letter(object):
        # ...     pass
        # ...

        # >>> class C(Letter):
        # ...     letter = 'c'
        # ...

        # >>> issubclass(C, Letter)
        # True

        # >>> issubclass(C, C)
        # True

        # >>> issubclass(C, object)
        # True

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

a = [1, 2, 3]

b = iter(a)
c = iter(b)

print(a)
print(b)
print(c)
print(a is b)
print(b is c)
print(c is a)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —









