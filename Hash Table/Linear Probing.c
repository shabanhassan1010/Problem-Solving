#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

struct HashTable 
{
    int table[TABLE_SIZE];
    int size;
};

void InitializeHashTable(struct HashTable* ht)
{
    ht->size = TABLE_SIZE;
    for (int i = 0; i < ht->size; i++) 
    {
        ht->table[i] = -1;    // -1 indicates an empty slot
    }
}

int hashFunction(int key) 
{
    return key % TABLE_SIZE; 
}

// Function to insert a key into the hash table using linear probing
void Insert(struct HashTable* ht, int key) 
{
    int index = hashFunction(key);

    // Linear probing to find the next available slot
    while (ht->table[index] != -1) 
    {
        index = (index + 1) % TABLE_SIZE; // Move to the next slot >> El index hna mmoken increase more than one to gwt the empty index
    }

    // Insert the key into the hash table
    ht->table[index] = key;
}

int Search(struct HashTable* ht, int key) 
{
    int index = hashFunction(key); // Get the hash index

    for(int i = 0 ; i < TABLE_SIZE ; i++)
    {
        if(ht->table[index] == key)
        return index;   

        if(ht->table[index] == -1)
        {
        break;
        }
        index = (index + 1 )% TABLE_SIZE;
    }
    return -1 ;

}

void Delete(struct HashTable* ht, int key) 
{
    int index = hashFunction(key); // Get the hash index

    // Linear probing to find the key
    while (ht->table[index] != -1) 
    {
        if (ht->table[index] == key) 
        {
            ht->table[index] = -1; // Mark the slot as empty
            printf("Key %d deleted from index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE; // Move to the next slot
    }

    printf("Key %d not found in the hash table\n", key);
}

void Display(struct HashTable* ht) 
{
    printf("Hash Table:\n");
    for (int i = 0; i < ht->size; i++) 
    {
        printf("Index %d: ", i);
        if (ht->table[i] != -1) 
        {
            printf("%d", ht->table[i]);
        } 
        else 
        {
            printf("Empty");
        }
        printf("\n");
    }
}

int main() 
{
    struct HashTable ht;
    InitializeHashTable(&ht); // Initialize the hash table

    Insert(&ht, 5);
    Insert(&ht, 15);
    Insert(&ht, 25);
    Insert(&ht, 35);
    Insert(&ht, 7);

    Display(&ht);

    int key = 15;
    int result = Search(&ht, key);
    if (result != -1) 
    {
        printf("Key %d found at index %d\n", key, result);
    } 
    else 
    {
        printf("Key %d not found in the hash table\n", key);
    }

    Delete(&ht, 15);
    Display(&ht);

    return 0;
}




























