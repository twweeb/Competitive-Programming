#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct _Node {
    int data;
    struct _Node *left, *right;
} Node;


// You need to implement this function
void deleteNode(Node **root, int key);


#endif
