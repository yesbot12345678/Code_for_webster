import random
l=0 
p=0
c=0
t=0
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
            t += 1
            print("comp has own", c, "times")
            print("player has own", p, "times")
            print("you have ties", t, "times")
        elif Com == 2: #if comp chooses paper
            print("you lost")
            print("Comp Chose Paper")
            c += 1
            print("comp has own", c, "times")
            print("player has own", p, "times")
            print("you have ties", t, "times")
        elif Com == 3: #if comp chooses scissors
            print("you win")
            print("Comp Chose Scissors")
            p += 1
            print("comp has own", c, "times")
            print("player has own", p, "times")
            print("you have ties", t, "times")
    elif Player == "Paper" or Player == "paper":
        if Com == 1:
            print("you win")
            print("Comp Chose Rock")
            p += 1
            print("comp has own", c, "times")
            print("player has own", p, "times")
            print("you have ties", t, "times")
        elif Com == 2:
            print("tie game")
            print("Comp Chose Paper")
            t += 1
            print("comp has own", c, "times")
            print("player has own", p, "times")
            print("you have ties", t, "times")
        elif Com == 3:
            print("you lost")
            print("Comp Chose Scissors")
            c += 1
            print("comp has own", c, "times")
            print("player has own", p, "times")
            print("you have ties", t, "times")
    elif Player == "scissors" or Player == "Scissors":
        if Com == 1:
            print("you lost")
            print("Comp Chose Rock")
            c += 1
            print("comp has own", c, "times")
            print("player has own", p, "times")
            print("you have ties", t, "times")
        elif Com == 2:
            print("you win")
            print("Comp Chose Paper")
            p += 1
            print("comp has own", c, "times")
            print("player has own", p, "times")
            print("you have ties", t, "times")
        elif Com == 3:
            print("tie game")
            print("Comp Chose Scissors")
            t += 1
            print("comp has own", c, "times")
            print("player has own", p, "times")
            print("you have ties", t, "times")
    else:
        print("acceptable value not entered try again")
