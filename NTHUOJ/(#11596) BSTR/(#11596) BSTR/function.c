//
//  function.c
//  (#11596) BSTR
//
//  Created by Magic Bear on 2017/10/19.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include "function.h"
#include <stdlib.h>

void insert(Node **root, int key){
    if(*root == NULL){
        Node *e = malloc(sizeof(Node));
        e->data = key;
        e->left = e->right = NULL;
        *root = e;
    }
    if(key < (*root)->data) insert(&(*root)->left, key);
    if(key > (*root)->data) insert(&(*root)->right, key);
}
void deleteNode(Node **root, int key){
    if((*root)==NULL) return;
    if((*root)->data == key){
        if((*root)->left == NULL && (*root)->right != NULL){
            *root = (*root)->right;
        }
        else if((*root)->left != NULL && (*root)->right == NULL){
            *root = (*root)->left;
        }
        else if((*root)->left == NULL && (*root)->right == NULL){
            free(*root);
            (*root) = NULL;
        }
        else{
            Node *curr = (*root)->right,
                 *currpar = *root;
            while(curr->left!=NULL){
                currpar = curr;
                curr = curr->left;
            }
            if(currpar==*root){
                curr->left = (*root)->left;
                *root = curr;
            }
            else {
                currpar->left = curr->right;
                curr->left = (*root)->left;
                curr->right = (*root)->right;
                *root = curr;
            }
        }
        return;
    }
    if((*root)->data < key) deleteNode(&(*root)->right, key);
    if((*root)->data > key) deleteNode(&(*root)->left, key);
}
