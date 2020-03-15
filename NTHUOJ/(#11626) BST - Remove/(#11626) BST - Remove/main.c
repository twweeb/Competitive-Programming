#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* new_node(int key)
{
    Node* node = malloc(sizeof(Node));
    node->data = key;
    node->left = node->right = NULL;

    return node;
}

Node* insert(Node* root, int key)
{
    if(root == NULL)
        return new_node(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    else   
        root->right = insert(root->right, key);
    
    return root;
}

void inorder_print(Node* root)
{
    if(root == NULL)
        return;

    inorder_print(root->left);
    printf("%d ", root->data);
    inorder_print(root->right);
    free(root);
}


int main()
{
    int N, temp;
    Node* root = NULL;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &temp);
        root = insert(root, temp);
    }

    while(scanf("%d", &temp) != '-') {
        deleteNode(&root, temp);
    }
    
    //deleteNode(&root, 12);
    //deleteNode(&root, 16);
    
    inorder_print(root);

    return 0;

}
