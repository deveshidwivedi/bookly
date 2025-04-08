#ifndef BOOK_TREE_H
#define BOOK_TREE_H

#include<stdio.h>
#include "book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVLTree for books Structure
typedef struct AVLBook{
    Book* book;
    struct AVLBook* left;
    struct AVLBook* right;
    int height;
} AVLBook;
// Functions to perform Operations in the AVL tree
void insertBookInTree(AVLBook**, Book*);
void deleteBookInTree(AVLBook**, char[]);
Book* searchBookInTree(AVLBook*, char[]);
void displayBookTree(AVLBook*);
void freeBookTree(AVLBook*); // Also frees the book

// AVLTree Rebalancing Functions
 int max(int a, int b);
 AVLBook* minValueNode(AVLBook* node);
 int getBalanceFactor(AVLBook* node);
 void updateHeight(AVLBook* node);

#endif
