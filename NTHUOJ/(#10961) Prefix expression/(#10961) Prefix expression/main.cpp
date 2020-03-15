//
//  main.cpp
//  (#10961) Prefix expression
//
//  Created by Magic Bear on 2018/3/17.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include<iostream>
#include<cmath>
#include<string>

using namespace std;

struct Node{
    string data;
    int val;
    Node *left,*right;
};

void BuildTree(Node **head){
    string c;
    
    if((*head)==NULL)
    {
        (*head) = new Node();
        cin >> c;
        
        (*head)->data = c;
        
        (*head)->left = (*head)->right = NULL;
        
        if(   (*head)->left == NULL && ((*head)->data.compare("+")==0 || (*head)->data.compare("-")==0))
            BuildTree( &(*head)->left);
        if((*head)->right == NULL && ((*head)->data.compare("+")==0 || (*head)->data.compare("-")==0))
            BuildTree( &(*head)->right);
    }
}

void PrintInfix(Node* head){
    if(head == NULL) return;
    if(head->left!=NULL)
        PrintInfix(head->left);
    cout << head->data;
    if(head->right!=NULL)
        PrintInfix(head->right);
}

int Ans(Node* head){
    if(head->data.compare("+")==0)
        return Ans(head->left) + Ans(head->right);
    else if(head->data.compare("-")==0)
        return Ans(head->left) - Ans(head->right);
    else return stoi(head->data);
}

int main(){
    Node *head = NULL;
    BuildTree(&head);
    
    //cout << str;
    //PrintInfix(head);
    cout << Ans(head);
    
    return 0;
}

