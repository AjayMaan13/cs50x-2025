#include <cs50.h>
#include <stdio.h>


// An array can be written as int array[]={1,2,3,4,4} and in reality its {1,2,3,4,4,'\0'} where the last value is null

// arrays can also be boolian i.e true and false (bool array[5]) and we can change values by array[3] =true or false if you want
// an array can also be 2-D by creating an array of int array[5][5] but it takes 25 direct spaces.

// If you want to copy two arrays of same size in which one is empty and other is full we need to use a for loop
//int foo [5] = { 1, 2, 3, 4, 5 };
//int bar [5];
//for(int j = 0; j < 5; j++)
//{
//    bar[j] = foo[j];
//}


// Constant
const int N = 3;     // Global variable

// Prototype
float average(int length, int array[]);   // return_type function_name(variable or parameters to be used)

int main(void)
{
    // Get scores
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])        // function along with 2 parameters
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;      // (float) helps to return the value as float even if all others are int
}