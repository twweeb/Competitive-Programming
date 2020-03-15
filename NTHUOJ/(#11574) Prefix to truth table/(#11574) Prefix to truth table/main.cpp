//
//  main.cpp
//  (#11574) Prefix to truth table
//
//  Created by Magic Bear on 2017/10/6.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//
/*
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int pos_now;
bool test[26];

struct Node{
    char c;
    Node *left;
    Node *right;
};

bool ischar(int c){
    return c>='A' && c<='Z';
}

Node* BuildTree(Node *root, int length, string str){
    if(pos_now == length) return NULL;
    Node *e = new Node();
    e->c = str[pos_now];
    e->left = e->right = NULL;
    pos_now++;
    if(ischar(e->c)) return e;
    else{
        e->left = BuildTree(e->left, length, str);
        e->right = BuildTree(e->right, length, str);
        return e;
    }
}

void PrintTree(Node *root){
    if(root->left != NULL)
        PrintTree(root->left);
    cout << root->c;
    if(root->right != NULL)
        PrintTree(root->right);
    
}

bool Ans(Node *root){
    if(root->c == '^')
        return Ans(root->left) ^ Ans(root->right);
    else if(root->c == '|')
        return Ans(root->left) | Ans(root->right);
    else if(root->c == '&')
        return Ans(root->left) & Ans(root->right);
    else
        return test[root->c - 'A'];
}

int main(){
    int num,length;
    string str;
    Node *root = NULL;
    cin >> num >> length >> str;
    pos_now = 0;
    root = BuildTree(root,length,str);
    //PrintTree(root);
    for(int i=0; i<pow(2,num); i++){
        int n = i;
        for(int j=0; j<num; j++){
            if(n%2 == 0) test[num-j-1] = false;
            else test[num-j-1] = true;
            n /= 2;
        }
        if(Ans(root)){
            for(int j=0; j<num ;j++){
                if (test[j]) cout << "1 ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
    return 0;
}
*/

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int pos_now;
bool text[26];

struct Node {
    Node *left,*right;
    char c;
};

bool isChar(char c){
    return 'A'<=c && 'Z'>=c;
}

Node* BuildTree(Node *root,int length,string str){
    if(pos_now==length)
        return NULL;
    Node *e = new Node();
    e->c = str[pos_now];
    e->left = e->right = NULL;
    pos_now++;
    
    if(isChar(e->c)){
        return e;
    }
    else{
        e->left = BuildTree(e->left,length,str);
        e->right = BuildTree(e->right,length,str);
        return e;
    }
}

void PrintTree(Node *root){
    if(root->left!=NULL)
        PrintTree(root->left);
    cout << root->c;
    if(root->right!=NULL)
        PrintTree(root->right);
}

bool ANS(Node *root){
    if(root->c == '&')
        return ANS(root->left) & ANS(root->right);
    else if(root->c == '|')
        return ANS(root->left) | ANS(root->right);
    else if(root->c == '^')
        return ANS(root->left) ^ ANS(root->right);
    else
        return text[root->c - 'A'];
}

int main(){
    int num,length;
    string str;
    pos_now = 0;
    cin >> num >> length >> str;
    Node *root = NULL;

    root = BuildTree(root,length,str);
    
    //PrintTree(root);
    int i = 0,j = 0;
    for(i = 0; i < pow(2,num); i++){
        int n = i;
        for(j = 0; j < num; j++){
            if(n%2==0) text[num-j-1] = false;
            else text[num-j-1] = true;
            n /= 2;
        }
        if(ANS(root)){
            for(j = 0;j<num;j++){
                if(text[j]) cout << "1 ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
