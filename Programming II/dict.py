# a dictionary is a collection of key-value pairs. Each key is unique and maps to a value. in Dictionaries you can change their contents after they are created.
# a key is a unique identifier for a value in a dictionary.
# a value is the data associated with a key in a dictionary.

# 1
x = "a"
dict1 = {"a": 1, "b": 2, "c": 3, "d": 4}

# 2
print("2.)", dict1)

# 3
print("3.)", dict1[x])

# 4
print("4.)", dict1.get("e", "Not found"))

# 5
dict1["e"] = 5
print("5.)", dict1)

dict1["a"] = 0
print("5.)", dict1)

# 6
del dict1["a"]
print("6.)", dict1)

# 7
dict1.pop("b")
print("7.)", dict1)

# 8
print("8.)", len(dict1))

for key in dict1.keys():
    print("8.)", key)

for value in dict1.values():
    print("8.)", value)

for key, value in dict1.items():
    print("8.)", f"{key}: {value}")

