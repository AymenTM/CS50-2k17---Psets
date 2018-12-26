
    from functools import wraps

    def logger(func):

        import logging
        logging.basicConfig(filename=f'{func.__name__}.log', level=logging.INFO)

        @wraps(func)
        def wrapper(*args, **kwargs):

            logging.info(f'Ran with args: {args}, and kwargs: {kwargs}')
            return func(*args, **kwargs)

        return wrapper

    @logger
    def greet_user(greeting, username):
        print(f'{greeting}, {username}')


greet_user('Hello', 'Tim')
greet_user('Hi', 'John')
greet_user('Welcome back', 'Louis')
