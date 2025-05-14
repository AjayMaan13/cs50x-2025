#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9
int g_argc;
char **g_argv;
int q = 0;
int voter_count;
int eliminated_indexes[3];
int n = 0;

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;

    // This can be used to see which candidate is eliminated and we can set it to true
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    g_argc = argc;
    g_argv = argv;
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 0;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();
        n++;

//        printf("The votes given to the candidates for Rank %i round are: \n", q + 1);
  //      for (int g = 0 ; g < g_argc - 1 ; g++)
    //    {
      //      printf("%s has %i votes\n", candidates[g].name, candidates[g].votes);
        //}


        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        q++;
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int a = 0 ; a < candidate_count ; a++)
    {
        if (strcmp(name, candidates[a].name) == 0)
        {
            preferences[voter][a] = rank;
            printf("%s now has preference %i\n", candidates[a].name, preferences[voter][a]);
            return 1;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //use q here
    for (int b = 0 ; b < candidate_count ; b++)

        if (candidates[b].eliminated)
        {
            b++;
        }
        //Casting votes when the preferences matches the current order
        for (int k = 0 ; k < voter_count ; k++)
        {
            if (preferences[k][b] == q)
            {
                candidates[b].votes++;
            }
        }

    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int c = 0 ; c < g_argc - 1 ; c++)
    {
        if ((candidates[c].votes > (voter_count / 2)) && candidates[c].eliminated == false).
        // MISTAKE is to reprint those which has already majority which can be solved by removing the second condition in if() because its already done in the code up
        {
            printf("%s\n", candidates[c].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_vote = candidates[0].votes;
    for (int d = 0 ; d < g_argc - 1 ; d++)
    {
        if (candidates[d].eliminated == false && candidates[d].votes < min_vote)
        {
            min_vote = candidates[d].votes;
            printf("The minimum votes in round%i is %i\n", q+1, min_vote);
            return min_vote;              // MISTAKE is to find the minimum value before looking at the end of the loop
        }
    }
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // after running a loop if any value of candidate is greater than min(mininum value) then false is return i.e its not a tie
    bool loop = true;
    for (int e = 0 ; e < g_argc - 1 ; e++)
    {
        if (candidates[e].votes != min && candidates[e].eliminated == false)
        {
            loop = false;
        }
    }
    return loop;
}
// my is tie was not a good structure to start with



// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int f = 0 ; f < g_argc - 1 ; f++)
    {
        if (candidates[f].votes == min)                // MISTAKE is to re eliminating those candidates which are already eliminated
        {
            candidates[f].eliminated = true;
            eliminated_indexes[q] = f;
        }
    }

    return;
}