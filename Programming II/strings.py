print(str("this is a string")) # this will print the string "this is a string"
x = str("this is another string")
print(x) # this will print the string "this is another string"
print(len(x)) # this will print the length of the string which is 24
print(x.split()[1]) # second word of the string is "is"
print(x.find("another")) # this will print the index of the first occurrence of the word "another" which is 
print(x.upper()) # this will print the string in uppercase "THIS IS ANOTHER STRING"
print(x.lower()) # this will print the string in lowercase "this is another string"
print(x.count("is")) # this will print the number of occurrences of the word "is"
print(x+x) # this will concatenate the string with itself and print "this is another stringthis is another string"
print(f"this is a string, {x}")