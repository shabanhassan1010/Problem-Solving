#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct HashTable 
{
    int size;
    struct Node** table;
};

struct Node* CreateNode(int key) 
{
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = key;
    NewNode->next = NULL;
    return NewNode;
}

int hashFunction(int key) 
{
    return key % 10; 
}

struct Node* search(struct Node* temp, int key) 
{
    while (temp != NULL) 
    {
        if (temp->data == key) {
            return temp; // Key found
        }
        temp = temp->next;
    }
    return NULL; // Key not found
}

// Function to insert a key into the linked list in sorted order
void SortedInsert(struct Node** head, int key) 
{
    struct Node* temp = CreateNode(key);
    struct Node* current;

    // If the list is empty or the new key is smaller than the head
    if (*head == NULL || (*head)->data >= key) {
        temp->next = *head;
        *head = temp;
    } 
    else 
    {
        // Traverse the list to find the correct position
        current = *head;
        // The smallest one will make it the last node, and it will also check if there is a node in the linkedList; 
        // it will keep going as long as there is one.
        while (current->next != NULL && current->next->data < key)  
        {
            current = current->next;
        }
        // Insert the new node
        temp->next = current->next;
        current->next = temp;
    }
}

void InsertkeyInHashTable(struct HashTable* ht, int key) 
{
    int index = hashFunction(key); // Get the hash index
    SortedInsert(&(ht->table[index]), key); // Insert the key in sorted order
}

// Function to create a hash table
struct HashTable* CreateHashTable(int size) 
{
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->size = size;
    ht->table = (struct Node**)malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; i++)
    {
        ht->table[i] = NULL; // Initialize all linked lists to NULL
    }
    return ht;
}


void Display(struct HashTable* ht) 
{
    for (int i = 0; i < ht->size; i++) 
    {
        printf("Index %d: ", i);
        struct Node* temp = ht->table[i];
        while (temp != NULL) 
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable* ht = CreateHashTable(10); // Create a hash table of size 10

    InsertkeyInHashTable(ht, 5);
    InsertkeyInHashTable(ht, 15);
    InsertkeyInHashTable(ht, 25);
    InsertkeyInHashTable(ht, 35);
    InsertkeyInHashTable(ht, 7);

    Display(ht);

    // Search for a key
    int key = 15;
    struct Node* res = search(ht->table[hashFunction(key)], key);
    if (res != NULL) 
    {
        printf("%d is found in the hash table.\n", key);
    } 
    else 
    {
        printf("%d is not found in the hash table.\n", key);
    }


    return 0;
}