# Codes
Repository codes
python program code for guessing the word game
print("Welcome !!!\n")
print("While guessing always use small letters")
print("There are 3 levels:\n1.) Easy level\n2.)Medium level\n3.)Hard level")
level = int(input("Choose the level: "))
if level == 1:
    print("Level 1 : Easy")
    secret = "egg"
    guess = ""
    life=0
    limit=3
    while guess != secret and life<limit:
        guess = input("Guess the word: ")
        if life == 0:
            print("Total life : 3")
            if guess != secret:
                print("OOPS\t Wrong, Try again :)")
                print("Let me give a clue: It is white in color")

        elif life == 1:
            print("Life remaining : 2")
            if guess != secret:
                print("OOPS\t Wrong, Try again :)")
                print("Let me give a clue: It breaks easily")
        elif life ==2:
            print("Life remaining : 1")
            if guess != secret:
                print("OOPS\t Wrong, Try again :)")
                print("Let me give a clue: It is round in shape")

        else:
            print("invalid")
        life += 1
    if guess == secret:
        print("Congratulations!!! You win!")
    else:
        print("Sorry -_- , out of guesses, try again")


elif level == 2:
    print("Level 2 : Medium")
    secret = "birthday candle"
    guess = ""
    life = 0
    limit = 3
    while guess != secret and life<limit:
        guess = input("Guess the word: ")
        if life == 0:
            print("Total life : 2")
            if guess != secret:
                print("OOPS\t Wrong, Try again :)")
                print("Let me give a clue: They sing when it is alive")

        elif life == 1:
            print("Life remaining : 2")
            if guess != secret:
                print("OOPS\t Wrong, Try again :)")
                print("Let me give a clue: They clap when it dies")
        '''elif life ==2:
            print("Life remaining : 1")
            if guess != secret:
                print("OOPS\t Wrong, Try again :)")
                print("Let me give a clue: It is round in shape")'''
        '''else:
            print("invalid")'''
        life += 1
    if guess == secret:
        print("Congratulations!!! You win!")
    else:
        print("Sorry -_- , out of guesses, try again")

elif level == 3:
    print("Level 3 : Hard")
    secret = "popcorn"
    guess = ""
    life = 0
    limit = 3
    while guess != secret and life<limit:
        guess = input("Guess the word: ")
        if life == 0:
            print("Total life : 2")
            if guess != secret:
                print("OOPS\t Wrong, Try again :)")
                print("Let me give a clue: It makes sound when turning bigger")

        elif life == 1:
            print("Life remaining : 2")
            if guess != secret:
                print("OOPS\t Wrong, Try again :)")
                print("Let me give a clue: It losses weight when turning big")
        life += 1
    if guess == secret:
            print("Congratulations!!! You win!")
    else:
            print("Sorry -_- , out of guesses, try again")
