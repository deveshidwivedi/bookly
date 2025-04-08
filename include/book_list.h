#ifndef BOOK_LIST_H
#define BOOK_LIST_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "book.h"

typedef struct Book Book;  // Forward declaration

typedef struct BookList
{
   struct BookList *next;
   char bookName[50];
} BookList;

void initBookList(BookList*);
void insertBookList(BookList**, Book*);
void displayBookList(BookList*);
void freeBookCatalog(BookList*);

#endif