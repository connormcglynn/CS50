// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Returns true if word is in dictionary else false


typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[26];

bool check(const char *word)
{
    // TODO (will be case-insensitive)
    // assume strings with only alphabetical chars and/or apostrophes
    // if word exists, it should be found in the hash bucket of it's first letter
        hashtable[hash(word)]

    node *cursor = node;
    while (cursor != NULL)
    {
        // TODO strcasecmp
        // search in that linked list if it exists
    }
    cursor = cursor->next;
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    while (fscanf(file, "%s", word) != EOF)
    {
        // malloc a node * for each new word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(new_node->word, word);
            new_node->next = head;
            head = new_node;
        }
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
