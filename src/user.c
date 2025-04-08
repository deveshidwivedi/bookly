#include "user.h"

// Function to create a new user record
void initUser(User** user){
    initBookList((*user)->bookCatalogStart);
    (*user)->book = NULL;
    (*user)->hasTakenBook = false;
    
    printf("Enter Name: ");
    fgets((*user)->name, sizeof((*user)->name), stdin);
    (*user)->name[strcspn((*user)->name, "\n")] = '\0';  // Remove newline

    printf("Enter Address: ");
    fgets((*user)->address, sizeof((*user)->address), stdin);
    (*user)->address[strcspn((*user)->address, "\n")] = '\0';
    printf("\n");
}

// Function to display the history of books the user has read
void displayCatalog(User* user){
    displayBookList(user->bookCatalogStart);
}

// Function to display user
void displayUserInfo(User* user){
    printf("<----- User Info ----->\n");
    printf("Name: %s\n", user->name);
    printf("Address: %s\n", user->address);
    printf("Book taken: %s\n", (user->hasTakenBook ? "Yes" : "No"));

    if(user->hasTakenBook){
        printf("Book: %s\n", user->book->name);
    }
    printf("\n <----- User's Book Catalog ----->\n");
    displayCatalog(user);
}

char getInitialUserChar(User* user) {
    return user->name[0];  
}
