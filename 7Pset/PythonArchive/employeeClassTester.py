

import unittest
from employeeClass import Employee


class TestEmployeeClass(unittest.TestCase):

    # Before any Test
    @classmethod
    def setUpClass(cls):
        print('Tests will start shortly.')

    # After all Tests
    @classmethod
    def tearDownClass(cls):
        print('\nAll tests have been executed.')

    # Before every single Test
    def setUp(self):
        self.emp_1 = Employee('Sam', 'Telji', 50000)
        self.emp_2 = Employee('Xavier', 'Hubert', 60000)

    # After every Single Test
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


