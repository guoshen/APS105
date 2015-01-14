//Lab #3
//Shengyuan Guo
//1/10/2012
/* This program determines whether a given substance is water, mercury,
gold, silver or copper when given the threshold temperature and the boiling point.*/ 

#include <stdio.h>

int main()
{
   int water=100;
   int mercury=357;
   int copper=1187;
   int silver=2193;
   int gold=2660;
   int t, observedBP;
   int min, max;


   printf("Enter the threshold in celsius: ");
   scanf("%d", &t);
   printf("Enter the observed boiling point in celsius: ");

   scanf("%d", &observedBP);
   printf("\n");
   min=observedBP-t;
   max=observedBP+t;
   if (min<=water && water<=max)
   {
       printf("The substance you tested is: Water");
   }
    else if (min<=mercury && mercury<=max)
   {
       printf("The substance you tested is: Mercury");

   }
    else if (min<=copper && copper<=max)
   {
       printf("The substance you tested is: Copper");
   }
   else if (min<=silver && silver<=max)
   {
       printf("The substance you tested is: Silver");
   }
   else if (min<=gold && gold<=max)
   {
       printf("The substance you tested is: Gold ");
   }
   else
   {
       printf("Substance unknown.");
   }


return 0;

}
