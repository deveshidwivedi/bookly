#include "borrower_queue.h"

void initBorrowerQueue(Book* book)
{
    book->front = NULL;
    book->rear = NULL;
}

void enqueueUser(Book* book, User* user)
{
    BorrowerQueue* temp = (BorrowerQueue*)malloc(sizeof(BorrowerQueue));
    temp->user = user;
    temp->next = NULL;

    // Deal with underflow
    if(book->front == NULL){    
        book->front = temp;
        book->rear = temp;
    } else{
        book->rear->next = temp;
        book->rear = temp;
    }
}

void dequeueUser(Book* book)
{
    // Deal with underflow (empty queue case)
    if (book->front == NULL) {
        printf("No users currently in the queue!\n");
        return;
    }

    BorrowerQueue* temp = book->front;
    book->front = book->front->next;

    // If the queue becomes empty, set rear to NULL
    if (book->front == NULL) {
        book->rear = NULL;
    }

    free(temp);
}

void displayBorrowerQueue(Book* book)
{
    BorrowerQueue* temp = book->front;

    if (temp == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    printf("<----- Borrower's Queue ----->\n");
    while(temp != NULL){
        printf("%s-->\t", temp->user->name);
        temp = temp->next;
    }
    printf("END\n");
}