a = 1
while (a < 5 and a > 0):
    print("Enter the number corisponding to the operation you want to perform:")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Exit")
    a = int(input("Enter your choice: "))

    if a == 1:
        print("you chose addition")
        x = float(input("Enter first number: "))
        y = float(input("Enter second number: "))
        print("Result:", x + y)
    elif a == 2:
        print("you chose subtraction")
        x = float(input("Enter first number: "))
        y = float(input("Enter second number: "))
        print("Result:", x - y)
    elif a == 3:
        print("you chose multiplication")
        x = float(input("Enter first number: "))
        y = float(input("Enter second number: "))
        print("Result:", x * y)
    elif a == 4:
        print("you chose division")
        x = float(input("Enter first number: "))
        y = float(input("Enter second number: "))
        if y != 0:
            print("Result:", x / y)
        else:
            print("Error: Division by zero is not allowed.")
    elif a == 5:
        print("Exiting the calculator. Goodbye!")

    
