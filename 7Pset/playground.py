
from decorators import logger


@logger
def say_hi():
    print('hi')


say_hi()
