#include <stdio.h>
#include <stdbool.h>
//Lab #5: Functions
//Shengyuan Guo
//26/10/2012
/* This program allows user to play a game of dice. (Luck based on random number generators in C). 
*/


int rollDice()
{
    int int2 = rand() % 6 +1;
    int int1 = rand() % 6 +1;
    return int1+int2;
}

bool playGame()
{
    bool Game==true;
    int r = rollDice();
    int pt=r;


    if (r == 7 || r == 11)
    {
        printf("You rolled: %d\n", r);
        printf("You win!\n");
        return true;
    }
    else if (r == 2 || r == 3 || r == 12)
    {
        printf("You rolled: %d\n", r);
        printf("You loss!\n");
        return false;
    }
    else
    {
        pt = r;
        printf("Your pt is: %d\n", r);
    }

    while (Game==true)
    {
        r = rollDice();
        printf("You rolled: %d\n", r);
        if ( r == pt)
        {
            printf("You win!\n");
            return true;
        }
        else if (r == 7 )
        {
            printf("You loss!\n");
            return false;
        }
    }
}
void winLoss()
{
    int w = 0;
    int l = 0;
    char playAgain;
    playAgain ='y';

    while (playAgain=='y'  || playAgain=='Y')
    {
        if (playGame())
            w++;
        else
            l++;
        printf("Play again?");
        scanf(" %c",&playAgain);


    }
    printf("Wins: %d\n", win);
    printf("Losses: %d\n", l);
}
