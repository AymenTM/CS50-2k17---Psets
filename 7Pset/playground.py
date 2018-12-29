
from collections import namedtuple

Color = namedtuple('RGB', ['red', 'green', 'blue'])

orange = Color(255, 153, 81)

print(orange)

print(orange.red)
print(orange.green)
print(orange.blue)
