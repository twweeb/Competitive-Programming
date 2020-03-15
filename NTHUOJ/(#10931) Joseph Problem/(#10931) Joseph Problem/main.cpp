//
//  main.cpp
//  (#10931) Joseph Problem
//
//  Created by LeiHsiung on 2019/3/8.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>

using namespace std;

int sum = 0;

typedef struct node{
    int data;
    struct node *next;
}Node;

Node* create(int n){
    Node* head = (Node*)malloc(sizeof(Node*));
    head->data = 1;
    Node* curr = head;
    for(int i = 2; i < n; i++)
    {
        Node* e = (Node*)malloc(sizeof(Node*));
        e->data = i;
        e->next = NULL;
        curr->next = e;
        curr = curr->next;
    }
    Node* e = (Node*)malloc(sizeof(Node*));
    e->data = n;
    e->next = head;
    curr->next = e;
    
    return head;
}

void josephus(int m,Node *head){
    Node* cur = head;
    while(1){
        Node *tmp=cur,
            *tmppar=cur;
        
        for(int i = 0; i < m+1; i++){
            tmppar = tmp;
            tmp = tmp->next;
        }
        tmppar->next = tmp->next;
        cur = tmp->next;
        if(tmp == cur) {
            sum += tmp->data;
            break;
        }
        free(tmp);
        tmp = NULL;
    }
}

void free_node(Node *head){
    if(head == nullptr) return;
    //delete head;
    head = nullptr;
}

int main(int argc, const char * argv[]) {
    Node *head = nullptr;
    int N = 0,n = 0,m = 0;
    cin >> N;
    while(N--)
    {
        cin >> n >> m;
        head = create(n);
        josephus(m, head);
        free_node(head);
    }
    cout << sum << endl;
    return 0;
}

