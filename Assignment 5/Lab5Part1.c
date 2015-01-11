//Lab #5: Functions
//Shengyuan Guo
//26/10/2012
/* This programs takes in a number greater than 99999 and encrypts it using an algorithm*/

void input (int *num)
{
    while(*num<=99999)
    {
    printf("Please enter an integer greater than 99999: ");
    scanf("%d",num);
    if (*num<=99999)
    printf("Incorrect input.\n");
    else
    {
        printf("The number entered is %d\n",*num);
    }

    }
}




    int add4(int num)
        {
            int a = 0, i = 1, newNum = 0;
            int pos=0;
            while (num / i != 0)
            {
                pos=i*10;
                a = (num % pos )/i +4 ;
                if (a >= 10)
                    a -= 10;
                newNum += a * i;
                i = pos;
            }
            return newNum;
        }

        int shift(int num)
        {
            int i = 1, newnum = 0;

            while (num / i >= 10 )
            {
                i*=10;
            }

            newnum = (num % i) * 10 + (num / i);
            return newnum;

        }

int main()
{
int originalNum=0;
int encryptNum=0;
input(&originalNum);



encryptNum=shift(add4(originalNum));

printOutput(encryptNum,originalNum);

}

void printOutput(int encryptNum, int originalNum)

{
    printf("Original number: %d\n",originalNum);
    printf("Encrypted number: %d",encryptNum);
}













