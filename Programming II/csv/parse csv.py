import csv
names = []
with open('Programming II/csv/names.csv', 'r', newline='') as csvfile:
    csvreader = csv.reader(csvfile)
    for line in csvreader:
        names.append(line)
    with open('Programming II/csv/new_names.csv', 'w', newline='') as new_csvfile:
        csvwriter = csv.writer(new_csvfile, delimiter='\t')
        for line in names:
            csvwriter.writerow([line[0]])

with open('Programming II/csv/new_names.csv', 'r', newline='') as csvfile:
    csvreader = csv.DictReader(csvfile)
    for line in csvreader:
        print(line['first_name'])