select =(int(input("1. exit, 2. Enter Temp")))
while select != 1:
    if select == 2:
        t = input("Enter the temp")
        temp = int(t)
    if temp > 80 and temp < 100:
        print("its too hot!")
    elif temp < 65 and temp > 80:
        print("its just right")
    elif temp < 46 and temp > 65:
        print("its getting better")
    elif temp < 45 and temp > 0:
        print("its too cold")
    else:
        print("Invalid temp")
    select =(int(input("1. exit, 2. Enter Temp")))