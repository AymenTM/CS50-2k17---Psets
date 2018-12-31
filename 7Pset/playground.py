
class Employee:

    num_employees = 0
    raise_amount = 1.04

    def __init__(self, first, last, pay):

        self.first = first
        self.last = last
        self.pay = pay
        self.email = f'{first.lower()}.{last.lower()}@company.com'

        Employee.num_employees += 1

    def fullname(self):
        return f'{self.first} {self.last}'

    def apply_raise(self):
        self.pay = int(self.pay * self.raise_amount)

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
        return (f'Employee({self.first}, {self.last}, {self.pay})')

    def __str__(self):
        return (f'{self.first} {self.last} - {self.email} - ${self.pay}/yr')

    def __add__(self, other):
        return (self.pay + other.pay)

    def __len__(self):
        return len(self.fullname())


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


emp_1 = Employee('Steve', 'Jobs', 65000)
dev_1 = Developper('Corey', 'Schafer', 95000, 'Python')
mgr_1 = Manager('Chris', 'Olinder', 70000, None)
