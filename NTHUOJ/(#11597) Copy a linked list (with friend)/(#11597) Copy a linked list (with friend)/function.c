//
//  function.c
//  (#11597) Copy a linked list (with friend)
//
//  Created by Magic Bear on 2017/10/17.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include"function.h"

Node* copy(Node *head){
    Node *temp[100000];
    Node *fritemp[100000];
    Node *copy = malloc(sizeof(Node));
    Node *curr = head;
    Node *cptemp = copy;
    int i=0;
    while(curr!=NULL){
        temp[i]=curr;
        curr->id = i;

        fritemp[i]=cptemp;
        cptemp->fri = NULL;
        cptemp->id = curr->id;
        cptemp->next = malloc(sizeof(Node));
        if(curr->next==NULL)
            cptemp->next = NULL;
        else
            cptemp = cptemp->next;
        curr = curr->next;
        
        i++;
    }
    curr = head;
    cptemp = copy;
    while(curr!=NULL){
        if(curr->fri != NULL){
            unsigned long id = curr->fri->id;
            cptemp->fri = fritemp[id];
        }
        curr = curr->next;
        cptemp = cptemp->next;
    }
    return copy;
}
