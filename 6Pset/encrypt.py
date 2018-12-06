
# To test crack.c

from crypt import crypt
from sys import argv

print(crypt(argv[1], argv[2]))
