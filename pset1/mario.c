#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int b, c, e, f, g;
    int d = 0;
    int a = 0;

    //call a function to input number from key board
    a = get_int("Height : ");

    //when input is not in the range of 1 to 9,print error message
    while (!((a < 9) && (a >= 1)))
    {
        //input another number
        a = get_int("Height: ");
    }

    b = a - 1;
    c = 1;

    // This is the main code of the program
    do
    {

        for (e = b ; e >= 1 ; e--)
        {
            printf(" ");
            // This helps in printing white spaces for the pyramid
        }


        for (f = b ; f < a ; f++)
        {
            printf("#");
            // # printing code

        }
        b--;
        c++;
        d++;

        printf("  ");

        // The descending pyramid code
        for (g = b + 1 ; g < a ; g++)
        {
            printf("#");

        }


        printf("\n");
        // Ending of each line

    }
    while (d < a);
}