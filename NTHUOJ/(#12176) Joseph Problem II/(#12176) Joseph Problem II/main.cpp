//
//  main.cpp
//  (#12176) Joseph Problem II
//
//  Created by LeiHsiung on 2019/3/11.
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
    for(int i = 2; i <= n; i++)
    {
        Node* e = (Node*)malloc(sizeof(Node*));
        e->data = i;
        e->next = NULL;
        curr->next = e;
        curr = curr->next;
    }
    curr->next = head;
    
    return head;
}

void josephus(int n, int m,Node *head){
    Node* cur = head;
    while(n){
        Node *tmp=cur,
        *tmppar=cur;
        int t = m % n;
        
        for(int i = 0; i < t+1; i++){
            tmppar = tmp;
            tmp = tmp->next;
        }
        tmppar->next = tmp->next;
        cur = tmp->next;
        n--;
        if(tmp == cur) {
            sum += tmp->data;
            break;
        }
        free(tmp);
        tmp = NULL;
    }
    return;
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
        
        josephus(n, m, head);
        free_node(head);
    }
    cout << sum << endl;
    return 0;
}
