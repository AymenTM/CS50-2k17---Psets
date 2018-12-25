
from functools import wraps


def do_twice(func):

    @wraps(func)
    def wrapper_do_twice(*args, **kwargs):
        func(*args, **kwargs)
        func(*args, **kwargs)

    return wrapper_do_twice


@do_twice
def say_msg(msg):
    print(msg)


>>> say_msg('Decorators are cool!')
'Decorators are cool!'
'Decorators are cool!'
