#ifndef USER_TREE_H
#define USER_TREE_H

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_list.h"
#include "user.h"

// AVLTree for books Structure
typedef struct AVLUser{
    User* user;
    struct AVLUser* left;
    struct AVLUser* right;
    int height;
} AVLUser;

// Functions to perform Operations in the AVL tree
void insertUserInTree(AVLUser**, User*);
void deleteUserInTree(AVLUser**, char[]);
User* searchUserInTree(AVLUser*, char[]);
void displayUserTree(AVLUser*);
void freeUserTree(AVLUser*); // Also frees the book

// AVLTree Rebalancing Functions
int maxUser(int a, int b);
AVLUser* minValueNodeUser(AVLUser* node);
int getBalanceFactorUser(AVLUser* node);
void updateHeightUser(AVLUser* node);

#endif