//
//  main.c
//  (#11602) Editor
//
//  Created by Magic Bear on 2017/10/19.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<cstdio>
#include<iostream>

using namespace std;

struct Node
{
    char c;
    Node* up;
    Node* down;
    Node* left;
    Node* right;
};

bool isChar(char c)
{
    if(c>='a' && c<='z') return true;
    else if(c>='A' && c<='Z') return true;
    else if(c>='0' && c<='9') return true;
    else if(c==' ' || c==',' || c=='.' || c=='!' || c=='?' || c=='(' || c==')') return true;
    else return false;
}

void Print(Node *head){
    Node *currCol,*currRow;
    currCol = currRow = head;
    while(currRow!=NULL){
        while(currCol!=NULL){
            if(isChar(currCol->c))
                cout << currCol->c;
            currCol = currCol->right;
        }
        cout << endl;
        currRow = currRow->down;
        currCol = currRow;
    }
}

int main(){
    char c;
    Node *head = new Node(),*curr = head;
    head->up = head->down = head->left = head->right = NULL;
    head->c ='_';
    while( (c=getchar())!=EOF ){
        if(c=='/'){
            cin >> c;
            if(c=='u'){
                int pos=0;
                Node *tmp = curr;
                while(curr->left!=NULL){
                    curr = curr->left;
                    pos++;
                }
                if(curr->up==NULL) curr = tmp;
                else{
                    curr = curr->up;
                    while(pos){
                        if(curr->right == NULL) break;
                        curr = curr->right;
                        pos--;
                    }
                }
            }
            else if(c=='d'){
                int pos=0;
                Node *tmp = curr;
                while(curr->left!=NULL){
                    curr = curr->left;
                    pos++;
                }
                if(curr->down==NULL) curr = tmp;
                else{
                    curr = curr->down;
                    while(pos){
                        if(curr->right == NULL) break;
                        curr = curr->right;
                        pos--;
                    }
                }
            }
            else if(c=='l'){
                if(curr->left != NULL)
                    curr = curr->left;
            }
            else if(c=='r'){
                if(curr->right != NULL)
                    curr = curr->right;
            }
            else if(c=='b'){
                if(curr!=NULL){
                    if(isChar(curr->c)){
                        Node *tmp = curr;
                        curr->left->right = curr->right;
                        if(curr->right!=NULL) curr->right->left = curr->left;
                        curr = curr->left;
                        delete tmp;
                    }
                }
            }
            else if(c=='n'){
                while(curr->left!=NULL)curr = curr->left;
                Node *e = new Node();
                e->c = '_';
                e->left = e->right = NULL;
                e->down = curr->down;
                if(curr->down!=NULL) curr->down->up = e;
                e->up = curr;
                curr->down = e;
                curr = e;
            }
            else{
                while(curr->right!=NULL)curr = curr->right;
                while(curr->left!=NULL){
                    curr = curr->left;
                    delete curr->right;
                    curr->right = NULL;
                }
                if(curr->up!=NULL || curr->down!=NULL){
                    if(curr->down == NULL){
                        curr = curr->up;
                        delete curr->down;
                        curr->down = NULL;
                        while(curr->right!=NULL)
                            curr = curr->right;
                    }
                    else{
                        Node *tmp = curr;
                        curr = curr->down;
                        if(tmp->up!=NULL)tmp->up->down = curr;
                        curr->up = tmp->up;
                        delete tmp;
                        while(curr->right!=NULL)curr = curr->right;
                    }
                }
                Node *Findhead = curr;
                while(Findhead->left!=NULL)Findhead = Findhead->left;
                while(Findhead->up!=NULL)Findhead = Findhead->up;
                head = Findhead;
            }
        }
        else{
          Node *e = new Node();
          e->c = c;
          e->up = e->down = NULL;
          e->right = curr->right;
          if(curr->right!=NULL) curr->right->left = e;
          e->left = curr;
          curr->right = e;
          curr = e;
        }
    }
    Print(head);
    return 0;
}
