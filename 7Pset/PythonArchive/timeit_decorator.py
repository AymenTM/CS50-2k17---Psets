
from functools import wraps
from contextlib import contextmanager

# Decorator
def timeit(func):
    """
    Times the execution time of a function and logs it after its
    execution.
    """

    @wraps(func)
    def new_func(*args, **kwargs):

        from time import perf_counter

        t1 = perf_counter()
        result = func(*args, **kwargs)
        t2 = perf_counter()
        print(f"[Finished {func.__name__} in {t2 - t1:.9f}s]")

        return result

    return new_func


# Context Manager
@contextmanager
def timer():
    """
    Times the execution time of the entire with statement block
    and logs it after its excution.
    """

    from time import perf_counter

    try:
        t1 = perf_counter()
        yield
    except Exception:
        pass
    finally:
        t2 = perf_counter()
        print(f"[Finished block in {t2 - t1:.9f}s]")



# Testing --------------------------------------------

# @timeit
# def say(phrase):
#     print(phrase)

# print('-----------------------------\nTimit Decorator:')
# say('\nhello world')
# say('\nhey this is just me checking in about an appointement')
# say('\nsup bro hows life going im just checking up on you')
# say('\na')
# print()

# print('-----------------------------\nTimer Context Manager:\n')
# with timer():
#     print('hello world')
#     print('hey this is just me checking in about an appointement')
#     print('sup bro hows life going im just checking up on you')
#     print('a\n')

