//
//  main.c
//  (#11486) Josephus Prob. using Circular Linked List (better)
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include<stdio.h>
#include "function.h"

int main(void){
    Node *head = NULL;
    int n,m;
    scanf("%d %d",&n, &m);
    head = create(n);
    josephus(m,head);
    free_node(head);
    
    /*
    Node *cur = head;
    printf("%d ",cur->data);
    cur = cur->next;
    while(cur != head){
        printf("%d ",cur->data);
        cur = cur->next;
    }
     */
    return 0;
}

