
class Employee:

    num_employees = 0
    raise_amount = 1.04

    def __init__(self, first, last, pay):

        self._first = first
        self._last = last
        self._pay = pay

        Employee.num_employees += 1

    @property  # getter
    def email(self):
        return f'{self._first.lower()}.{self._last.lower()}@email.com'

    @property  # getter
    def fullname(self):
        return f'{self._first} {self._last}'

    @fullname.setter
    def fullname(self, fullname):
        self._first, self._last = fullname.split(' ')

    @fullname.deleter
    def fullname(self):
        self._first = None
        self._last = None

    def apply_raise(self):
        self._pay = int(self._pay * self.raise_amount)

    @classmethod
    def from_string(cls, string):
        first, last, pay = string.split('-')
        return cls(first, last, pay)

    @staticmethod
    def is_workday(day):
        if day.weekday() == 5 or day.weekday() == 6:
            return False
        return True

    def __repr__(self):
        return (f'Employee({self._first}, {self._last}, {self._pay})')

    def __str__(self):
        return (f'{self._first} {self._last} - {self.email} - ${self._pay}/yr')

    def __add__(self, other):
        return (self._pay + other._pay)

    def __len__(self):
        return len(self.fullname)


class Developper(Employee):

    raise_amount = 1.10

    def __init__(self, first, last, pay, prog_lang):

        Employee.__init__(self, first, last, pay)
        self.prog_lang = prog_lang


class Manager(Employee):

    raise_amount = 1.10

    def __init__(self, first, last, pay, employees_managed=None):

        super().__init__(first, last, pay)
        if employees_managed == None:
            self.employees_managed = []
        else:
            self.employees_managed = employees_managed

    def add_emp(self, emp):
        if emp not in self.employees_managed:
            self.employees_managed.append(emp)

    def remove_emp(self, emp):
        if emp in self.employees_managed:
            self.employees_managed.remove(emp)

    def print_emps(self, ):
        for emp in self.employees_managed:
            print(f'--> {emp.fullname()}')
