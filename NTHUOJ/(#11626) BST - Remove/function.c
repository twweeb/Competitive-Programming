//
//  function.c
//  (#11626) BST - Remove
//
//  Created by Magic Bear on 2017/10/25.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "function.h"
void deleteNode(Node **root, int key){
    if((*root)==NULL)
        return;
    else if((*root)->data==key){
        if((*root)->left==NULL && (*root)->right==NULL){
            free(*root);
            *root = NULL;
        }
        else if((*root)->left==NULL && (*root)->right!=NULL){
            *root = (*root)->right;
        }
        else if((*root)->left!=NULL && (*root)->right==NULL){
            *root = (*root)->left;
        }
        else{
            Node *curr = (*root)->right;
            Node *currPar = *root;
            while(curr->left!=NULL){
                currPar = curr;
                curr = curr->left;
            }
            curr->left = (*root)->left;
            if(currPar != *root){
                currPar->left = curr->right;
                curr->right = (*root)->right;
            }
            *root = curr;
        }
        return;
    }
    else if((*root)->data < key)
        deleteNode(&((*root)->right), key);
    else if((*root)->data > key)
        deleteNode(&((*root)->left), key);
}
