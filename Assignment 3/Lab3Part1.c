#include <stdio.h>
#include <math.h>
//Lab #3
//Shengyuan Guo
//1/10/2012
/* This program determines which quadrant of the coordinate plane,
 a given point is in or indicates if the point is at the origin.*/ 
int main()
{
    float x, y, rx,ry;


    printf("Enter the x-coordinate in floating point: ");
    scanf("%f",&x );
    printf("\nEnter the y-coordinate in floating point: ");
    scanf("%f",&y);
    printf("\n\n");

    rx= rint(x*100)/100;
    ry= rint(y*100)/100;

    if (rx<0)
    {
        if (ry<0)
        {
            printf("(%.2f,%.2f) is in Quadrant III.", rx, ry);
        }
        else if (ry>0)
        {
            printf("(%.2f,%.2f) is in Quadrant II.", rx, ry);
        }
        else
        {
            printf("(%.2f,%.2f) is on the x axis.", rx, ry);
        }

    }
    else if (rx>0)
    {
        if (ry<0)
        {
            printf("(%.2f,%.2f) is in Quadrant IV.", rx, ry);
        }
        else if (ry>0)
        {
            printf("(%.2f,%.2f) is in Quadrant I.", rx, ry);
        }
        else
        {
            printf("(%.2f,%.2f) is on the x axis.", rx, ry);
        }
    }
    else if (ry!=0)
    {
        printf("(%.2f,%.2f) is on the y axis.", rx, ry);
    }
    else
    {
        printf("(%.2f,%.2f) is at the origin.", rx, ry);
    }

    return 0;
}
