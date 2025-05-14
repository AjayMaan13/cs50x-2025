// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();
int printRandoms();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with generations
person *create_family(int generations)
{
    // Allocate memory for new person
    person *n = malloc(sizeof(person));
    if (n == NULL)
    {
        printf("Could not find memory");
        return NULL;
    }

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // Set parent pointers for current person
        n -> parents[0] = parent0;
        n -> parents[1] = parent1;

        // Randomly assign current person's alleles based on the alleles of their parents
        n -> alleles[0] = parent0 -> alleles[printRandoms()];
        n -> alleles[1] = parent1 -> alleles[printRandoms()];
    }

    // If there are no generations left to create
    else
    {
        // Set parent pointers to NULL
        n -> parents[0] = NULL;
        n -> parents[1] = NULL;

        // TODO: Randomly assign alleles
        n -> alleles[0] = random_allele();
        n -> alleles[1] = random_allele();

    }

    // Return newly created person
    return n;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    //Handle base case
    person *f = malloc(sizeof(person));
    if (f == NULL)
    {
        printf("Could not find memory");
    }

    //Setting pointer of newly created struct to parents
    f -> parents[0] = p -> parents[0];
    f -> parents[1] = p -> parents[1];
    free(p);

    // Free parents recursively

    if (f -> parents[0] != NULL)
    {
        // Recursion for freeing parents
        free_family(f -> parents[0]);
        free_family(f -> parents[1]);
        free(f);
    }
    else
    {
        free(f);
    }
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0 ; i < generation * INDENT_LENGTH ; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p -> alleles[0], p -> alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p -> alleles[0], p -> alleles[1]);
    }
    else
    {
        for (int i = 0 ; i < generation - 2 ; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p -> alleles[0], p -> alleles[1]);
    }

    // Print parents of current generation
    print_family(p -> parents[0], generation + 1);
    print_family(p -> parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
int printRandoms()
{
    srand(time(0));
    int n;
    for (int i = 0 ; i < 1 ; i++)
    {
        int num = (rand() % (1 - 0 + 1)) + 0;
        n = round(num);

    }
    return n;
}