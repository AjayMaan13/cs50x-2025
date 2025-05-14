#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int create_array(string letter);
int points[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int main(void)
{

    string word1 = get_string("Player 1: ");

    int score1 = compute_score(word1);
    printf("The score of player1 is: %i\n", score1);
}

int compute_score(string word)
{
    int score =0;
    int b,i;
    char c;
    int len = strlen(word);

    for(i=0;i<len;i++)
    {
        c=toupper(word[i]);
        b= (int)c -65;
        if (b<=26 && b>=0)
        {
            score +=points[b];
        }
    }
    return score;
}

