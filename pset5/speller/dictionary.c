// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define hashsize 199999

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// hashtable[hashsize]
node *hashtable[hashsize];

// wordcount
unsigned long wc = 0;

// hash function declaration
unsigned long hash(char *str);

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO (check for case-insensitivity)
    int length = strlen(word);
    char n[length + 1];
    n[length] = '\0';

    for (int i = 0; i < length; i++)
    {
        n[i] = tolower(word[i]);
    }

    int index = hash(n) % hashsize;
    node *cursor = hashtable[index];

    while (cursor != NULL)
    {
        // TODO strcmp
        // search in that linked list if word exists
        if (strcmp(n, cursor->word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fclose(file);
        return false;
    }

    // reset wordcount
    wc = 0;

    // set buffer
    char buffer[LENGTH + 1];

    // TODO
    while (fscanf(file, "%s", buffer) != EOF)
    {
        int length = strlen(buffer);
        if (buffer[length - 1] == '\n')
        {
            buffer[--length] = '\0';
        }

        unsigned int index = hash(buffer) % hashsize;

        // malloc a node * for each new word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(new_node->word, buffer);
        new_node->next = hashtable[index];
        hashtable[index] = new_node;
        wc++;

    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wc;
}

// Dan Bernstein's djb2 hash function via http://www.cse.yorku.ca/~oz/hash.html
unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < hashsize; i++)
    {
        node *next = hashtable[i];
        while (next != NULL)
        {
            node *f = next;
            next = next->next;
            free(f);
        }
    }


    wc = 0;
    return true;
}

