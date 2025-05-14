#include <cs50.h>
#include <stdio.h>

//The output of this code is simple but the code that is written here is done by a professional i.e professional code here

//This code uses the mechanins of loop in function within function i.e one function triggers the function itself until the final output is generatted

void draw(int n);

int main(void)
{
    // Get height of pyramid
    int height = get_int("Height: ");

    // Draw pyramid
    draw(height);
}


// THis is the masterpiece of the code
void draw(int n)
{
    // If nothing to draw
    if (n <= 0)
    {
        return;
    }

// Draw pyramid of height n - 1 i.e to draw a pyramid of n length first we need to create a pyramid of n-1 length and place the final layer on the bottom
    draw(n - 1);

    // Draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

// How the code works is that first it checks if n is ==0 until that it goes into function with function
// like
//function
//{
//    function
//    {
//        function
//        {
//.          .....
//        }
//    }
//}
//
// and when at the final when n=0 then it comes out of the final loop turning n from 0 to 1, then 2 and so on until the Height
//