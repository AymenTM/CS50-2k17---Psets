# * * * * * * * * * * * * * * * #
# ============================= #
#        CS50 - crack.py        #
# ============================= #
# * * * * * * * * * * * * * * * #

from crypt import crypt
from sys import argv

alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
total_chars = 0


def main():
    if len(argv) is 2:
        if crack(argv[1]):
            return (0)
        else:
            print('Uncrackable!')
            return (1)
    else:
        print('Usage: python crack.py hash')
        return (1)


# Tries every possible permutation for the current index.
def crack_furthur(hsh, passwd, salt, index):
    found = 0
    for c in alphabet:
        passwd[index] = c
        if total_chars > index:
            found = crack_furthur(hsh, passwd, salt, index + 1)
            if found:
                return (1)
        elif crypt(''.join(passwd), salt) == hsh:
            print(''.join(passwd))
            return (1)
    return (0)


# Tries every possible permutation for the index 0 when
# the password is at a length of 1, 2, 3, 4 & 5.
def crack(hsh):
    global total_chars
    salt = hsh[:2]
    passwd = ['', '', '', '', '']
    found = 0
    while total_chars < 5:
        for c in alphabet:
            passwd[0] = c
            if total_chars > 0:
                found = crack_furthur(hsh, passwd, salt, 1)
                if found:
                    return (1)
            elif crypt(''.join(passwd), salt) == hsh:
                print(''.join(passwd))
                return (1)
        total_chars += 1
    return (0)


if __name__ == '__main__':
    main()
