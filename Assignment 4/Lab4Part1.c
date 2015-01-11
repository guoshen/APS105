//Lab #4: Making Decisions and Repetition
//Shengyuan Guo
//20/10/2012
/* This program makes change for the user, based on the user input in pennies.*/

#include <stdio.h>

int main()
{
    int coinctr=1;  //loop control

    int quarters=0,dimes=0,nickels=0,pennies=0;

    int ctr=0, andpos=0; //check position

    while (coinctr>0 && coinctr<100)
    {

        ctr=0;
        printf("Please give an amount in cents less than 100: ");
        scanf("%d",&coinctr);
        quarters= coinctr/25;
        dimes=coinctr%25/10;
        nickels=coinctr%25%10/5;
        pennies=coinctr%25%10%5;


        if(pennies>0)
            andpos=4;
        else if(nickels>0)
            andpos=3;
        else if(dimes>0)
            andpos=2;
        if (coinctr>0 && coinctr<100)
        {


            printf("%d cents: ", coinctr);

            if (quarters>0)
            {
                printf("%d quarter", quarters);
                if (quarters>1)
                {
                    printf("s");
                }

                ctr++;
            }

            if (dimes>0)
            {
                if (ctr>0 && andpos==2)
                    printf(" and %d dime", dimes);
                else if(ctr>0)
                    printf(", %d dime", dimes);
                else
                    printf("%d dime", dimes);

                if (dimes>1)
                    printf("s");
                ctr++;
            }

            if (nickels>0)
            {
                if (ctr>1 && andpos==3)
                    printf(", and %d nickel", nickels);
                else if (ctr>0 &&andpos==3)
                    printf(" and %d nickel", nickels);
                else if(ctr>0)
                    printf(", %d nickel", nickels);
                else
                    printf("%d nickel", nickels);

                if (nickels>1)
                    printf("s");
                ctr++;
            }

            if (pennies>0)
            {
                if (ctr>1 && andpos==4)
                    printf(", and %d cent", pennies);
                else if (ctr>0 && andpos==4)
                    printf(" and %d cent", pennies);
                else if(ctr>0)
                    printf(", %d cent", pennies);
                else
                    printf("%d cent", pennies);

                if (pennies>1)
                    printf("s");
                ctr++;
            }


            printf(".\n");
        }
}
printf("Goodbye.");
    return 0;

    }
