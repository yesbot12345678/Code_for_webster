# function, method, and procedure are reffer to the same thing

def func1(): # function / method / procedure 1 with no parameters
    x = "hi"
    return x
def func2(param): # function / method / procedure 2 with 1 parameter
    return param
def func3(param, param2, param3): # function / method / procedure 3 with 3 parameters
    return param + param2 + param3

# outputting the results of the functions
print(func1()) #inputs no parameters
print(func2("hi")) #inputs 1 parameter
print(func3("hi ", "hello ", "hey")) #inputs 3 parameters
