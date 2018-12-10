#include <stdio.h>
#include <stdlib.h>

// Header file includes declared variables and other various functions.
#include "game.h"

int main()
{
    // Activates "myword" function to receive entered word for the txt file.
    myword();
    // Introduces user to the game and tells what the word
    // they are guessing id related to.
    printf("*******Guess The Correct Word Below*******\n");
    // Displays the hint to screen from the function created in "game.h"
    displayhint();
    // Loop that keeps asking for guesses until the MAX_GUESS has been reached where the game will end.
    while (endofgame()!= 1)
    {
        printguess();
        // Show the player how many guesses they have left.
        printf("\nGuess %d of %d\n", currentguess);
        // Accept a guess from the player.
        printf("Enter Your Guess: ");
        scanf("%s", &guess);
    }
    // Shows if user has won(if statement) or lost(else statement)
    if (hasuserwon() == 1)
    {
        printf("Good Job, you guessed the correct word.\n");
    }
    else
    {
        printf("Try Again.\n");
    }
    return 0;
}



