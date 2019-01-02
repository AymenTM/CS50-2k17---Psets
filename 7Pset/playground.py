
# Context Managers


class File:

    def __init__(self, filename, mode):

        self.filename = filename
        self.mode = mode

    def __enter__(self):

        self.fd = open(self.filename, self.mode)
        return self.fd

    def __exit__(self, exc_type, exc_val, traceback):

        self.fd.close()
        return True


from contextlib import contextmanager


@contextmanager
def open_file(filename, mode):

    try:
        fd = open(filename, mode)
        yield fd

    finally:
        fd.close()


with open_file('decorators.py', 'r') as fd:

    print(fd.read())


# with something_that_returns_a_context_manager as my_resource:

    #		    do something with my resource
    #			...
