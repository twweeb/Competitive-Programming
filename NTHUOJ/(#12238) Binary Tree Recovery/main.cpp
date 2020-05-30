//
//  main.cpp
//  (#12238) Binary Tree Recovery
//
//  Created by LeiHsiung on 2019/5/4.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>

using namespace std;

int n = 0;

struct Node {
    int data;
    Node *left, *right;
};

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = nullptr;
    return (node);
}

Node* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex){
    if (inStrt > inEnd) return nullptr;
    
    Node* node = newNode(post[*pIndex]);
    (*pIndex)--;
    
    if (inStrt == inEnd)
        return node;
    
    int iIndex = search(in, inStrt, inEnd, node->data);
    
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
    
    return node;
}

Node* buildTree(int in[], int post[], int n){
    int pIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
}

void preOrder(Node* node){
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


void printPostOrder(int in[], int pre[], int n)
{
    int root = search(in, 0, n, pre[0]);
    if (root != 0)
        printPostOrder(in, pre + 1, root);
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    cout << pre[0] << " ";
}

void pre_in_to_post(){
    cin >> n;
    int *pre = (int*)malloc(n*sizeof(int*)),
    *in = (int*)malloc(n*sizeof(int*));
    
    for(int i = 0; i< n; i++){
        cin >> pre[i];
    }
    for(int i = 0; i< n; i++){
        cin >> in[i];
    }
    printPostOrder(in, pre, n);
    delete pre;
    delete in;
}

void post_in_to_pre(){
    cin >> n;
    int *post = (int*)malloc(n*sizeof(int*)),
    *in = (int*)malloc(n*sizeof(int*));
    
    for(int i = 0; i< n; i++){
        cin >> post[i];
    }
    for(int i = 0; i< n; i++){
        cin >> in[i];
    }
    Node* root = buildTree(in, post, n);
    preOrder(root);
    delete post;
    delete in;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    pre_in_to_post();
    cout << endl;
    post_in_to_pre();
    cout << endl;
    return 0;
}
