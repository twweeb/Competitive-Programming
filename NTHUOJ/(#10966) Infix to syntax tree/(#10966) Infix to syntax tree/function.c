//
//  function.c
//  (#10966) Infix to syntax tree
//
//  Created by Magic Bear on 2017/10/6.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
//#include"function.h"

BTNode* EXPR()
{
    char c;
    BTNode *node = NULL, *right=NULL;
    if(pos>=0)
    {
        right = FACTOR();
        if(pos>0)
        {
            c = expr[pos];
            if(c=='&'||c=='|')
            {
                node = makeNode(c);
                node->right = right;
                pos--;
                node->left = EXPR();
            }
            else node = right;
        }
        else node = right;
    }
    return node;
}

BTNode* FACTOR()
{
    BTNode *node = NULL;
    if(pos>=0)
    {
        char c = expr[pos--];
        if(c>='A' && c<='D') node = makeNode(c);
        else if(c==')')
        {
            node = EXPR();
            //if(expr[pos--]!='(') printf("error\n");
        }
    }
    return node;
}

BTNode* makeNode(char c)
{
    BTNode *e = malloc(sizeof(BTNode));
    int i;
    for(i=0 ; i<6 ; i++) if(sym[i]==c) e->data = i;
    e->left = NULL;
    e->right = NULL;
    return e;
}
