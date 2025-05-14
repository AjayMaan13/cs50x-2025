#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a,b,c,e,f,g,i;
    int d =0;

    // while(a>0 and a<9)
    //{}
    // a = get_int("Enter the levels of pyramid: \n");
    //}

    a = get_int("Enter the levels of pyramid: \n");
    b= a-1;
    c=1;

    do
    {

        for(e=b;e>=1;e--)
        {
            printf(" ");
        }


        for(f=b;f<a;f++)
        {
            printf("#");

        }
        b--;
        c++;
        d++;
        printf(" \n");

    }while(d<a);
    printf("The code ended  \n");
}