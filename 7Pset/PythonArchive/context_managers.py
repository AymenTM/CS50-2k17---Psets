
# Collection of the Context Managers I've made.

from contextlib import contextmanager


@contextmanager
def ignored(*exceptions):
    """
    Ignore exceptions for the code in the block.
    """

    try:
        yield
    except exceptions:
        pass


@contextmanager
def redirect_stdout(fileobj):
    """
    Temporarily redirect standard output to a file.
    """

    import sys

    old_stdout = sys.stdout
    sys.stdout = fileobj
    try:
        yield
    finally:
        sys.stdout = old_stdout


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
