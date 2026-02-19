import random
l=0 
while l==0:
    Com = random.randint(1,4) #chooses a rand num from 1 to 3
    Player = str(input("enter rock, paper, or scissors (or leave to exit): "))
    if Player == "leave" or Player == "Leave": # if player chose to exit
        print("exiting now")
        l=1 # setting the var to 1 so it fails the while loop check
    elif Player == "rock" or Player == "Rock": 
        if Com == 1: #if comp chooses rock
            print("tie game")
            print("Comp Chose Rock")
        elif Com == 2: #if comp chooses paper
            print("you lost")
            print("Comp Chose Paper")
        elif Com == 3: #if comp chooses scissors
            print("you win")
            print("Comp Chose Scissors")
    elif Player == "Paper" or Player == "paper":
        if Com == 1:
            print("you win")
            print("Comp Chose Rock")
        elif Com == 2:
            print("tie game")
            print("Comp Chose Paper")
        elif Com == 3:
            print("you lost")
            print("Comp Chose Scissors")
    elif Player == "scissors" or Player == "Scissors":
        if Com == 1:
            print("you lost")
            print("Comp Chose Rock")
        elif Com == 2:
            print("you win")
            print("Comp Chose Paper")
        elif Com == 3:
            print("you lost")
            print("Comp Chose Scissors")
    else:
        print("acceptable value not entered try again")
