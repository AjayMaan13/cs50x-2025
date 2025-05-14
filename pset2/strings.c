#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%c %c %c %c\n", s[0], s[1], s[2], s[3]);  // Every string is an array with collection of characters
} // Here i shows the numbers assigned to each character 

// If we'll use %c then it'll print the actual number

// ** And if we take s[>2] then it'll print blank space **