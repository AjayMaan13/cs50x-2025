// a pointer usually takes up 8 bytes and an integer takes up 4 bytes

//& Provides the address of something stored in memory.
//* Instructs the compiler to go to a location in memory.


NUL means /0 and NULL means zero address

#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}
//Notice the %p, which allows us to view the address of a location in memory.
//&n is translated as “the address of n.” Executing this code will return an address of memory beginning with 0x.

// We can even store the address of an int in terms of int
int n = 50;
int *p = &n;

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", *p); // here %i prints the integer 50

    // and if we want to print the addreee
    printf("%p\n", p);
}

// There is no actual string library in c, its made up by cs50 by typing
typedef char *string;
// the actual way to store a string is
char *string_name = "abc"; // and in printf we use both %s and %c in order to print it

// A pointer to a string stores the address of the first character of the string and goes consequetly until "\0" comes
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    // both the code in line 44 and 45 prints the same thing i.e the address of the first char
    // one thing to know is that a string itself is an address
}

// another way to print each characters of a string
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}

// One of the format that we get wrong when adding multiple pointer in a same line "int* px, py, pz;"
// The corect way to write is to type "int* pa, *pb, *pc;"


//The logic behind strcmp is that it compares each character of two string which is not similar to ==
// == campares the address of two character not the number itself while in case of int it compare the integer itself
// what strcmp do is -
int main(void)
{
    char *s1 = "HI!";
    char *s2 = "HI!";
    if (*s1 == *s2 && *(s1+1) == *(s2+1) && *(s1+2) == *(s2+2)) // it automatically loop until "\0" comes i.e NUL
    {
        return true;
    }
    else
    {
        return false;
    }
}

//If arr is an array of doubles, then &arr [i] is a pointer-to-double who value is the address of the ith element of arr.
//An array's name, then, is actually just a pointer to its first element - you've been working with pointers all along!

//if we try to dereference a pointer whose value is NULL then we'll get a segmentation fault

// If we equate (=) a string to a new string, then any changes made on one string will result in the original string
// as = makes a new string pointing to the original final address

//"x =malloc(n);" i.e memory allocation helps to give n bytes of space available to a certain variable
// for a string of length n we need a memory of n+1 bytes
// At the end of the your code type "free(x)l;" to free up the space you took
// use stlib.h library to use malloc

// there is a method to store integer using malloc i.e providing space to a new_variable
new_variable = malloc(3*sizeof(int)) // i.e an array of 3 ints

//there is  possiblity that in malloc we use up too much storage and we need to come out of code before that happens
if (file_name_created_using_malloc == NULL)
{
    return 1;
}

// instead of using malloc and free we use a method called strcpy(new_file, old_file ); to copy a text

// Valgrind ./file_name is used to check for any memory related error in the code

// If we create an int array of high storage, then in the beginning it will have garbage values i.e random values

// Below are two examples of code to swap values of two variable and only one of them works
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
// in this code the changes are definately made but only in the scope of function and it'll reset after it completes
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}


void swap(int *a, int *b)  //  and to use the function we will type "swap(&a, &b);"
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// on the other hand in this code all the changes made are to the address of the code, hence, permanent

//In CS50, we have created functions like get_int to simplify the act of getting input from the user.
//scanf is a built-in function that can get user input. and it works as -

#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);
    printf("x: %i\n", x);
}

// And in the case of a string we need not to ask type &file_name, just the file_name itself
// But the main downside is that we need to create an array of size n+1 before using scanf
#include <stdio.h>

int main(void)
{
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}


//how to add documents in an csv file
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open CSV file
    FILE *file = fopen("phonebook.csv", "a"); // Open a file or creae a file -  a means append only

    // Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Print to file
    fprintf(file, "%s,%s\n", name, number); // (File_name_to_add_data, "Actual data");

    // Close file
    fclose(file);
}


// 8 bits = 1 byte

// THings to remember before opening a file or using uint8_t or mallow
//1. fclose the file
//2. free(file_name)
//3. use less memory than allocated
//4. when taking up space using malloc or uint8_t use n+1 space to write a file of space n



