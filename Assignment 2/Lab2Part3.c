//Lab #2: Programs That Calculate
//Shengyuan Guo
//Student Number:999867130
//21/09/2012
/* This program is a loan calculator which helps determine your monthly payment
amount.*/ 

#include <stdio.h>
#include <math.h>


int main()
{
    double P,D,M,r,x;
    int n;
    printf("Enter the purchase price P: ");
    scanf("%lf",&P);
    printf("Enter the amount of down payment D: ");
    scanf("%lf",&D);
    printf("Enter the finance term (in months): ");
    scanf("%i",&n);
    printf("Enter the monthly interest rate (in percent): ");
    scanf("%lf",&r);
    x=pow(1+r/100,n);
    M=((P-D)*r/100*x)/(x-1);
    printf("\nThe monthly payment is: %.2lf", M);
    return 0;
}





