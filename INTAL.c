#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char * initializeINTAL();

void Reversal(char *s)
{
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}




char * Multisum(char *a, char *b)
{

    char * ans = initializeINTAL();

    

    int len1 = strlen(a);
    int len2 = strlen(b);

    ans[len1] = '\0';


    int i=len1 - 1;
    int j=len2 - 1;


    int ansindex = i;

    int sum =0, carry = 0, s=0;

    while(i>=0 && j>=0)
    {
        s =  a[i] - '0' + (b[j] - '0') + carry;
        sum  = s % 10;
        carry = s / 10;

        ans[ansindex--] = sum + '0';

        i--; j--;


    }

    if(carry>0)
    {
        ans[ansindex] = carry + '0';
    }

    return ans;
}






char *initializeINTAL()
{
    int n = 1001;
    char *p = (char *)malloc(n * sizeof(char));

    for (int i = 0; i < n; i++)
    {
        p[i] = '0';
    }

    p[n - 1] = '\0';
    return p;
}

char *intal(char str[])
{
    int n = 1001;
    char *p = (char *)malloc(n * sizeof(char));

    for (int i = 0; i < n; i++)
    {
        p[i] = '0';
    }

    p[n - 1] = '\0';

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        p[i] = str[i];
    }

    p[len] = '\0';
    return p;
}

int compareINTAL(char *a, char *b)
{
    if (strlen(a) > strlen(b))
        return 1;

    if (strlen(a) < strlen(b))
        return -1;

    int len1 = strlen(a);

    int i = 0;

    while (i < len1)
    {

        if (a[i] - '0' > b[i] - '0')
            return 1;

        if (a[i] - '0' < b[i] - '0')
            return -1;

        i++;
    }

    return 0;
}

char *intalAdder(char *a, char *b)
{
    Reversal(a);
    Reversal(b);

    char *Adder = initializeINTAL();

    int adderindex = 0, carry = 0, sum = 0, s = 0;

    int len1 = strlen(a), len2 = strlen(b);

    int i = 0, j = 0;

    while (i < len1 && j < len2)
    {

        s = (a[i] - '0') + (b[j] - '0') + carry;
        sum = s % 10;
        carry = s / 10;

        Adder[adderindex++] = sum + '0';

        i++;
        j++;
    }

    while (i < len1)
    {

        s = (a[i] - '0') + carry;
        sum = s % 10;
        carry = s / 10;

        Adder[adderindex++] = sum + '0';

        i++;
    }

    while (j < len2)
    {

        s = (b[j] - '0') + carry;
        sum = s % 10;
        carry = s / 10;

        Adder[adderindex++] = sum + '0';

        j++;
    }

    if (carry > 0)
    {

        Adder[adderindex++] = carry + '0';
    }

    Adder[adderindex] = '\0';

    Reversal(Adder);
    Reversal(a);
    Reversal(b);

    return Adder;
}



char *intalSubtractor(char *a, char *b)
{
    char *Subtractor = initializeINTAL();
    if (compareINTAL(a, b) == 0) // if both are equal
    {
        Subtractor[1] = '\0';
    }

    else if (compareINTAL(a, b) == 1)// if a greater than b
    {
        Reversal(a);
        Reversal(b);

        int subindex = 0;

        int len1 = strlen(a), len2 = strlen(b);

        int i = 0, j = 0;

        int c = a[i] - '0';

        while (i < len1 && j < len2)
        {
            if (c < b[j] - '0')
            {
                Subtractor[subindex++] = ((c + 10) - (b[j] - '0') + '0');
                i++;
                j++;

                c = a[i] - '0' - 1;
            }

            else
            {
                Subtractor[subindex++] = ((c - (b[j] - '0')) + '0');
                i++;
                j++;

                c = a[i] - '0';
            }
        }

        while (i < len1)
        {
            if (c < 0)
            {
                Subtractor[subindex++] = c + 10 + '0';
                i++;
                c = a[i] - '0' - 1;
            }

            else{

                Subtractor[subindex++] = c  + '0';
                i++;
                c = a[i] - '0';


            }

        }

        Subtractor[subindex] = '\0';

        //removing extra zeros

        i = subindex - 1;

        while (i >= 0)
        {
            if (Subtractor[i] == '0')
                Subtractor[i] = '\0';
            else
                break;

            i--;
        }

        Reversal(Subtractor);
        Reversal(a);
        Reversal(b);
    }

    else // if b greater than a
    {

        Reversal(a);
        Reversal(b);

        int subindex = 0;

        int len1 = strlen(a), len2 = strlen(b);

        int i = 0, j = 0;

        int c = b[j] - '0';

        while (i < len1 && j < len2)
        {
            if (c < a[i] - '0')
            {
                Subtractor[subindex++] = ((c + 10) - (a[i] - '0') + '0');
                i++;
                j++;

                c = b[j] - '0' - 1;
            }

            else
            {
                Subtractor[subindex++] = ((c - (a[i] - '0')) + '0');
                i++;
                j++;

                c = b[j] - '0';
            }
        }

        while (j < len2)
        {
            if (c < 0)
            {
                Subtractor[subindex++] = c + 10 + '0';
                j++;
                c = b[j] - '0' - 1;
            }

            else{

                Subtractor[subindex++] = c  + '0';
                j++;
                c = b[j] - '0';


            }
        }

        Subtractor[subindex] = '\0';

        //removing extra zeros

        j = subindex - 1;

        while (j >= 0)
        {
            if (Subtractor[j] == '0')
                Subtractor[j] = '\0';
            else
                break;

            j--;
        }

        Reversal(Subtractor);
        Reversal(a);
        Reversal(b);
    }

    return Subtractor;
}




char* multiplyINTAL(char *a, char *b)
{
    char *Multiplier = initializeINTAL();


    if((strlen(a)== 1 && a[0]=='0' ) || (strlen(b)== 1 && b[0]=='0'))
    {
        Multiplier[1] = '\0' ;
        return Multiplier;

    }

    if((strlen(a)== 1 && a[0]=='1' ) || (strlen(b)== 1 && b[0]=='1'))
    {
        if(strlen(a)== 1 && a[0]=='1' )
        {
            Multiplier = b;
            return Multiplier;
        }

        else{

            Multiplier = a;
            return Multiplier;


        }

    }


    int len1 = strlen(a);
    int len2 = strlen(b);

    Multiplier[len1 + len2] ='\0';

    
    char *temp = initializeINTAL();
    int ptr1 =1;

    for(int i = len2-1; i >= 0; i--)
    {
        char *result = initializeINTAL();
        int sum = 0, carry = 0;
        result[len1 + len2] = '\0';
        int ptr2 = len1 +len2 - ptr1;


        for(int j = len1-1; j >= 0; j--)
        {
            sum = (a[j]-'0')*(b[i]-'0') + (result[ptr2]-'0')+carry;
            result[ptr2] = (result[ptr2]-'0') + '0' + (sum%10);
            carry = sum/10;
            --ptr2;

        }

        if(carry>0)
        {
            result[ptr2] = (result[ptr2] - '0') + carry + '0';

        }


        temp = Multisum(Multiplier,result);
        free(Multiplier);
        Multiplier = temp;

        free(result);


        ++ptr1;

    }

    //for removing extra zeros

    Reversal(Multiplier);

    int i = strlen(Multiplier)-1;

    while(i>=0)
    {
        if(Multiplier[i] == '0')Multiplier[i] = '\0';
        else break;

        i--;
    }

    Reversal(Multiplier);

    return Multiplier;

}


char* FibonacciINTAL(unsigned int n)
{
    char *a = initializeINTAL();
    a[1] = '\0';


    if(n == 0){
        return a;
    }

    char *b = initializeINTAL();

    b[0] = '1';
    b[1] = '\0';


    if(n == 1){

        free(a);
        return b;
    }

    char *temp = initializeINTAL();

    for(int i = 2; i <= n; i++){

        temp = intalAdder(a,b);
        free(a);
        a = b;
        b = temp;
    }

    free(a);

    return b;



}


char* factorialINTAL(unsigned int n)
{
    char *result = initializeINTAL();
    result[0] = '1';
    result[1] = '\0';

    if(n<=1)
        return result;


    char *num = initializeINTAL();
    num[0] = '1';
    num[1] = '\0';


    char *one = initializeINTAL();
    one[0] = '1';
    one[1] = '\0';



    char *temp = initializeINTAL();

    for(int i=2; i<=n; i++)
    {
        temp = intalAdder(num,one);
        num = temp;
        temp = multiplyINTAL(result,num);
        free(result);
        result = temp;

    }

    free(num);

    return result;

    
}






int main()
{
    char a[1001], b[1001];


    printf("\n Before You Proceed Furthur... \n\nNote :\n1. This program takes only unsigned non negative integers  as inputs.\n\n2. In case of Addition, Subtraction and multiplication you should put two inputs so that the resultant answer does not exceed 1000 digits as locating memory in the heap takes space,So my algorithm is deliberately restricted to 1000 digits which is more than enough for which a long long unsigned number can do.\n\n3. In case of Fibonacci and Factorial the input should also be unsigned non negative integers and the the resultant answer should not exceed 1000 digits for the same reason.Now lets have fun with big big numbers!!!!\n\n");


    printf("\nenter two non negative unsigned numbers , don't worry about however big it is!:\n");

    scanf("%s", a);
    scanf("%s", b);



    printf("comparison result: %d\n",compareINTAL(intal(a),intal(b)));

    printf("Addtiton result: %s\n",intalAdder(intal(a),intal(b)));

    printf("Subtraction Result: %s\n", intalSubtractor(intal(a), intal(b)));

    printf("Multiplication Result: %s\n",multiplyINTAL(intal(a),intal(b)));


    printf("\nEnter any non negative unsigned number:\n");

    unsigned int n;

    scanf("%d",&n);


    printf("Fibonocci no %d is %s\n",n,FibonacciINTAL(n));

    printf("Factorial of %d is %s\n",n,factorialINTAL(n));


    return 0;
}
