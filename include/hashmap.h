#ifndef HASHMAP_H
#define HASHMAP_H

#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
#include "book.h"
#include "book_tree.h"
#include "user.h"
#include "user_tree.h"

// BookMap struct: Key based on starting alphabet
typedef struct BookHashMap
{
    AVLBook* map[26];
} BookHashMap;

int hashFunction(char);

// Functions for BookMap
void initHashMap(BookHashMap*);
void insertBookInMap(BookHashMap*, Book*);
void listAllBooksInMap(BookHashMap*);
void listAllBooksInBucket(BookHashMap*, char);
Book* searchBookInBucket(BookHashMap*, char[]);
void freeHashMap(BookHashMap*);

// UserMap struct: Key based on starting alphabet
typedef struct UserHashMap
{
    AVLUser* map[26];
} UserHashMap;

// Functions for UserMap
void initUserHashMap(UserHashMap*);
void insertUserInMap(UserHashMap*, User*);
void listAllUsersInMap(UserHashMap*);
void listAllUsersInBucket(UserHashMap*, char);
User* searchUserInBucket(UserHashMap*, char[]);
void freeUserHashMap(UserHashMap*);

#endif