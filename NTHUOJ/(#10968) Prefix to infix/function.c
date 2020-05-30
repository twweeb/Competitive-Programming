//
//  function.c
//  (#10968) Prefix to infix
//
//  Created by Magic Bear on 2017/10/6.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<stdio.h>
#include"function.h"
int isChar(char c){
    return c>='A' && c<='D';
}
void printInfix(Node *root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL)
        printInfix(root->left);
    printf("%c",root->data);
    if(root->right!=NULL){
        if(!isChar(root->right->data) && !isChar(root->data))
            printf("(");
        printInfix(root->right);
        if(!isChar(root->right->data) && !isChar(root->data))
            printf(")");
    }
}
