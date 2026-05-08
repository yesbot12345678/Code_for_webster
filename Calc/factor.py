n_factor = input("Enter a number to find its factors: ")
store = []
print("The factors of", n_factor, "are:")
for i in range(1, int(n_factor) + 1):
    if int(n_factor) % i == 0:
        store.append(i)

for i in range(len(store)):
    if store[i] != store[len(store) - 1]:
        for j in range(i + 1, len(store)):
            if store[i] * store[j] == int(n_factor):
                print(f"{store[i]} : {store[j]}")