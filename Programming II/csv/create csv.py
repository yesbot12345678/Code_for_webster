import csv

names = {'first_name': 'Baked', 'last_name': 'Beans', 'age': 100}

with open('Programming II/csv/names.csv', 'w', newline='') as csvfile:
    fieldnames = names.keys()
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerow(names)

