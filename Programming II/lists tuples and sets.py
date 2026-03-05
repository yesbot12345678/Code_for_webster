x = [1,2]
x.append(3)
print(x[0:3])
x.insert(0,0)
print(x)
x.extend([4,5,6,7,8,9,0])
print(x)
x.reverse() # this will reverse the order of the list
print(x)
x.sort(reverse=True) # this will sort the list in reverse order
print(x)
x.sort()
print(x)
print(min(x))
print(max(x))
y = (1,2,3,4,5) # this is a tuple and it cannot be changed once it is created
print(y)
z = {1,2,3,4,5} # this is a set and it does not allow duplicates
print(z)