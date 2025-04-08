#ifndef BOOK_H
#define BOOK_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "borrower_queue.h"

// Forward declare
typedef struct BorrowerQueue BorrowerQueue;

typedef struct Book
{
    int yearOfPublication;
    char name[50];
    char genre[50];
    char author[50];
    bool isAvailable;
    BorrowerQueue* front;
    BorrowerQueue* rear;
} Book;

void initBook(Book**);
void displayBookInfo(Book*);
char getInitialBookChar(Book*);

#endif