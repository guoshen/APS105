#include <stdio.h>
#include <math.h>
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
