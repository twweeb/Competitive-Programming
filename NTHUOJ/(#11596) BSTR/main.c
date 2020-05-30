#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *left, *right;
} Node;

Node* new_node(int key)
{
    Node* node = malloc(sizeof(Node));
    node->data = key;
    node->left = node->right = NULL;

    return node;
}

void insert(Node **root,int num){
    if((*root)==NULL){
        Node *e = new_node(num);
        (*root) = e;
        return;
    }
    else if(num < (*root)->data)
        insert(&((*root)->left),num);
    else
        insert(&((*root)->right),num);
}

void deleteNode(Node **root,int key){
    if((*root)==NULL)
        return;
    if((*root)->data==key){
        if((*root)->left == NULL && (*root)->right == NULL){
            free(*root);
            *root = NULL;
        }
        else if((*root)->left == NULL && (*root)->right != NULL){
            *root = (*root)->right;
        }
        else if((*root)->left != NULL && (*root)->right == NULL){
            *root = (*root)->left;
        }
        else {
            Node *curr = (*root)->right,
            *currPar = *root;
            while(curr->left!=NULL){
                currPar = curr;
                curr = curr->left;
            }
            if(currPar == *root){
                curr->left = (*root)->left;
                *root = curr;
            }
            else {
                curr->left = (*root)->left;
                currPar->left = curr->right;
                curr->right = (*root)->right;
                *root = curr;
            }
        }
    }
    else if((*root)->data > key)
        deleteNode(&((*root)->left), key);
    else
        deleteNode(&((*root)->right), key);
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
    int N, temp, a, b;
    Node* root = NULL;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &temp);
        insert(&root, temp);
    }

    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; i++)
        deleteNode(&root, i);

    inorder_print(root);

    return 0;

}
