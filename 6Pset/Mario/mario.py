# * * * * * * * * * * * * * * * * * * * * #
# ======================================= #
#          Mario Double Pyramid           #
# ======================================= #
# * * * * * * * * * * * * * * * * * * * * #

from cs50 import get_int

def main():
	height = get_int("Height: ")
	while height < 1 or height > 8:
		height = get_int("Height: ")
	put_pyramid(height)

def put_pyramid(height):
	i = 0
	for y in range(height):
		i += 1
		hashes = height - (height - i)
		spaces = height - hashes
		for m in range(spaces):
			print(" ", end="")
		for n in range(hashes):
			print("#", end="")
		print("  ", end="")
		for n in range(hashes):
			print("#", end="")
		print()
	print("MA nigga 3absoun !")

if __name__ == '__main__':
	main()
