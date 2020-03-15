//
//  function.c
//  (#11486) Josephus Prob. using Circular Linked List (better)
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include "function.h"
#include <stdio.h>
#include <stdlib.h>

Node* create(int n){
    Node* head = malloc(sizeof(Node*));
    head->data = 1;
    Node* curr = head;
    for(int i = 2;i<n;i++)
    {
        Node* e = malloc(sizeof(Node*));
        e->data = i;
        e->next = NULL;
        curr->next = e;
        curr = curr->next;
    }
    Node* e = malloc(sizeof(Node*));
    e->data = n;
    e->next = head;
    curr->next = e;
    
    return head;
}

void josephus(int m,Node *head){
    Node* cur = head;
    int i;
    while(1){
        Node *tmp=cur,*tmppar=cur;
        for(i = 1;i<m;i++){
            tmppar = tmp;
            tmp = tmp->next;
        }
        tmppar->next = tmp->next;
        cur = tmp->next;
        printf("%d",tmp->data);
        if(tmp == cur) {
            printf("\n");
            break;
        }
        else printf(" ");
        free(tmp);
        tmp = NULL;
    }
}

void free_node(Node *head){
    
}
