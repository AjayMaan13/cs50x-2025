#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");

    // Count number of characters up until '\0' (aka NUL)
    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
}

// This is the normal way to find length of a string, but there is a library called string.h where we can use
// strlen function which tells the length of a string
// like int a = strlen(string_name)