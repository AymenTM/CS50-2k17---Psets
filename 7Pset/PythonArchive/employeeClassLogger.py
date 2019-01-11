
import logging

# Setting Up Logger — — — — — — — — — — — — — — — — — — — — — — — — — — —

formatter = logging.Formatter(
    '%(levelname)s:%(name)s: %(filename)s, line %(lineno)d:\t%(message)s')

file_handler = logging.FileHandler('employee.log', mode='a')
file_handler.setFormatter(formatter)
file_handler.setLevel(logging.INFO)

logger = logging.getLogger(name=__name__)
logger.addHandler(file_handler)
logger.setLevel(logging.DEBUG)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


class Employee:

    num_employees = 0
    raise_amount = 1.04

    def __init__(self, first, last, pay):

        self._first = first
        self._last = last
        self._pay = pay

        logger.info(f'Created an employee —> {first} {last}')

    @property  # getter
    def email(self):
        return f'{self._first.lower()}.{self._last.lower()}@email.com'

    @property  # getter
    def fullname(self):
        return f'{self._first} {self._last}'


emp_1 = Employee('Jack', 'Robenson', 50000)
emp_2 = Employee('John', 'Hubert', 60000)
emp_3 = Employee('Mick', 'Lisker', 70000)
