#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//In this code we are using the principle of ascii number in order to find the index value of an alphabet i.e 'a' as 0 and so on

// These are the function used in this program.
int compute_score(string word);
int create_array(string letter);
string result(int a, int b);  // it calculates the final result of the scrabble game.
// points array is the point system we will use in which each points represent an alphabet.
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Now we will take in the string inputs
    string word1 = get_string("Player 1 choose a word: ");
    string word2 = get_string("Player 2 choose a word: ");
    //Calculating scores
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    string final_result = result(score1, score2);
    //Printing scores
    printf("%s\n", final_result);

}

// Funciton to calculate the score of a give code
int compute_score(string word)
{
    int score = 0;
    int b, i;
    char c;
    int len = strlen(word);

    // Main functioning loop here which calculates the score
    for (i = 0 ; i < len ; i++)
    {
        c = toupper(word[i]);
        b = (int)c - 65;  // The most important part wher we convert each char in acii and then deduct 65, hence, making a as 0 and so on
        if (b <= 26 && b >= 0)
        {
            score += points[b];
        }
    }
    return score;
}

string result(int a, int b)
{
    // a simple if else statements to check which is bigger and smaller
    string r;
    if (a == b)
    {
        r = "Tie!";
        return r;
    }
    if (a > b)
    {
        r = "Player 1 wins!";
        return r;
    }
    else
    {
        r = "Player 2 wins!";
        return r;
    }
}