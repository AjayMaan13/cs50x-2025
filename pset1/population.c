#include <stdio.h>
#include "cs50.h"


int main(void)
{
    int i = 0;
    int p = 0;
    do
    {
        // The input for asking the start size
        p = get_int("Start size: ");
    }
    while (p < 9);
    int pl = 0;
    do
    {
        // Th input for asking the ending size
        pl = get_int("End size: ");
    }
    while (pl < p);

    while (p < pl)
    {
        // This is the MAIN working code of the program wher we add and subtract population each year
        // If a value is of decimal then we add only the integer part of it by using (int) in the code
        p = p + (int)p / 3 - (int)p / 4;
        i = i + 1;
    }

    // The final printing of the code
    printf("Years: %i\n", i);


}
