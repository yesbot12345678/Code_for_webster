
store_n= []
store_d= []
factors_n = {}
factors_d = {}
store_d = []
common_factors = []

numerator = input("Enter a number for the numurator ( top ): ")
denominator = input("Enter a number for the denominator ( bottom ): ")

for i in range(1, int(numerator) + 1):
    if int(numerator) % i == 0:
        store_n.append(i)


for i in range(1, int(denominator) + 1):
    if int(denominator) % i == 0:
        store_d.append(i)

for i in range(len(store_n)):
    if store_n[i] != store_n[len(store_n) - 1]:
        for j in range(i + 1, len(store_n)):
            if store_n[i] * store_n[j] == int(numerator):
                if store_n[i] not in factors_n:
                    factors_n[store_n[i]] = [store_n[j]]

for i in range(len(store_d)):
    if store_d[i] != store_d[len(store_d) - 1]:
        for j in range(i + 1, len(store_d)):
            if store_d[i] * store_d[j] == int(denominator):
                if store_d[i] not in factors_d:
                    factors_d[store_d[i]] = [store_d[j]]
x = 0
if len(store_n) < len(store_d):
    x = True
else:
    x = False

if x:
    for i in range(len(store_n)):
        if store_n[i] in store_d:
            common_factors.append(store_n[i])
else:
    for i in range(len(store_d)):
        if store_d[i] in store_n:
            common_factors.append(store_d[i])

largest = 0
for i in range(len(common_factors)):
    if common_factors[i] > largest:
        largest = common_factors[i]

numerator = float(numerator) / float(largest)
denominator = float(denominator) / float(largest)
print(f"{numerator}/{denominator}")

