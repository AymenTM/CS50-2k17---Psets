# Testing stuff

def main():

	students_list = []

	# Get Info of 3 students
	for i in range(3):
		print()

		# Get Student Info
		name = str(input('Name: '))
		age = str(input('Age: '))
		nationality = str(input('Nationality: '))

		# Append Student Object to List (this is a dict variable named 'student')
		student = {'Name': name, 'Age': age, 'Nationality': nationality}
		students_list.append(student)

	# Print Info for every Student in the List
	print()
	print_list_of_dicts(students_list)


def print_list_of_dicts(list):
	for elem in list:
		print(f'——————————————\n==> Element #{list.index(elem) + 1} <==\n')
		for key in elem:
			print(f'{key} : {elem.get(key)}')
	print('——————————————')


if __name__ == "__main__":
	main()
