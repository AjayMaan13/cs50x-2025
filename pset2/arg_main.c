#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])  //Here main has 2 parameters where argv takes in variable and argc is count of all args
                                   // argv - argument vector and argc argument count
{
    if (argc == 2) // If 1 new value is added in code, therefore 2 count of argv
                   // the last variable in argv is argv[argc-1] and first is argv[0]

                   // every value put into argv is a string, even if we put a int in it, it'll be saved as a string
                   // and if we type argv[n] where n is more than the argc then it'll give an error
    {
        printf("hello, %s\n", argv[1]);  // By default argv[0] is taken in by the system
    }
    else
    {
        printf("hello, world\n");
    }
}


// This helps to quickly provide with variable name before running the code. example:
// make arg_main
// ./arg_main David.   // 2 arguments here

//$ hello, David
//$

