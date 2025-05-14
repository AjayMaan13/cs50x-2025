#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int printRandoms();

int main(void)
{
    int a = printRandoms();
    printf("%i\n", a);
    return 0;
}

int printRandoms()
{
    srand(time(0));
    int n;
    for (int i = 0; i < 1; i++)
    {
        int num = (rand() % (1 - 0 + 1)) + 0;
        n = round(num);

    }
    return n;
}