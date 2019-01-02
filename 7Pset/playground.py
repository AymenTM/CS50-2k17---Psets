
# Context Manager Practical Example

from contextlib import contextmanager
import os

@contextmanager
def change_dir(destination):

    try:
        cwd = os.getcwd()
        os.chdir(destination)
        yield

    finally:
        os.chdir(cwd)

        with change_dir('Sample-Dir-One'):

            print(os.listdir())
#	 		    ...
