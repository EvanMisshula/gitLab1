import random as rd
import numpy as nd



rd.seed(42)

wins= 0
losses = 0
seriesOver=False
thisGameOver = False
while seriesOver==False:
    print("I am thinking of a number in the range 1 - 64 inclusive.")
    print(" You have 7 guesses to guess it")
    guessNum = 0
    mySecretNum=rd.randint(1,64)
    qString="my secret number is {secret}.".format(secret=mySecretNum)
    print(qString)

    rawGuess = int(input('What is your guess?'))

    if (rawGuess>=1 and rawGuess<=64):
        guess=rawGuess
        guessNum=guessNum+1
    else:
        rawGuessBad = True
        while rawGuessBad:
            rawGuess = int(input('Your guess was outside the range, try again.'))
            if (rawGuess>=1 and rawGuess<=64):
                rawGuessBad = False
                guessNum = guessNum + 1

    while (guessNum <= 8 and thisGameOver==False):
        if guessNum==8:
            print("Sorry, you lose!! The number was {mySecret}!!".format(mySecret=mySecretNum))
            losses = losses + 1
            thisGameOver=True
        else:
            if guess<mySecretNum:
                print("Your guess was too low.")
                guess = int(input('What is your guess?'))
                guessNum = guessNum + 1
            elif guess>mySecretNum:
                print("Your guess was too high.")
                guess = int(input('What is your guess?'))
                guessNum = guessNum + 1
            else:
                print("Congrats, you are a winner in {tries} tries!!".format(tries=guessNum))
                wins = wins + 1
                thisGameOver=True
           

        
        
    playAgain=input('Enter yes to play again, anything else to quit.')
    if playAgain=="yes":
        seriesOver = False
        thisGameOver = False
    else:
        seriesOver = True
        
games = wins + losses
winPct = round(100* wins / games, 3)

print("You won {wins:>3d} games out of {games:>4d} for a winning percent of {winPct:>5.3f}%.".format(wins=wins,games=games,winPct=winPct))
