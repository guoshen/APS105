//Lab #7: The Mastermind Assistant (Recursion)
//Shengyuan Guo
//November 12,2012
/* A program that asks the user to input a guess pattern,
the number of white and black pegs. The program then prints out all the
combinations of keys for the case using letters from a-f */
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    printf("Enter pattern length: ");
    scanf("%d",&n);

    char str [n+1];
    char guess[n+1];
    printf("Input the guess pattern: ");
    scanf ("%s", guess);


    int wpeg, bpeg;
    printf("Enter the number of black pegs in the feedback: ");
    scanf("%d", &bpeg);
    printf("Enter the number of white pegs in the feedback: ");
    scanf("%d", &wpeg);

    //str [n]='\0';
    //guess [n]='\0';
    printf("The possible key patterns are:");
    rec(n,0,str,guess, wpeg, bpeg);

    return 0;


}

void rec(int n,int filled, char *str, char *guess, int wpeg, int bpeg)

{
    char i;

    if (n==filled)
    {



        if (isMatched(n,str,guess,wpeg,bpeg)==1)
        printf("%s \n",str);



    }
    else
    {

        for(i='a'; i<='f'; i++)
        {
            if (isPossible(n,filled,str,guess,wpeg+bpeg)==1)
            {
                str[filled]=i;
                rec(n,filled+1,str, guess,wpeg,bpeg);
            }
        }

    }



}

int isMatched(int n, char *key,char *guess, int wpeg,int bpeg)
{
    int bctr=0 , wctr=0;
    int i;
    char result[n];
    int m;
    bool check=true;

    for (i=0;i<n; i++)
    {
        if (key[i]==guess[i])
        {
        bctr++;
        result[i]='b';
        }
        else
        {
            result [i]='.';
        }
    }
    if(bctr!=bpeg)
        return 0;

    for (i=0;i<n; i++)
    {
        if (result[i]!='b')
        {
            check=false;

        }
        else
        {
            check=true;
        }
        for (m=0; m<n && check==false; m++)
        {
            if (key[m]==guess[i] && result[m]=='.')
            {


            wctr++;
            result[m]='w';
            check=true;
            }
        }

    }



    if (bctr==bpeg && wctr==wpeg)
    return 1;
    else
    return 0;

}

int isPossible(int n, int filled, char *str, char *guess,int sumPeg)
{
    int matched=0;
    int i;
    int j;

    for (i=0; i<filled; i++)
    {
        for (j=0 ; j<n; j++)
        {
            if (guess[j]==str[i]  )
            {
                matched++;
                j=n;

            }
        }
    }
    if (matched+(n-filled)>=sumPeg)
    return 1;
    else
    return 0;
}

