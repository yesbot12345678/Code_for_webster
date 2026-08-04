import math
while(True):
    a=float(input("input a value for A: "))
    b=float(input("input a value for B: "))
    c=float(input("input a value for C: "))

    awnser_positive = (((b-(2*b))+(math.sqrt((b**2)-(4*a*c))))/(2*a))
    awnser_negative = (((b-(2*b))-(math.sqrt((b**2)-(4*a*c))))/(2*a))

    print("answers are: ", awnser_positive," and ", awnser_negative)