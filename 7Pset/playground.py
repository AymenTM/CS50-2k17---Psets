
from contextlib import contextmanager

@contextmanager
def redirect_stdout(destination):
    """Temporarily redirect standard output to a file."""

    import sys

    old_stdout = sys.stdout
    sys.stdout = destination
    try:
        yield
    finally:
        sys.stdout = old_stdout


with open('playground.js', 'w') as f:
    with redirect_stdout(f):
        help(pow)
