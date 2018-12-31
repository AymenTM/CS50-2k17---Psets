
class Employee:

    def __init__(self, first, last, pay):

        self._first = first
        self._last = last
        self._pay = pay

    @property
    def email(self):
        return f'{self._first.lower()}.{self._last.lower()}@email.com'

    @property
    def fullname(self):
        return f'{self._first} {self._last}'

    @fullname.setter
    def fullname(self, fullname):
        self._first, self._last = fullname.split(' ')

    @fullname.deleter
    def fullname(self):
        self._first = None
        self._last = None

    def __str__(self):
        return f'{self.fullname} - {self.email} - ${self._pay}/yr'


emp_1 = Employee('Dave', 'Stevenson', 70000)

emp_1.fullname = 'Derek Meigner'

print(emp_1)

del emp_1.fullname


# 1 - we create private variables.

# 2 - and only allow access them via the setter, getter and deleter methods

# 3 - and these methods thanks to the property's decorator functions become
#     accessible just like any attribute
