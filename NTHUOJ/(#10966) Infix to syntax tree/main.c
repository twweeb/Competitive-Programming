//
//  main.c
//  (#10966) Infix to syntax tree
//
//  Created by Magic Bear on 2017/10/5.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
unsigned long pos;   // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR(void);
BTNode* FACTOR(void);
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

int main(void){
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    while (scanf("%s", expr)!=EOF)
    {
        pos = strlen(expr) - 1;
        BTNode *root = EXPR();
        printPrefix(root);
        printf("\n");
        freeTree(root);
    }
    
    return 0;
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// EXPR = FACTOR | EXPR OP FACTOR
// FACTOR = ID | (EXPR)

BTNode *EXPR(void){
    BTNode *node = NULL,
           *right = NULL;
    if(pos>=0){
        right = FACTOR();
        if(pos>0){
            char c = expr[pos];
            if(c == '&' || c== '|'){
                node = makeNode(c);
                node->right = right;
                pos--;
                node->left = EXPR();
            }
            else
                node = right;
        }
        else
            node = right;
    }
    return node;
}

BTNode *FACTOR(void){
    BTNode *node = NULL;
    if(pos>=0){
        char c = expr[pos--];
        if(c == ')'){
            node = EXPR();
            if(expr[pos--]!='(')
                printf("error!\n");
        }
        else if(c>='A' && c<='D'){
            node = makeNode(c);
        }
    }
    return node;
}

BTNode *makeNode(char c){
	BTNode *e = (BTNode *)malloc(sizeof(BTNode));
    e->right = e->left = NULL;
    int i;
    for(i = 0;i < 6;i++)
        if(sym[i]==c)
            e->data = i;
    
    return e;
}
