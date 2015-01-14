//Lab #2: Programs That Calculate
//Shengyuan Guo
//21/09/2012
/* When given an encrypted combination, this program outputs the actual
combination.*/ 

#include <stdio.h>

int main()
{
    int combo,a,b,c,d;
    printf("Enter an encrypted 4-digit combination: ");
    scanf("%i", &combo);
    a=combo/1000;
    b=combo/100- a*10;
    c=combo/10-a*100-b*10;
    d=combo-a*1000-b*100-c*10;
    printf("The real combination is: %i%i%i%i",d,9-b,9-c,a);
    return 0;

}
