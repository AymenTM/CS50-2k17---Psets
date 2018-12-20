
import csv

    sequence = [
        ['James', '23yrs', 'Canadian'],
        ['Arnold', '21yrs', 'French'],
        ['Kevin', '25yrs', 'British'],
        ['Brian', '19yrs', 'Scotish'],
        ['Smith', '22yrs', 'Spanish'],
    ]


with open('copy.csv', 'w') as wr_csv_file:

    csv_writer = csv.writer(wr_csv_file, delimiter='\t')

    for row in sequence:
        csv_writer.writerow(row)
