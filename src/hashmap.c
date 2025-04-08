#include "hashmap.h"

int hashFunction(char key)
{
    key = toUpperCase(key);

    // Reduce the key into the range (0 - 25) for characters (A - Z)
    key -= 'A';

    // In this way, every alphabet can go into it's respective bucket of our map_ array
    return (key % 26);
}

void initHashMap(BookHashMap* hashmap)
{
    // Initialize the trees
    for(int i = 0; i < 26; i++){
        hashmap->map[i] = NULL;
    }
}

void insertBookInMap(BookHashMap* hashmap, Book* book)
{
    // HashMap needs to be allocated in main and sent over
    char key = getInitialBookChar(book);
    int value = hashFunction(key);

    insertBookInTree(&hashmap->map[value], book);
}

void listAllBooksInMap(BookHashMap* hashmap)
{
    int counter = 0; // To count if there are no books in the library
    for(int i = 0; i < 26; i++){
        counter++;

        if(hashmap->map[i] == NULL){
            continue;
        }

        printf("\n");
        printf("For books starting from letter %c:\n", i + 'A');

        displayBookTree(hashmap->map[i]);
        printf("\n");
    }

    if(counter == 0){
        printf("Currently no books in the library!");
    }

    printf("\n\n");
}

void listAllBooksInBucket(BookHashMap* hashmap, char letter){
    int value = hashFunction(letter);

    if(hashmap->map[value] == NULL){
        printf("No books in that bucket!");
        return;
    }
    displayBookTree(hashmap->map[value]);
};

Book* searchBookInBucket(BookHashMap* hashmap, char bookName[])
{
    int value = hashFunction(bookName[0]);

    return searchBookInTree(hashmap->map[value], bookName);
}

void freeHashMap(BookHashMap* hashmap)
{
    // Free all the buckets associated with the hashmap
    for(int i = 0; i < 26; i++){
        printf("\n");

        if(hashmap->map[i] == NULL){
            continue;
        }

        freeBookTree(hashmap->map[i]);

        printf("\n\n");
    }

    // Free Hashmap after freeing all the buckets
    free(hashmap);
}


// <------ UserHashMap Section ----->

void initUserHashMap(UserHashMap* hashmap)
{
    // Initialize the trees
    for(int i = 0; i < 26; i++){
        hashmap->map[i] = NULL;
    }
}

void insertUserInMap(UserHashMap* hashmap, User* user)
{
    // HashMap needs to be allocated in main and sent over
    char key = getInitialUserChar(user);
    int value = hashFunction(key);

    insertUserInTree(&hashmap->map[value], user);
}

void listAllUsersInMap(UserHashMap* hashmap)
{
    int counter = 0; // To count if there are no books in the library
    for(int i = 0; i < 26; i++){
        counter++;

        if(hashmap->map[i] == NULL){
            continue;
        }

        printf("\n");
        printf("For user names starting from letter %c:\n", i + 'A');

        displayUserTree(hashmap->map[i]);
        printf("\n");
    }

    if(counter == 0){
        printf("Currently no users registered in the library!");
    }

    printf("\n\n");
}

User* searchUserInBucket(UserHashMap* hashmap, char userName[])
{
    int value = hashFunction(userName[0]);

    return searchUserInTree(hashmap->map[value], userName);
}

void freeUserHashMap(UserHashMap* hashmap)
{
    // Free all the buckets associated with the hashmap
    for(int i = 0; i < 26; i++){
        printf("\n");

        if(hashmap->map[i] == NULL){
            continue;
        }

        freeUserTree(hashmap->map[i]);

        printf("\n\n");
    }

    // Free Hashmap after freeing all the buckets
    free(hashmap);
}