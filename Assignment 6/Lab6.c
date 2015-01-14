//Lab #6: Mastermind Fall 2012
//Shengyuan Guo
//November 3,2012
/* A program that plays a game of Mastermind*/
#include <stdio.h>
#include <stdbool.h>



int main()
{
    int l;
    int k;

    int score;
    int lenGuess;
	char key[l];
    char g[lenGuess][l];
    char r[lenGuess][l];
    printf("Enter the pattern length: ");
    scanf("%d",&l);
    printf ("Enter the number of guesses: ");
    scanf("%d",&lenGuess);
    

    printf("Input the key pattern with no spaces: ");
    scanf ("%s",key);
    score=0;

 for (k=0;k<lenGuess && score==0;k++)
 {

    printf("Input a guess pattern with no spaces: ");
    scanf (" %s",g[k]);

    score=checkInput(key,g[k],r[k],l);
    printOutput(l,k,r,g);

 }

if (score==1)
{
    printf("You guessed the pattern!");

}
else
{
    printf("You did not guess the pattern!");
}
 return 0;
}

int checkInput(char key[], char guess[], char result[], int lengthstr)

{
    int i,m;
    bool check;
    int score=1;
    for (i=0; i<lengthstr;i++)
    {
        if (key[i]==guess[i])
        {
            result[i]='b';
        }
        else
        {
            result[i]='.';
            score=0;
        }
    }
    for (i=0; i<lengthstr;i++)
    {
        if (result[i]!='b')
        {
         check=false;


            for(m=0; m<lengthstr && check==false; m++)
                {
                    if(result[m]=='.'  && key[m] == guess[i])
                        {
                            result[m]='w';
                            check=true;
                        }
                }
        }
    }

    return score;

}

void printOutput(int l, int k, char r[][l],char g[][l])
{
    int i,j;
    for (i=0;i<=k;i++)
    {

        printf("%d: ",i+1);

        for (j=0; j<l;j++)
        {
            if (r[i][j]=='b')
                printf("%c",r[i][j]);
        }
        for (j=0; j<l;j++)
        {
            if (r[i][j]=='w')
                printf("%c",r[i][j]);
        }
          for (j=0; j<l;j++)
        {
            if (r[i][j]=='.')
                printf("%c",r[i][j]);
        }
        printf(" ");
        for (j=0; j<l;j++)
        {
            printf("%c",g[i][j]);
        }
        printf("\n");
    }


}





