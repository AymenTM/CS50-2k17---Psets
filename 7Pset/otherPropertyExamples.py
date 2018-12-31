# Some Class Examples for the @property Decorator Function


class Teacher:

    def __init__(self, name, subject):

        self._name = name
        self._subject = subject

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value

    @name.deleter
    def name(self):
        self._name = None


class Celsius:

    def __init__(self, temperature=0):
        self.temperature = temperature

    def get_temperature(self):
        return self._temperature

    def set_temperature(self, value):
        if value < -273:
            raise ValueError("Temperature below -273 is not possible")
        self._temperature = value

    def del_temperature(self):
        self._temperature = None

    temperature = property(get_temperature, set_temperature, del_temperature)
