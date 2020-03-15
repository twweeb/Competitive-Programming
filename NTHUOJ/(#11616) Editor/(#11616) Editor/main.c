//
//  main.c
//  (#11616) Editor
//
//  Created by Magic Bear on 2017/11/3.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct _Node {
    struct _Node *left,*right;
    char data;
} Node;

void print(Node *head){
    while(head!=NULL){
        if(head->data!='_')
            printf("%c",head->data);
        head = head->right;
    }
}
int main(void) {
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = '_';
    head->right = head->left = NULL;
    Node *curr = head;
    char c;
    while((c = getchar())!=EOF){
        if(c == '/'){
            scanf("%c",&c);
            if(c == 'l'){
                if(curr->left != NULL)
                    curr = curr->left;
            }
            else if(c == 'r'){
                if(curr->right != NULL)
                    curr = curr->right;
            }
            else{
                if(curr->left!=NULL){
                    curr->left->right = curr->right;
                    if(curr->right!=NULL)
                        curr->right->left = curr->left;
                    free(curr);
                    curr = curr->left;
                }
            }
        }
        else{
            if(curr->right == NULL){
                Node *e = (Node *)malloc(sizeof(Node));
                e->data = c;
                e->left = curr;
                e->right = NULL;
                curr->right = e;
                curr = e;
            }
            else{
                Node *e = (Node *)malloc(sizeof(Node));
                e->data = c;
                e->left = curr;
                e->right = curr->right;
                curr->right->left = e;
                curr->right = e;
                curr = e;
            }
        }
    }
    print(head);
    return 0;
}
