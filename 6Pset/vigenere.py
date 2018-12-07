# * * * * * * * * * * * * * * * * * #
# ================================= #
#           Vigenère Cipher         #
# ================================= #
# * * * * * * * * * * * * * * * * * #

from sys import argv


def main():
    # Make sure a key was passed and that it is strictly alphabetical
    if len(argv) == 2 and argv[1].isalpha():
        msg = str(input("plaintext: "))
        cipher = vigenere_cipher(msg, argv[1])
        print(f'ciphertext: {cipher}')
    else:
        print("Usage: python vigenere.py k")


# Cipher's text Vigenère style
def vigenere_cipher(msg, key):
    cipher = ""
    mlen = len(msg)
    klen = len(key)
    i = 0
    while i < mlen:
        j = 0
        while i < mlen and j < klen:
            if (msg[i].islower() and key[j].islower()):
                cipher += chr(ord('a') +
                              ((ord(msg[i]) - ord('a')) + (ord(key[j]) - ord('a'))) % 26)
            elif (msg[i].isupper() and key[j].isupper()):
                cipher += chr(ord('A') +
                              ((ord(msg[i]) - ord('A')) + (ord(key[j]) - ord('A'))) % 26)
            elif (msg[i].islower() and key[j].isupper()):
                cipher += chr(ord('a') +
                              ((ord(msg[i]) - ord('a')) + (ord(key[j]) - ord('A'))) % 26)
            elif (msg[i].isupper() and key[j].islower()):
                cipher += chr(ord('A') +
                              ((ord(msg[i]) - ord('A')) + (ord(key[j]) - ord('a'))) % 26)
            else:
                cipher += msg[i]
                i += 1
                continue
            i += 1
            j += 1
    return (cipher)


if __name__ == '__main__':
    main()
