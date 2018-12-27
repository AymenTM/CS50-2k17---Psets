
from functools import wraps


def timer(func):

    import time

    @wraps(func)
    def wrapper(*args, **kwargs):

        t1 = time.perf_counter()
        value = func(*args, **kwargs)
        t2 = time.perf_counter()
        print(f"[Finished '{func.__name__}' in {t2 - t1:.4f}s]")

        return value

    return wrapper


@timer
def do_stuff():
    for c in ['A', 'B', 'C']:
        for i in range(1, 5):
            print(tuple([c, i]), end=', ')
    print()


do_stuff()
