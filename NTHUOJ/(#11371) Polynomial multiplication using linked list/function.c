#include<stdio.h>
#include<stdlib.h>
#include "function.h"

void printNode(Node* head){         //the function which will print the output
    while(head!=NULL){
        if(head->data != 0)
        printf(" %ld %d",head->data, head->power);
        head = head->next;
    }
}
Node* create(){                     //create polynomial linked list
    int i=1;
    Node *head = NULL;
    Node *curr = NULL;
    while(i>=0){
        Node *e = malloc(sizeof(Node));
        scanf("%ld %d",&e->data ,&e->power);
        if(head == NULL){
            e->prev = NULL;
            e->next = NULL;
            curr = head = e;
        }
        else{
            if(curr->power == e->power && curr != NULL){
                curr->data += e->data;
                i++;
            }
            else{
                e->prev = curr;
                e->next = NULL;
                curr->next = e;
                curr = e;
            }
        }
        i = e->power - 1;
    }
    return head;
}
void destroy(Node *node){           //destroy polynomial linked list
    Node* tmp;
    while (node != NULL){
        tmp = node;
        node = node->next;
        free(tmp);
    }
}
Node* multiple(Node* p1, Node* p2){ //input two polynomial linked list and return the result
    Node* mul=NULL;
    Node* curr = malloc(sizeof(Node));
    curr->data = 0;
    curr->power = 0;
    curr->next = curr->prev = NULL;
    Node* p1curr = p1;
    Node* p2curr = p2;
    int LeadPower = p1->power + p2->power;
    int i=LeadPower;
    /*while(p1curr!=NULL){
        while(p2curr!=NULL){
            int j = p1curr->power + p2curr->power;
            if(mul==NULL){
                curr->data = p1curr->data * p2curr->data;
                curr->power = j;
                curr->next = curr->prev = NULL;
                mul = curr;
            }
            else if(curr->power == j){
                curr->data += p1curr->data * p2curr->data;
            }
            else{
                curr = mul;
                for(i = LeadPower; i > j+1; i--){
                    curr = curr->next;
                }
                Node* e = malloc(sizeof(Node));
                e->data = p1curr->data * p2curr->data;
                e->power = j;
                e->prev = curr;
                e->next = NULL;
                curr->next = e;
                curr = e;
            }
            p2curr = p2curr->next;
        }
        p2curr = p2;
        p1curr = p1curr->next;
    }
    */
    
    while(i>=0){
        while(p1curr!=NULL){
            int j = p1curr->power;
            while(p2curr!=NULL){
                int k = p2curr->power;
                if(i == (j+k)){
                    if(curr->power == i){
                        curr->data += p1curr->data * p2curr->data;
                    }
                    else{
                        Node* e = malloc(sizeof(Node));
                        e->data = p1curr->data * p2curr->data;
                        e->power = i;
                        if(mul==NULL){
                            e->prev = NULL;
                            e->next = NULL;
                            mul = curr =  e;
                        }
                        else{
                            e->prev = curr;
                            e->next = NULL;
                            curr->next = e;
                            curr = e;
                        }
                    }
                    break;
                }
                p2curr = p2curr->next;
            }
            p2curr = p2;
            p1curr = p1curr->next;
        }
        p1curr = p1;
        if(mul==NULL){
            Node* e = malloc(sizeof(Node));
            e->data = 0;
            e->power = i;
            e->prev = NULL;
            e->next = NULL;
            mul = curr =  e;
        }
        else if(curr->power != i){
            Node* e = malloc(sizeof(Node));
            e->data = 0;
            e->power = i;
            e->prev = curr;
            curr->next = e;
            curr = e;
        }
        i--;
    }
    return mul;
}

