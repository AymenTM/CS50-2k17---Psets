
# LOGGING w/ the 'logging' Module

import logging
import employee

# Setting Up Logger — — — — — — — — — — — — — — — — — — — — — — — — — — —

formatter = logging.Formatter(
    '%(levelname)s:%(name)s: %(filename)s, line %(lineno)d:\t%(message)s')

file_handler = logging.FileHandler('playground.log', mode='a')
file_handler.setFormatter(formatter)
file_handler.setLevel(logging.DEBUG)

logger = logging.getLogger(name=__name__)
logger.addHandler(file_handler)
logger.setLevel(logging.DEBUG)

# Setting Up StreamHandler — — — — — — — — — — — — — — — — — — — — — — —

stream_handler = logging.StreamHandler(stream=None)
stream_handler.setFormatter(formatter)
stream_handler.setLevel(logging.ERROR)

logger.addHandler(stream_handler)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


def add(x, y):
    """Add Function"""
    return x + y


def sub(x, y):
    """Subtract Function"""
    return x - y


def mul(x, y):
    """Multiply Function"""
    return x * y


def div(x, y):
    """Divide Function"""
    try:
        result = x / y
    except ZeroDivisionError:
        logger.error(f'Tried to divide by zero!', exc_info=0)
    else:
        return result

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

num_1 = 20
num_2 = 0

add_result = add(num_1, num_2)
logger.debug(f'Add: {num_1} + {num_2} = {add_result}')


sub_result = sub(num_1, num_2)
logger.debug(f'Sub: {num_1} - {num_2} = {sub_result}')


mul_result = mul(num_1, num_2)
logger.debug(f'Mul: {num_1} * {num_2} = {mul_result}')


div_result = div(num_1, num_2)
logger.debug(f'Div: {num_1} / {num_2} = {div_result}')

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
