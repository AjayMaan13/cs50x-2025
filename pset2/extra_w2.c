#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    int b[2];
    char a[] ="abcABC";
    int len = strlen(a);

    char c ='a';
    char d ='b';
    b[0]=(int)c;
    b[1]=2;
    for(i=0;i<2;i++)
    {
        printf("ascii value is: %i\n", b[i]-90);    // this is the answer of the code
 //now we need to first convert it to uppercase letters and then do this technique and at last compare it to the points array
    }
//    for (i=0;i<len;i++)
  //  {
    //    printf("char is: %i\n ",a[i]);
      //  printf("upper words is: %c and the new int is %i\n", toupper(a[i]), toupper(a[i]));
        //printf("ascii value is: %d\n",toascii(a[i]);
//    }
  //  printf("Final score is: %i\n", b);
}