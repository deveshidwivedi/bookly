#include "book_list.h"

void initBookList(BookList* start)
{
    start = NULL;
}

void insertBookList(BookList** start, Book* book) {
    // Create and attach new node
    BookList* newBook = (BookList*)malloc(sizeof(BookList));
    newBook->next = NULL;
    strcpy(newBook->bookName, book->name);

    if (*start == NULL) {
        *start = newBook;  // Update the start pointer if the list is empty
        return;
    }
    
    BookList* current = *start;

    // Find last node
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newBook;
}

void displayBookList(BookList* start) {
    BookList* current = start;
    while (current != NULL) {
        // Print the book name
        printf("%s", current->bookName);

        // If there is a next node, print '->'
        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }
    printf("\n");
}

void freeBookCatalog(BookList* start)
{
    BookList* temp = start;
    while(start != NULL){
        start = start->next;
        free(temp);
        temp = start;
    }
}
