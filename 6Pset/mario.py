# * * * * * * * * * * * * * * * * * * * * #
# ======================================= #
#          Mario Double Pyramid           #
# ======================================= #
# * * * * * * * * * * * * * * * * * * * * #

def main():
	height = int(input("Height: "))
	while height < 1 or height > 100:
		height = int(input("Height: "))
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

if __name__ == '__main__':
	main()
