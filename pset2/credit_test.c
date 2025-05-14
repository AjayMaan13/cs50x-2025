#include <cs50.h>
#include <stdio.h>
#include <math.h>



int main(void)
{
//    int ten1 = 10;
  //  int ten2 = 1;
//    printf("the last place is %li\n", (num % (10))/1);   first even place and ten =1
//    printf("the even place is %li\n", ((num % ten1)/ten2)); //secound even place and ten1 = 10000
    int count = 16;
    int even_sum = 0;
    long even_ten1 = 10;
    long even_ten2 = 1;
    int num = 23;
    printf("secound letter is %i\n", num/10);
    printf("first letter is %i\n",(num%10));


//    for (int j = 0 ; j < count / 2 ; j++)
  //  {
    //    even_sum  += ((num % even_ten1)/even_ten2);
      //  printf("Even digit is %li\n", ((num % even_ten1)/even_ten2));
        //even_ten1*=100;
        //even_ten2*=100;
    //}
}


// we can use two for loops by / the number and getting the place value
// For the odd places we can use 10, 1000 i.e a**100, starting from 10
// similarly for the even places we can use the 100, 10000 i.e a**100 starting from 100
//

