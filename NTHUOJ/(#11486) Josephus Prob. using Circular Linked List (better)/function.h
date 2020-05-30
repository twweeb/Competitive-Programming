//
//  function.h
//  (#11486) Josephus Prob. using Circular Linked List (better)
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct node{
    int data;
    struct node *next;
}Node;

Node* create(int n);
void josephus(int m,Node *head);
void free_node(Node *head);

#endif

