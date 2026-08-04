# School
This is all of the coding assignments we have done for Mr. Webster's class aswell as some personal projects that i make when i am bored. If you are looking at my code only the .cpp, .py, and .html files in programming, programming II, Comp Sci., and AP Comp. Sci. folders are relevant.


print("Standard form for equation ax^2+bx+c ( ACCOUNT FOR THE SIGN )")

a=int(input("input a value for a: "))
b=int(input("input a value for b: "))
c=int(input("input a value for c: "))

z=0
y=0

t=0

while(t==0):
    for n in range(a * c + 1):
        print("n=",n)
        for m in range(a*c + 1):
            print("m=",m)
            z=n*m
            y=n+m
            if z == a*c and y == b:
                t=1
        if t == 1:
            break

number_z = z
factors_z = []

for i in range(1, number_z + 1):
    print("i=",i)
    if number_z % i == 0:
        factors_z.append(i)

number_a = z
factors_a = []

for i in range(1, number_a + 1):
    print("i=",i)
    if number_a % i == 0:
        factors_a.append(i)


number_y = z
factors_y = []

for i in range(1, number_y + 1):
    print("i=",i)
    if number_y % i == 0:
        factors_y.append(i)

number_c = z
factors_c = []

for i in range(1, number_c + 1):
    print("i=",i)
    if number_c % i == 0:
        factors_c.append(i)

L1=[]
L2=[]

q1=0
q2=0
q3=0
q4=0

if len(factors_a) > len(factors_z):
    L1=factors_a
    L2=factors_z
else:
    L1=factors_z
    L2=factors_a

for i in range(len(L1)):
    print("i=",i)
    for j in range(len(L2)):
        print("j=",j)
        if L1[i] == L2[j]:
            q1=L1[i]


if len(factors_a) > len(factors_y):
    L1=factors_a
    L2=factors_y
else:
    L1=factors_y
    L2=factors_a

for i in range(len(L1)):
    print("i=",i)
    for j in range(len(L2)):
        print("j=",j)
        if L1[i] == L2[j]:
            q2=L1[i]



if len(factors_y) > len(factors_c):
    L1=factors_y
    L2=factors_c
else:
    L1=factors_c
    L2=factors_y

for i in range(len(L1)):
    print("i=",i)
    for j in range(len(L2)):
        print("j=",j)
        if L1[i] == L2[j]:
            q3=L1[i]


if len(factors_z) > len(factors_c):
    L1=factors_z
    L2=factors_c
else:
    L1=factors_c
    L2=factors_z

for i in range(len(L1)):
    print("i=",i)
    for j in range(len(L2)):
        print("j=",j)
        if L1[i] == L2[j]:
            q4=L1[i]


print("The factors are: ", "(",q1,"x+",q2,")(",q3,"x+",q4,")")