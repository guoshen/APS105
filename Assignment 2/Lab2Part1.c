//Lab #2: Programs That Calculate
//Shengyuan Guo
//Student Number:999867130
//21/09/2012
/* This program calculates the cost of car rentals days and the number of free
 days offered, when given the daily rate and the rental period.*/ 


#include <stdio.h>

int main()
{
    float day_rate, total;
    int rental, free_days;


    printf("Enter the Daily Rate: ");
    scanf("%f",&day_rate,"\n");
    printf("Enter the Rental Period (in days): ");
    scanf("%i",&rental,"\n");
    
        free_days=rental/4;
    
    total= (rental-free_days)*(day_rate)*(1.13);
    printf("\nYour total free day(s) in this rental is: %i",free_days);
    printf("\nYour total charge including taxes is: %.2f",total);

    return 0;
}
