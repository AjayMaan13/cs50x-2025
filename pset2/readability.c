#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h> // For the use of round functin in the code

//All 3 function created in the code
int count_letters(string word); // count the number of letters in the text
int count_words(string word);  // count the nummber of words in the text
int count_sentences(string word); // count the number of sentences in the text


int main(void)
{
    string input = get_string("Text: "); // main text input

    int L = count_letters(input);
    int W = count_words(input);
    int S = count_sentences(input);
    int f;

    // The main line of the code where the final work is done of calculating the grade
    float index = round(0.0588 * (L * 100.0 / W) - 0.296 * (S * 100.0 / W) - 15.8);
    f = (int) index;
    if (f >= 16)
    {
        // if the grade outcome is more than 16
        printf("Grade 16+\n");
        return 0;
        // return 0; indicate the ending of the code, when this line is executed the main code ends and goes no further
    }
    if (f < 1)
    {
        // when grade is below 1
        printf("Before Grade 1\n");
        return 0;
    }
    else
    {
        // Places for the rest of the grade form 1 to 16
        printf("Grade %i\n", f);
        return 0;
    }

}

int count_letters(string word)
{
    int s = 0;
    int i;
    int len = strlen(word);
    for (i = 0 ; i < len ; i++)
    {

        if (islower(word[i]) || isupper(word[i]))
// islower and isupper is used here to identify only uppercase and lowercase words
        {
            s++;
        }

    }
    return s;
}

int count_words(string word)
{
    int w = 1;
    int j;
    int len = strlen(word);
    for (j = 0; j < len ; j++)
    {
        if (word[j] == ' ')
// In this function the method used is to find the number of spaces in the code and finding the number of words
        {
            w++;
        }
    }
    return w;
}

int count_sentences(string word)
{
    int s = 0;
    int k;
    int len = strlen(word);
    for (k = 0 ; k < len ; k++)
    {
        if (word[k] == '.' || word[k] == '!' || word[k] == '?')
// Here . ! and ? are counted as ending of a code and hence counting the number of sentences
        {
            s++;
        }
    }
    return s;
}