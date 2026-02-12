a = 1
while (a < 5 and a > 0):
    print("Enter the number corisponding to the operation you want to perform:")
    print("1. Area of Square")
    print("2. Area of Circle")
    print("3. Celcius to Fahrenheit")
    print("4. Fahrenheit to Celcius")
    print("5. Exit")
    a = int(input("Enter your choice: "))

    if a == 1:
        print("you chose Area of Square")
        x = float(input("Enter first number: "))
        y = float(input("Enter second number: "))
        print("Result:", x * y)
    elif a == 2:
        print("you chose Area of Circle")
        x = float(input("Enter the raidius number: "))
        print("Result:", x * x * float(3.14))
    elif a == 3:
        print("you chose Celcius to Fahrenheit")
        x = float(input("Enter celcius number: "))
        print("Result:", (x * float((9/5)) + float(32)))
    elif a == 4:
        print("you chose Fahrenheit to Celcius")
        x = float(input("Enter fahrenheit number: "))
        print("Result:", (float((x - 32) / (9/5))))
    elif a == 5:
        print("Exiting the calculator. Goodbye!")

    
