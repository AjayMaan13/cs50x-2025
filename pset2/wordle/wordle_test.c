#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
// a define is to give a constant value to a variable like here LISTSIZE has a constant value of 1000
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./wordle wordsize");
        return 0;
    }
    int wordsize = 0;

    wordsize = atoi(argv[1]);

    if (wordsize > 8 || wordsize < 5)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 0;
    }

    // open correct file, each file has exactly LISTSIZE words //
    char wl_filename[wordsize];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This is WORDLE50"RESET"\n");
    // This is how we give colours to a string
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // setting all elements of status array initially to 0, aka WRONG
        for(int j = 0 ; j < wordsize ; j++)
        {
            status[j] = 0;
        }

        // Calculate score for the guess
        int score_final = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score_final == EXACT * wordsize)
        {
            printf("You won!\n");
            won = true;
            break;
        }
    }

    // Printing the game's result

    printf("The actual word was: %s\n", choice);

    // End of the code
    return 0;
}

string get_guess(int wordsize)
{
    int length1 = wordsize;
    // ensuring users actually provide a guess that is the correct length
    string guess1;
    int length2 = 0;
    while (length2 == length1)
    {
        guess1 = get_string("Input a %i-letter word:", length1);
    }

    return guess1;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;

    // compare guess to choice and score points as appropriate, storing points in status

    int guess_length = strlen(guess);
    int choice_length = strlen(choice);

    for (int g =0 ; g < guess_length ; g++)
    {
        for (int c =0 ; c < choice_length ; c++)
        {
            if (guess[g] == choice[c])
            {
                if (g == c)
                {
                    score += EXACT;
                    status[g] = EXACT;
                }
                else
                {
                    score += CLOSE;
                    status[g] = CLOSE;
                }
            }

        }
    }

    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal

    for (int f =0 ; f < wordsize ; f++)
    {
        if (status[f] == 2)
        {
            printf(GREEN"This is WORDLE50"RESET"\n");
        }
        if (status[f] == 1)
        {
            printf(YELLOW"This is WORDLE50"RESET"\n");
        }
        else
        {
            printf(RED"This is WORDLE50"RESET"\n");
        }
    }

    printf("\n");
    return;
}
