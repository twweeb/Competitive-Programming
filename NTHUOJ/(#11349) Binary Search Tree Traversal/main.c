#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void create_tree(Node **root, int n);
void print_tree(Node *root);
void destroyTree(Node *root);

void insert(Node* root, int num){
    Node *e = (Node *)malloc(sizeof(Node));
    e->left = NULL;
    e->right = NULL;
    e->data = num;
    Node *curr = root,
         *par = NULL;
    while(curr!=NULL){
        par = curr;
        if(num == curr->data){
            free(e);
            return;
        }
        else if(num > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    if(num > par->data)par->right = e;
    else par->left = e;
}

void create_tree(Node **root, int n){
    int num;
    scanf("%d",&num);
    Node *e = (Node *)malloc(sizeof(Node));
    e->left = NULL;
    e->right = NULL;
    e->data = num;
    (*root) = e;
    n--;
    while(n>0){
        scanf("%d",&num);
        insert(*root,num);
        n--;
    }
}

void print_InOrder(Node *root){
    if(root->left!=NULL){
        print_InOrder(root->left);
    }
    printf(" %d",root->data);
    if(root->right!=NULL){
        print_InOrder(root->right);
    }
}
void print_PostOrder(Node *root){
    if(root->left!=NULL){
        print_PostOrder(root->left);
    }
    if(root->right!=NULL){
        print_PostOrder(root->right);
    }
    printf(" %d",root->data);
}
void print_PreOrder(Node *root){
    printf(" %d",root->data);
    if(root->left!=NULL){
        print_PreOrder(root->left);
    }
    if(root->right!=NULL){
        print_PreOrder(root->right);
    }
}
void print_tree(Node *root){
    printf("preorder:");
    print_PreOrder(root);
    printf("\ninorder:");
    print_InOrder(root);
    printf("\npostorder:");
    print_PostOrder(root);
    printf("\n");
}

void destroyTree(Node *root)
{
  if(root != NULL)
  {
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
  }
}
int main(void)
{
  int n;
  Node *root = NULL;
  scanf("%d",&n);
  create_tree(&root, n);
  print_tree(root);
  destroyTree(root);
  return 0;
}
