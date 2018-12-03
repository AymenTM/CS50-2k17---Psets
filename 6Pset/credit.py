# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * #
# ============================================================= #
#           Credit Card Checksum using Luhn's Algorithm         #
# ============================================================= #
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * #

def main():
	number = str(input("Number: "))
	card_len = len(number)
	card_type = find_type(number, card_len)
	if card_type != "INVALID" and valid_card(number, card_len - 1):
		print(card_type)
	else:
		print("INVALID")

# checks the characteristics of the number to determine type #
def find_type(number, length):
	if length == 15 and number[0] == '3':
		if number[1] == '4' or number[1] == '7':
			return ("AMEX")
	elif length == 16 and number[0] == '5':
		if 	(number[1] == '1' or number[1] == '2' or
			 number[1] == '3' or number[1] == '4' or
			 number[1] == '5'):
			return ("MASTERCARD")
	elif length == 13 or length == 16 and number[0] == '4':
			return ("VISA")
	else:
		return ("INVALID")

# Luhn's algorithm checksum #
def valid_card(number, length):
	sum1 = 0
	sum2 = 0
	while length >= 0:
		sum1 += int(number[length])
		length -= 1
		temp = int(number[length]) * 2
		if length >= 0:
			while temp > 0:
				sum2 += temp % 10
				temp //= 10
			length -= 1
	sum1 += sum2
	if (sum1 % 10 == 0):
		return (1)
	return (0)

if __name__ == '__main__':
	main()
