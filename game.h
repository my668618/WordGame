#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
// Defines "MAX_CHAR" to a maximum of 10 characters long wherever used.
#define MAX_CHAR 10
// Variable Declaration
void myword(void);
void displayhint(void);
void printguess(void);
int currentguess = 1;
int MAX_GUESS = 5;
int endofgame(void);
int match(void);
int hasuserwon(void);
int gameval;
char guess[MAX_CHAR];
char word[MAX_CHAR];
// Get the word from file.
void myword()
{
    FILE *ptrfile;
    ptrfile = fopen("word.txt", "r");
    fscanf(ptrfile, "%s", &word);
    fclose(ptrfile);
}
// Gets string from "hint.txt" and prints it out to the user
void displayhint()
{
    FILE *ptrfile;
    char hint[50];
    ptrfile = fopen("hint.txt", "r");
    printf("Your Hint: ");
    while(fgets(hint, 50, ptrfile) != NULL)
    {
        printf("%s", hint);
    }
    fclose(ptrfile);
}
// Function that determines is the game is over or not.
int endofgame()
{
    if (match() == 1 || currentguess > MAX_GUESS)
    {
        return 1;
    }
// Ends the game if the "if statement" is not met.
    else
    {
        return 0;
    }
}
// Compares entered word to word in file "word.txt".
int match()
{
    gameval = 1;
    int x;
    for(x = 0; x < MAX_CHAR; x++)
    {
        if(guess[x] != word[x])
            return 0;
    }
    return gameval;
}
// Prints back guess. Incorrect characters are filled with a "#"
void printguess()
{
    int x;
    printf("\nCurrent Guess: ");
    for (x = 0; x < MAX_CHAR; x++)
        if (word[x] == guess[x])
        {
            printf("%c", guess[x]);
        }
        else
        {
            printf("#");
        }
        currentguess++;
}
// Ends the game if all guesses are used or if word is correct.
int hasuserwon()
{
    if (endofgame() == 1 && match() == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


#endif // GAME_H_INCLUDED
