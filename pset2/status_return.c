#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}

// We use the method of 'echo $?' to find out what is the return value of a code
// for example here if if statement works it'll print 1 and if is not satisfies it'll print 0 when echo $? is written in code
// 0 by default means the code is properly running and 1 means there is a errror or bug in it

// And when we write return 0 in-between the code, then the code will stop after executing return 0's line