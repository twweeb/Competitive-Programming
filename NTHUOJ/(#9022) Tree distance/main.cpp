//
//  main.cpp
//  (#9022) Tree distance
//
//  Created by Magic Bear on 2017/10/5.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int name;
    int level;
    Node* parent;
};

int FindDistance(Node* A, Node* B){
    if(B->name == A->name) return 0;
    if(A->level > B->level){
        return 1+FindDistance(A->parent, B);
    }
    else return 1+FindDistance(A, B->parent);
}

int main(){
    int j=1;
    int N;
    while(cin>>N){
        vector<Node*> handle;
        handle.push_back(NULL);
        Node *root;
        int i;
        for(i = 1; i <= N; i++){
            Node *e = new Node();
            e->name = i;
            e->parent = NULL;
            handle.push_back(e);
        }
        for(i = 1; i <= N;i++){
            int parent;
            cin >> parent;
            if(parent == -1) root = handle[i];
            else handle[i]->parent = handle[parent];
        }
        for(i = 1;i <= N; i++){
            Node* curr = handle[i];
            int level = 0;
            while(curr!=NULL){
                level++;
                curr = curr->parent;
            }
            handle[i]->level = level;
        }
        int n,m;
        cout << "Case " << j << ":";
        while(cin>>m>>n){
            if(m==0 && n==0) break;
            cout << " " << FindDistance(handle[m],handle[n]);
        }
        cout << endl;
        j++;
    }
    return 0;
}
