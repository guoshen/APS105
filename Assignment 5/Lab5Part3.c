//Lab #5: Functions
//Shengyuan Guo
//26/10/2012
/* This programs takes in date and then returns a day of the week using the Zeller's Algorithm*/
void inputDate (int *day, int *month, int *year)
{
printf("Please enter a date: ");
scanf("%d/%d/%d", day, month,year);


}

void calculateDay(int day, int month, int year)
{
    int A, B, C,D;
    int W,X,Y,Z,R;

 printf("The day %02d/%02d/%4d is a ",day,month,year);

    B=day;


    if (month<=2 )
    {
        A= month+10;
        year--;

    }
    else if (month>2)
    {
     A=month-2;
    }

    C= year%100;
    D= year/100;

    W=(13*A-1)/5;
    X=C/4;
    Y=D/4;
    Z=W+X+Y+B+C-2*D;
    R=Z%7;
    if (R<0)
    {
        R+=7;
    }




    if (R==0)
    {
        printf("Sunday.");
    }
    else if (R==1)
    {
        printf("Monday.");
    }
    else if (R==2)
    {
        printf("Tuesday.");
    }
    else if (R==3)
    {
        printf("Wednesday.");
    }
    else if (R==4)
    {
        printf("Thursday.");
    }
    else if (R==5)
    {
        printf("Friday.");
    }
    else if (R==6)
    {
        printf("Saturday.");
    }

}

/*void main()
{
    int d=0,m=0,y=0;
    inputDate(&d,&m,&y);

    calculateDay(d,m,y);
}
*/
