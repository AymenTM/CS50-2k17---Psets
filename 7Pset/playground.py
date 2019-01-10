
# UNIT TESTING w/ the 'unittest' Module


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

"""File called: myOperations. It contains functions we
want to test"""


# def add(x, y):
#     """Add Function"""
#     return x + y


# def sub(x, y):
#     """Subtract Function"""
#     return x - y


# def mul(x, y):
#     """Multiply Function"""
#     return x * y


# def div(x, y):
#     """Divide Function"""
#     if y == 0:
#     	raise ValueError(" Can not divde by zero!")
#     return x / y


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


"""Test File (seperate from 'myOperations' the file containing
the functions)"""


# import unittest
# import myOperations


# class TestCalc(unittest.TestCase):

#     def test_add(self):
#         self.assertEqual(myOperations.add(10, 5), 15)
#         self.assertEqual(myOperations.add(4, 5), 9)
#         self.assertEqual(myOperations.add(-1, 1), 0)
#         self.assertEqual(myOperations.add(-1, -1), -2)

#     def test_sub(self):
#         self.assertEqual(myOperations.sub(10, 5), 5)
#         self.assertEqual(myOperations.sub(4, 5), -1)
#         self.assertEqual(myOperations.sub(-1, 1), -2)
#         self.assertEqual(myOperations.sub(-1, -1), 0)

#     def test_mul(self):
#         self.assertEqual(myOperations.mul(10, 5), 50)
#         self.assertEqual(myOperations.mul(4, 5), 20)
#         self.assertEqual(myOperations.mul(-1, 1), -1)
#         self.assertEqual(myOperations.mul(-1, -1), 1)

#     def test_div(self):
#         self.assertEqual(myOperations.div(10, 5), 2)		# Tests for output
#         self.assertEqual(myOperations.div(4, 5), 0.8)
#         self.assertEqual(myOperations.div(-1, 1), -1)
#         self.assertEqual(myOperations.div(-1, -1), 1)
#         self.assertEqual(myOperations.div(5, 2), 2.5)

#         with self.assertRaises(ValueError):					# Tests for Execption
#             myOperations.div(10, 0)


# if __name__ == '__main__':
#     unittest.main()


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# Employee Class Unit Test


import unittest
from employeeClass import Employee


class TestEmployeeClass(unittest.TestCase):

    def setUp(self):
        self.emp_1 = Employee('Sam', 'Telji', 50000)
        self.emp_2 = Employee('Xavier', 'Hubert', 60000)

    def tearDown(self):
        pass

    def test_email(self):

        self.assertEqual(self.emp_1.email, 'sam.telji@email.com')
        self.assertEqual(self.emp_2.email, 'xavier.hubert@email.com')

        self.emp_1._first = 'John'
        self.emp_2._last = 'Bruno'

        self.assertEqual(self.emp_1.email, 'john.telji@email.com')
        self.assertEqual(self.emp_2.email, 'xavier.bruno@email.com')


    def test_fullname(self):

        self.assertEqual(self.emp_1.fullname, 'Sam Telji')
        self.assertEqual(self.emp_2.fullname, 'Xavier Hubert')

        self.emp_1._first = 'John'
        self.emp_2._last = 'Bruno'

        self.assertEqual(self.emp_1.fullname, 'John Telji')
        self.assertEqual(self.emp_2.fullname, 'Xavier Bruno')


    def test_raise(self):

        self.assertEqual(self.emp_1._pay, 50000)
        self.assertEqual(self.emp_2._pay, 60000)

        self.emp_1.apply_raise()
        self.emp_2.apply_raise()

        self.assertEqual(self.emp_1._pay, 52000)
        self.assertEqual(self.emp_2._pay, 62400)


if __name__ == '__main__':
    unittest.main()

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
