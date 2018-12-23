

# try:
#     f = open('t.txts')

# except FileNotFoundError:
#     print('File dun Exist buddy.')

# except SyntaxError:
#     print('Big Noob.')

# except Exception:
#     print('Can\'t Code ?')

# else:
#     print(f.read(), end='')
#     f.close()

# finally:
#     print('Over.')


def get_int(prompt_msg):

    while True:
        try:
            x = int(input(prompt_msg))
            return (x)
        except ValueError:
            pass


def get_string(prompt_msg):

    while True:
        try:
            x = str(input(prompt_msg))
            return (x)
        except Exception:
            pass

				1 / try:
							# runs the code within this try clause

				2 / except (RuntimeError, TypeError, ...) as e:
							# if the code in the try clause has an
							# error, it will come here and run the
							# code within the except clause

				2 / else:
							# if no errors were raised in the try
							# clause, it will run what is in this
							# else clause

				3 / finally:
							# finally, regardless of what happens
							# the finally clause is run at the
							# very end of the try statement







		    while True:
		        try:
		            x = int(input('Number: '))
		        except ValueError:
		            pass
		        else:
		        	break









