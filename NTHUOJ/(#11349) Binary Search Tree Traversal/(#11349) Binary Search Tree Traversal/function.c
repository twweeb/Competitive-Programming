//
//  function.c
//  (#11349) Binary Search Tree Traversal
//
//  Created by Magic Bear on 2017/10/6.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//
#include<stdio.h>
#include"function.h"

void insert(Node *root, int val)
{
    Node e = (Node)malloc(sizeof(Node));
    e->data = val;
    e->left = NULL;
    e->right = NULL;
    Node *curr = root, *par = NULL;
    while(curr!=NULL)
    {
        par = curr;
        if(curr->data==val)
        {
            free(e);
            return;
        }
        else if(curr->data>val) curr = curr->left;
        else curr = curr->right;
    }
    if(par->data>val) par->left = e;
    if(par->data<val) par->right = e;
}

void create_tree(Node **root, int n)
{
    if(n==0) return;
    Node e = (Node)malloc(sizeof(Node));
    int val;
    scanf("%d",&val);
    e->data = val;
    e->left = NULL;
    e->right = NULL;
    n--;
    *root = e;
    while(n>0)
    {
        scanf("%d",&val);
        insert(*root,val);
        n--;
    }
}

void preorder(Node *root)
{
    if(root==NULL) return;
    printf(" %d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf(" %d",root->data);
    inorder(root->right);
}

void postorder(Node *root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d",root->data);
}

void print_tree(Node *root)
{
    printf("preorder:");
    preorder(root);
    printf("\n");
    printf("inorder:");
    inorder(root);
    printf("\n");
    printf("postorder:");
    postorder(root);
    printf("\n");
}
