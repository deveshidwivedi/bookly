#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "book_tree.h"
#include "hashmap.h"

// Forward declare
typedef struct BookHashMap BookHashMap; 
typedef struct UserHashMap UserHashMap;

// General Use Functions
char toUpperCase(char);

// Book Management Functions
void insertBook(BookHashMap*, Book*);
void deleteBook(BookHashMap*, char[]);
void userBookBorrow(UserHashMap*, char[], Book*);
void userBookReturn(UserHashMap*, char[]);

// User Management Functions
void insertUser(UserHashMap*, User*);
void deleteUser(UserHashMap*, char[]);

#endif