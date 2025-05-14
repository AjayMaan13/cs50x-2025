#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // This is the code which asks for the user to type in their name
    string name = get_string("What's your name? ");

    //The final printing statement of the code
    printf("Hello, %s\n", name);
}