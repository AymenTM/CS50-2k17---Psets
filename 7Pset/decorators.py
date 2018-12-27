
# Collection of the Decorators I've made.

from functools import wraps


def repeater(num_times):
    """Calls func 'num_times' times."""

    def decorator(func):

        @wraps(func)
        def wrapper(*args, **kwargs):

            for i in range(num_times):
                func(*args, **kwargs)

        return wrapper

    return decorator


def logger(func):
    """Logs the call and arguments with which functions were called
    in a file whose name is that of the function."""

    from logging import basicConfig, info, INFO
    basicConfig(filename=f'{func.__name__}.log', level=INFO)

    @wraps(func)
    def wrapper(*args, **kwargs):

        info(f"Ran '{func.__name__}' with args: {args}, and kwargs: {kwargs}")
        return func(*args, **kwargs)

    return wrapper


def timer(func):
    """Displays the total runtime of a function in seconds."""

    from time import perf_counter

    @wraps(func)
    def wrapper(*args, **kwargs):

        t1 = perf_counter()
        value = func(*args, **kwargs)
        t2 = perf_counter()
        print(f"[Finished '{func.__name__}' in {t2 - t1:.4f}s]")

        return value

    return wrapper
