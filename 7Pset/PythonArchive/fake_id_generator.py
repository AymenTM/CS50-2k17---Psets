
import random
import csv
from sys import argv

first_names = ['Aron', 'Andy', 'Arnold', 'Abby', 'Arthur', 'Alice', 'Ben', 'Betty', 'Bob', 'Beth', 'Bryce', 'Britny', 'Christoper', 'Catherine', 'Derek', 'Diana', 'Eric', 'Elisabeth', 'Fred', 'Fiona', 'Greg', 'Gabby', 'Harris', 'Hana', 'Ivan', 'Ina', 'Jack', 'Jasmine', 'Kyle', 'Kim', 'Louis', 'Lucy', 'Martin', 'Marry', 'Nolan', 'Nancy', 'Opera', 'Oliver', 'Patrick', 'Penny', 'Reagan', 'Rachel', 'Samantha', 'Steve', 'Tom', 'Tabia', 'Uler', 'Ulyana', 'Valerie', 'Vick', 'Wenston', 'Wendy', 'Xavier', 'Xandra', 'Zamayla', 'Zach', 'Ryan', 'Percy', 'Casey', 'Erika', 'Domingo', 'Douglas', 'Sandra', 'Cedric', 'Lawrence', 'Melissa', 'Alan', 'Zachary', 'Barry', 'Clint', 'Monica', 'Homer', 'Melba', 'Mary', 'Eduardo', 'Al', 'Snyder', 'Ellis', 'Chapman', 'Hubbard', 'Armstrong', 'Mack', 'Figueroa', 'Reese', 'White', 'Conner', 'Haskell', 'Lin', 'Solomon', 'Shanks', 'Cranford', 'Kincaid', 'Barger', 'Mcfadden', 'Franz', 'Hendrickson', 'Raven', 'Treena', 'Liz', 'Carolin', 'Avril', 'Amal', 'Lucina', 'Myrtice', 'Shanelle', 'Ela']
last_names = ['Reed', 'Todd', 'Phelps', 'Arroyo', 'James', 'Nash', 'Bennett', 'Hays', 'Kane', 'Thornton', 'Pacheco', 'Hobbs', 'Choi', 'David', 'Levy', 'Walker', 'Barajas', 'Petersen', 'Reyes', 'Kramer', 'Pratt', 'Bell', 'Crane', 'Villarreal', 'Macias', 'Fritz', 'Arellano', 'Walsh', 'Gallegos', 'Tanner', 'Berg', 'Freeman', 'Hess', 'Lowery', 'Vaughan', 'Russo', 'Cummings', 'Gregory', 'Fischer', 'Holden', 'Zavala', 'Howard', 'Li', 'Singleton', 'York', 'Taylor', 'James', 'Goodman', 'Lang', 'Dean', 'Meyers', 'Frye', 'Duncan', 'Costa', 'Trevino', 'Wang', 'Bryant', 'Turner', 'Ramirez', 'Porter', 'Payne', 'Huff', 'Woods', 'Garrett', 'Hodges', 'Brooks', 'Cole', 'Mann', 'Fletcher', 'Pearson', 'Hawkins', 'Mckenzie', 'Sutton', 'Owens', 'Pierce', 'Rowe', 'Lance', 'Mona', 'Scott', 'Jorge', 'Forrest', 'Marian', 'Candice', 'Tricia', 'Allan', 'Dexter']
state_names = ['AL', 'AK', 'AZ', 'AR', 'CA', 'CO', 'CT', 'DE', 'FL', 'GA', 'HI', 'ID', 'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'MD', 'MA', 'MI', 'MN', 'MS', 'MO', 'MT', 'NE', 'NV', 'NH', 'NJ', 'NM', 'NY', 'NC', 'ND', 'OH', 'OK', 'OR', 'PA', 'RI', 'SC', 'SD', 'TN', 'TX', 'UT', 'VT', 'VA', 'WA', 'WV', 'WI', 'WY', 'AS', 'DC', 'FM', 'GU', 'MH', 'MP', 'PW', 'PR', 'VI']
street_names = ['Park Place', '4th Street', '5th Street', 'Fawn Lane', 'Race Street', 'George Street', 'Crescent Street', '10th Street', 'Broad Street West', 'Buttonwood Drive', 'Hudson Street', 'Bridge Street', 'Hillside Drive', 'Cedar Court', 'Williams Street', 'Warren Avenue', 'Cobblestone Court', 'Hill Street', 'Route 29', 'Garfield Avenue', '7th Avenue', 'Clay Street', '10th Street', 'Summit Street', 'Route 44', 'South Street', 'Morris Street', 'B Street', 'Elm Street', 'Euclid Avenue', 'Strawberry Lane', 'Belmont Avenue', 'Mill Road', '6th Avenue', 'Green Street', 'Cedar Lane', 'Beechwood Drive', 'Harrison Street', 'Catherine Street', 'Maple Avenue', 'Franklin Court', 'Orange Street', 'Cherry Lane', 'Fulton Street', 'Briarwood Drive', 'College Avenue', '8th Street', 'Creek Road', 'Howard Street', 'Virginia Avenue', 'Grove Street', 'Cypress Court', 'Route 20', '5th Street East', 'Spruce Street', 'Forest Drive', 'Clinton Street', 'Clay Street', 'Country Club Drive', 'Andover Court', 'East Street', 'Street Road', 'Parker Street', '6th Street West', 'Front Street North', 'Cottage Street', 'Ivy Court', 'Buttonwood Drive', 'Willow Drive', 'Fawn Lane', 'Laurel Drive', 'Canterbury Road', 'Orange Street', 'Route 44', 'Carriage Drive', 'Route 29', 'Warren Street', 'Beechwood Drive', 'Lafayette Avenue', 'Valley View Road']
city_names = ['Arlington', 'Miami', 'Pittsburgh', 'Oakland', 'Reno', 'Modesto', 'Washington', 'Chesapeake', 'Stockton', 'New Orleans', 'Denver', 'San Antonio', 'Lexington - Fayette', 'Portland', 'Boston', 'Raleigh', 'Sacramento', 'Long Beach', 'Hialeah', 'Lubbock', 'St. Louis', 'Aurora', 'Orlando', 'Milwaukee', 'Chicago', 'Riverside', 'Scottsdale', 'Chandler', 'Minneapolis', 'Cleveland', 'Madison', 'Orlando', 'Anchorage', 'San Diego', 'Scottsdale', 'Toledo', 'St. Paul', 'Boise', 'Oakland', 'Huntington', 'St. Louis', 'Baltimore', 'Tulsa', 'Kansas City', 'New Orleans', 'Henderson', 'Anaheim', 'Stockton', 'Boston', 'Minneapolis', 'Jersey City', 'Fort Worth', 'Glendale', 'Rochester', 'Austin', 'Cleveland', 'Arlington', 'San Bernardino', 'San Antonio', 'Garland', 'Scottsdale', 'Cincinnati', 'Buffalo', 'Tulsa', 'Mesa', 'Lexington-Fayette', 'Detroit', 'Miami', 'Hialeah', 'St. Louis', 'Modesto', 'Glendale', 'Wichita', 'Omaha', 'Arlington', 'Jacksonville', 'Charlotte', 'San Diego', 'Atlanta', 'Riverside', 'Chesapeake', 'Los Angeles', 'Austin', 'Arlington', 'Norfolk', 'Chandler', 'Akron', 'Portland', 'Santa Ana']


def get_fake_id(amount=1):

    # Creates 'amount' identities. Stores them in a list of lists. Returns the list of lists.

    identities = []
    for i in range(1, amount + 1):

        first = random.choice(first_names)
        last = random.choice(last_names)

        phone = f'{random.randint(100, 999)}-555-{random.randint(1000, 9999)}'

        state = random.choice(state_names)
        city = random.choice(city_names)
        street = random.choice(street_names)
        st_num = random.randint(100, 999)
        zip_code = random.randint(10000, 99999)

        address = f'{st_num} {street}, {city} {state} {zip_code}'

        email = f'{first.lower()}_{last.lower()}@bogusemail.com'

        # identities.append(f'ID #{i}:\n{first} {last}\n{phone}\n{address}\n{email}')
        identities.append([f'{i}', f'{first}', f'{last}', f'{phone}', f'{address}', f'{email}'])

    return(identities)


def main():

    # Generates fake IDs and writes them to a CSV file (seperated by tabulations).

    if len(argv) != 2:
        amount = int(input('Number of IDs to be generated: '))
    else:
        amount = int(argv[1])
    identities = get_fake_id(amount)
    with open('fake_people.csv', 'w') as wr_csv_file:

        csv_writer = csv.writer(wr_csv_file, delimiter='\t')

        csv_writer.writerow(['id', 'firstname', 'lastname', 'phone', 'address', 'email'])

        for ID in identities:
            csv_writer.writerow(ID)


if __name__ == '__main__':
    main()
