#include "book_tree.h"

// Actual implementation
int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLBook* createBookNode(Book* book) {
    AVLBook* newNode = (AVLBook*)malloc(sizeof(AVLBook));
    newNode->book = book;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getHeight(AVLBook* node) {
    if (node == NULL) return 0;
    return node->height;
}

void updateHeight(AVLBook* node) {
    if (node == NULL) return;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

int getBalanceFactor(AVLBook* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLBook* rightRotate(AVLBook* y) {
    AVLBook* x = y->left;
    AVLBook* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLBook* leftRotate(AVLBook* x) {
    AVLBook* y = x->right;
    AVLBook* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

void insertBookInTree(AVLBook** node, Book* book) {
    if (*node == NULL) {
        *node = createBookNode(book); // Set the new node directly
        printf("The book is now available in the library.\n");
        return;
    }

    int cmp = strcmp(book->name, (*node)->book->name);
    if (cmp < 0)
        insertBookInTree(&(*node)->left, book);  // Pass address of left child
    else if (cmp > 0)
        insertBookInTree(&(*node)->right, book);  // Pass address of right child
    else
        return; // Duplicate entries not allowed

    updateHeight(*node);

    int balance = getBalanceFactor(*node);

    // Left Left Case
    if (balance > 1 && strcmp(book->name, (*node)->left->book->name) < 0)
        *node = rightRotate(*node);

    // Right Right Case
    if (balance < -1 && strcmp(book->name, (*node)->right->book->name) > 0)
        *node = leftRotate(*node);

    // Left Right Case
    if (balance > 1 && strcmp(book->name, (*node)->left->book->name) > 0) {
        (*node)->left = leftRotate((*node)->left);
        *node = rightRotate(*node);
    }

    // Right Left Case
    if (balance < -1 && strcmp(book->name, (*node)->right->book->name) < 0) {
        (*node)->right = rightRotate((*node)->right);
        *node = leftRotate(*node);
    }
}

void deleteBookInTree(AVLBook** root, char bookName[]) {
    if (*root == NULL) return;

    int cmp = strcmp(bookName, (*root)->book->name);
    if (cmp < 0)
        deleteBookInTree(&(*root)->left, bookName);
    else if (cmp > 0)
        deleteBookInTree(&(*root)->right, bookName);
    else {
        // Node with only one child or no child
        if ((*root)->left == NULL || (*root)->right == NULL) {
            AVLBook* temp = (*root)->left ? (*root)->left : (*root)->right;

            if (temp == NULL) {
                free((*root)->book);  // Free the book data
                free(*root);  // Free the node itself
                *root = NULL;
            } else {
                **root = *temp;  // Copy contents of temp to root
                free(temp);
            }
        } else {
            // Node with two children: Get inorder successor
            AVLBook* temp = minValueNode((*root)->right);

            // Properly allocate memory and copy book contents
            Book* newBook = (Book*)malloc(sizeof(Book));
            if (newBook == NULL) {
                printf("Memory allocation failed\n");
                return;
            }
            *newBook = *(temp->book);  // Deep copy book data

            free((*root)->book);  // Free existing book data
            (*root)->book = newBook;  // Assign newly allocated book

            deleteBookInTree(&(*root)->right, temp->book->name);
        }
    }

    if (*root == NULL) return;

    // Update height and balance the AVL tree
    updateHeight(*root);

    int balance = getBalanceFactor(*root);

    // Balance the tree using AVL rotations
    if (balance > 1 && getBalanceFactor((*root)->left) >= 0)
        *root = rightRotate(*root);
    else if (balance > 1 && getBalanceFactor((*root)->left) < 0) {
        (*root)->left = leftRotate((*root)->left);
        *root = rightRotate(*root);
    } else if (balance < -1 && getBalanceFactor((*root)->right) <= 0)
        *root = leftRotate(*root);
    else if (balance < -1 && getBalanceFactor((*root)->right) > 0) {
        (*root)->right = rightRotate((*root)->right);
        *root = leftRotate(*root);
    }
}

AVLBook* minValueNode(AVLBook* node) {
    AVLBook* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Book* searchBookInTree(AVLBook* root, char bookName[]) {
    if (root == NULL) {
        return NULL;
    }
    
    int cmp = strcmp(bookName, root->book->name);
    if (cmp == 0) {
        return root->book;  // Return the found book
    } 
    else if (cmp < 0) 
        return searchBookInTree(root->left, bookName);  // Return recursive call result
    else 
        return searchBookInTree(root->right, bookName);  // Return recursive call result
}

void displayBookTree(AVLBook* root) { // inorder traversal
    if (root != NULL) {
        displayBookTree(root->left);
        printf("\tBook: %s\t", root->book->name);
        displayBookTree(root->right);
    }
}

void freeBookTree(AVLBook* root){
    if(root == NULL) return;

    freeBookTree(root->left);

    free(root->book);
    free(root);

    freeBookTree(root->right);
}