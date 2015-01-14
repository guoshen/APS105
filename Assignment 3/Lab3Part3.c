#include <stdio.h>
#include <math.h>
//Lab #3
//Shengyuan Guo
//1/10/2012
/* Indicates the BMI and assesses the weight profile of a person given 
height and weight*/
int main()
{
    double weight=0, height=0, bmi=0,BMI=0, kg=0, m=0;
    char wUnit1,wUnit2, hUnit1,hUnit2;


    printf("Enter the body weight: ");

    scanf("%lf%c%c",&weight, &wUnit1,&wUnit2);
    if (wUnit1=='l' && wUnit2=='b')
    {
        kg=weight*0.4536;
    }
    else if (wUnit1=='k' && wUnit2=='g')
    {
        kg=weight;
    }

    printf("Enter the height: ");

    scanf("%lf%c%c",&height, &hUnit1,&hUnit2);
    if (hUnit1=='i'&& hUnit2=='n')
    {
        m=height/39.37;
    }
    else if (hUnit1=='f'&& hUnit2=='t')
    {
        m=height/3.28;
    }
    else if (hUnit1=='m'&& hUnit2=='t')
    {
        m=height;
    }

    bmi=kg/(pow(m,2));

    BMI=rint(bmi*100)/100;

    printf("\n\nThe Body Mass Index (BMI) is: %.1lf ",BMI);
    printf("\n");

    if (BMI<16.5 && BMI>0)
    {
    printf("Category: Severely Underweight");
    }
    else if (BMI<=18.4 && BMI>=16.5)
    {
    printf("Category: Underweight");
    }
    else if (BMI<=24.9 && BMI>=18.5)
    {
    printf("Category: Normal");
    }
    else if (BMI<=29.9 && BMI>=25.0)
    {
    printf("Category: Overweight");
    }

    else if (BMI>=30.0)
    {
    printf("Category: Obese");
    }

return 0;

}
