#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 28;
    int b = 50;
    int *c = &a;

    *c = 14;
    c = &b;
    *c = 25;

    // Print results
    printf("a has the value %i, located at %p\n", a, &a);
    printf("b has the value %i, located at %p\n", b, &b);
    printf("c has the value %p, located at %p\n", c, &c);
}
// print the statement to know what is the output

//Answer -

//c is an pointer and it first connects to the address of a, so any changes made to c first will result in a'change
//after that it connects to b hence now its free of a so any changes made now to c is equal to changes to b

//If we have a pointer-to-char called pc, then *pc is the data that lives at the memory address stored inside the variable pc.