// SPELLER

// ** Remember to use help50 valgrind ./memory for debugging ** //

// Create an array of linked lists, each by letters A through Z

// CREATE LINKED LIST

typedef struct sllist
{
    VALUE val;
    struct sllist* next;
}
sllnode;

sllnode* create(VALUE val);
sllnode* new = create(6);

// INSERT NEW NODE INTO BEGINNING OF EXISTING LINKED LIST

sllnode* insert(sllnode* head, VALUE val);

// FOR HASH TABLE
// use internet to search for best hash function, cite your source

// RESOURCES

// https://www.learn-c.org/en/Linked_lists
// https://www.geeksforgeeks.org/linked-list-set-1-introduction/
// https://www.tutorialspoint.com/data_structures_algorithms/hash_table_program_in_c.htm
// https://www.quora.com/How-can-I-implement-a-dictionary-using-C
// https://www.geeksforgeeks.org/hashing-set-1-introduction/