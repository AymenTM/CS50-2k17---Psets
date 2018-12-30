
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


emp_1 = Employee.from_string('Jack-Dorsee-70000')

print(emp_1.first)
print(emp_1.last)
print(emp_1.pay)
