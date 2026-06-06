while True:
    number = int(input("Enter a number: "))
    factors = []

    print("Factors of", number, ":")

    for i in range(1, number + 1):
        if number % i == 0:
            factors.append(i)

    for i in range(len(factors)):
        first = factors[i]

  
        for j in range(i + 1, len(factors)):
            second = factors[j]

            if first * second == number:
                 print(first, ":", second)
                    
