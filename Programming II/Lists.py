x = [1,2,3,4,5,6,7,8,9,0]
x.append(3) # adding 3 to the endo of the list
x.append(4) # adding 4 to the end of the list
x.append(5) # adding 5 to the end of the list
print(x[-1]) # this will print the last element of the list which is 5
print(x[2:5]) # this will print the elements from index 2 to index 5 which are 3,4,5
#x[14] this reaches out of higher bounds and will cause an error
#x[-14] this also reaches out of lower bounds and will cause an error
for element in x:
    print(element)
