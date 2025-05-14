#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int count_letters(string word);
int count_words(string word);
int count_sentences(string word);


int main(void)
{
    string input = get_string("Text: ");

    int L = count_letters(input);
    int W = count_words(input);
    int S = count_sentences(input);
    int f;

//    printf("Number of letters is: %i\n",count_letters(input));
//    printf("Number of words is: %i\n",count_words(input));
//    printf("Number of sentences is: %i\n",count_sentences(input));

    float index = round(0.0588 * (L*100.0/W) - 0.296 * (S*100.0/W) - 15.8);
    f= (int) index;
    if ( f >= 16)
    {
        printf("Grade 16+\n");
    }
    if ( f < 1 )
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", f);
    }

}

int count_letters(string word)
{
    int s = 0;
    int i;
    int len = strlen(word);
    for(i = 0 ; i < len ; i++)
    {
 //       if ((int)word[i] == 34 || (int)word[i] == 39 || word[i] == '/' || word[i] == '!' || word[i] == '@' || word[i] == ' '
 //       || word[i] == '#' || word[i] == '$' || word[i] == '%' || word[i] == '^' || word[i] == '&' || word[i] == '*'
//        || word[i] == '(' || word[i] == ')' || word[i] == '-' || word[i] == '{' || word[i] == '}' || word[i] == '['
//        || word[i] == ']' || word[i] == ':' || word[i] == ';' || word[i] == '"'
//        || word[i] == '<' || word[i] == '>' || word[i] == '.' || word[i] == '?' || word[i] == '~' || word[i] == '`')
        if( islower(word[i]) || isupper(word[i]) )
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
    for( j = 0; j<len;j++)
    {
        if (word[j] == ' ')
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
    for (k=0;k<len;k++)
    {
        if ( word[k] == '.' || word[k] == '!' || word[k] == '?' )
        {
            s++;
        }
    }
    return s;
}