#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct _Node {
    int data;
    struct _Node *left, *right;
} Node;


// You need to implement these functions
void insert(Node **root, int key);
void deleteNode(Node **root, int key);


#endif