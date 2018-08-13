// SPELLER

// ** Remember to use help50 valgrind ./memory for debugging ** //

// Create an array of linked lists, each by letters A through Z
    // if word exists, it should be found in the hash bucket of it's first letter
        hashtable[hash(word)]

    // search in that linked list if it exists
        strcasecmp

// CREATE LINKED LIST

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[26];

node *node1 = malloc(sizeof(node));
node *node2 = malloc(sizeof(node));
strcopy(node1->word, "Hello");
strcopy(node2->word, "World");
node1->next = node2;

node *create(int val);
node *new = create(6);

node *cursor = node;
while (cursor != NULL)
    // TODO strcasecmp
    cursor = cursor->next;

// INSERT NEW NODE INTO BEGINNING OF EXISTING LINKED LIST

sllnode* insert(sllnode* HEAD, int val);

// FOR HASH TABLE
// use internet to search for best hash function, cite your source

// RESOURCES

// https://www.learn-c.org/en/Linked_lists
// https://www.geeksforgeeks.org/linked-list-set-1-introduction/
// https://www.tutorialspoint.com/data_structures_algorithms/hash_table_program_in_c.htm
// https://www.quora.com/How-can-I-implement-a-dictionary-using-C
// https://www.geeksforgeeks.org/hashing-set-1-introduction/