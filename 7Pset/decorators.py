# Decorators

from functools import wraps


def repeat(times):
    """ Calls func 'times' times. """

    def decorator(func):

        @wraps(func)
        def wrapper(*args, **kwargs):

            for i in range(times):
                func(*args, **kwargs)

        return wrapper

    return decorator


def logger(func):
    """ Logs the call and arguments with which functions were called
    in a file whose name is that of the function. """

    import logging
    logging.basicConfig(filename=f'{func.__name__}.log', level=logging.INFO)

    @wraps(func)
    def wrapper(*args, **kwargs):

        logging.info(f'Ran with args: {args}, and kwargs: {kwargs}')
        return func(*args, **kwargs)

    return wrapper


def timer(func):
    """ Displays the total runtime of a function. """

    import time

    @wraps(func)
    def wrapper(*args, **kwargs):

        t1 = time.perf_counter()
        value = func(*args, **kwargs)
        t2 = time.perf_counter()
        print(f"[Finished '{func.__name__}' in {t2 - t1:.4f}s]")

        return value

    return wrapper
