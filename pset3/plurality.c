#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9


// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{

    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        //How to find out value in structure using indexes which is a little different from python
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        bool result = vote(name);
        if (result == false)
        {
            printf("Invalid vote.\n");

        }

    }
    //TO check out the number of votes of each individual in case wanted
    //for (int n = 0; n < candidate_count; n++)
    //{
    //    printf("%s has ", candidates[n].name);
    //    printf("%i votes\n", candidates[n].votes);
    //}

    // Display winner of election
    print_winner();


}

// Update vote totals given a new vote
bool vote(string name)
{
    //For giving a vote to someone
    for (int i = 0 ; i < candidate_count ; i++)
    {
        //This checks if the string value of name and input name is same and if yes then it adds a vote to that person
        if (!strcmp(candidates[i].name, name))
        {
            candidates[i].votes += 1;
            return true;

        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int a, b;
    a = candidates[0].votes;
    b = 0;

    // This code helps to find the maximum amount of votes a person got in election
    for (int j = 0 ; j < candidate_count ; j++)
    {
        if (candidates[j + 1].votes > a)
        {
            a = candidates[j + 1].votes;
            b = j + 1;
        }

    }
    printf("%s\n", candidates[b].name);

    // This part of code is required to print any other candidate which has equal votes
    for (int l = 0 ; l < candidate_count ; l++)
    {
        if (l != b)
        {
            if (candidates[l].votes == a)
            {
                printf("%s\n", candidates[l].name);
            }

        }

    }
    return;
}