#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct        //This is similar to how class works in python
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];  //Creating the structure named people with size of 2 elements 

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}