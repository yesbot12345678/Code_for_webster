import random
list1 = [ #2D list
    [1,1,1,1,1],
    [1,1,1,1,1],
    [1,1,1,1,1],
    [1,1,1,1,1],
    [1,1,1,1,1]
]

for row in range(len(list1)): #randomizer
    for col in range(len(list1[row])):
        list1[row][col]=random.randint(1,100)
   
for row in range(len(list1)): #base list output
         print(list1[row])

for row in range(len(list1)): # sort list
        list1[row].sort()

print() #spacer

for row in range(len(list1)): #sorted list output
     print(list1[row])


    