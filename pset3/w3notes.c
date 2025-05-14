// control + c helps to stop a running program

// "time ./code argv[1]_value" is the code that helps to give us the time taken to run the code for example - time ./sort 3

// recursion is a kind of code in which a function calls itself again within the function itself. for example pyramid_new.c
// and it follows the code format of
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    // recursive case which is like
    else
    {
        return n * fact(n - 1);
    }
}



NUL means /0 and NULL means zero address
