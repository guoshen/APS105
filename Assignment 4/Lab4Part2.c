//Lab #4: Making Decisions and Repetition
//Shengyuan Guo
//20/10/2012
/* This program prompts the user for a list of numbers.
The program calculates and outputs the standard deviation, average, the maximum and the minimum of the set.*/
#include <stdio.h>
#include <math.h>
int main()
{
    float number=0,sum=0, stdDeviation=0,sumSquared=0, max=0, min=0, mean=0;
    int ctr=0;

    printf("Please enter a list of numbers ending with a negative number.\n");

    while (number>=0)
    {
         scanf("%f",&number);
         if (number>=0)
         {
            ctr++;
            sum+=number;
            sumSquared+=(number*number);
            if (ctr==1)
            {
                min=number;
                max=number;
            }
            else
            {
                if (number>max)
                {
                    max=number;
                }
                if (number<min)
                {
                    min=number;
                }
            }

        }
    }

    printf("\nN = %d, ",ctr);
    if (ctr>0)
    {
         mean=sum/ctr;
         printf("min = %.2f, max = %.2f, mean = %.2f, ",min,max,mean);
         if (ctr>=2)
         {
             stdDeviation=sqrt((sumSquared- (sum*sum)/ctr)/(ctr-1));
             printf("std = %.2f\n", stdDeviation);
          }
          else if(ctr==1)
          {
              printf("std = Undefined\n");
          }
     }
     else
     {
         printf("no statistics can be calculated!\n");
     }

    return 0;

}
