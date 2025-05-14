// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//Size of the dictionary
int size_dict = 0;

const unsigned int N = (26 * 26) - 1;

// Hash table
node *table[N];


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary folder");
        return false;
    }

    //String for recieving words
    char word_dict[LENGTH + 1];
    while (fscanf(file, "%s", word_dict) != EOF)
    {
        //Finding index of the word
        int index_hash = hash(word_dict);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        //Copying the scanned word from file to node
        strcpy(n -> word, word_dict);
        size_dict++;
        n -> next = NULL;

        // Prepend node
        n -> next = table[index_hash];
        table[index_hash] = n;
    }
    fclose(file);

    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word_spell)
{
    // Finding Index of the word
    int index_check = hash(word_spell);
    node *check_node = table[index_check];

    //Checking if the node in table is empty or linked
    while ((check_node -> word) != 0x00)
    {
        //strcasecmp compares word regardless if they are uppercase or lowercase
        if (strcasecmp(word_spell, check_node -> word) == 0)
        {
            return true;
        }
        // Moving to next linked node
        else
        {
            check_node = check_node -> next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int index_zero = toupper(word[0]) - 'A';
    int final;
    int length_word = strlen(word);
    // For multi character word
    if (length_word > 1)
    {
        int index_one = toupper(word[1]) - 'A';
        final = 25 * index_zero + index_one;
        return final;
    }
    else
    {
        final = 26 * index_zero;
        return final;
    }

}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return size_dict;
}

// Unloads dictionary from memory, returning true if successful, else false

bool unload(void)
{
    for (int i = 0; i < N ; i++)
    {
        // Check if the table[i] is already empty
        while (table[i] != NULL)
        {
            //moving curser to the next node
            node *tmp = table[i] ->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}