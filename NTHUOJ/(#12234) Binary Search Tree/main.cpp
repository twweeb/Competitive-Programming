//
//  main.cpp
//  (#12234) Binary Search Tree
//
//  Created by LeiHsiung on 2019/5/2.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void insert(Node* root, int num){
    //cout << "insert " << num << endl;
    Node *e = new Node();
    e->left = nullptr;
    e->right = nullptr;
    e->data = num;
    Node *curr = root,
    *par = nullptr;
    while(curr!=nullptr){
        par = curr;
        if(num == curr->data){
            delete e;
            e = nullptr;
            return;
        }
        else if(num > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    if(num > par->data)par->right = e;
    else par->left = e;
}

void delete_node(Node** root, int num){
    Node *cur = *root, *par = nullptr;
    bool isLeft = true;
    while(cur!=nullptr && cur->data!=num)
    {
        par = cur;
        if(num < cur->data)
        {
            isLeft = true;
            cur = cur->left;
        }
        else
        {
            isLeft = false;
            cur = cur->right;
        }
    }
    if(cur!=nullptr)
    {
        if(cur->left==nullptr&&cur->right==nullptr)
        {
            if(par==nullptr){
                *root = nullptr;
            }else if(isLeft){
                par->left = nullptr;
            }else{
                par->right = nullptr;
            }
        }
        else if(cur->left==nullptr&&cur->right!=nullptr)
        {
            if(par==nullptr){
                *root = cur->right;
            }else if(isLeft){
                par->left = cur->right;
            }else{
                par->right = cur->right;
            }
        }
        else if(cur->left!=nullptr&&cur->right==nullptr)
        {
            if(par==nullptr){
                *root = cur->left;
            }else if(isLeft){
                par->left = cur->left;
            }else{
                par->right = cur->left;
            }
        }
        else
        {
            Node *succesor = cur->right, *succesor_par = nullptr;
            while(succesor->left!=nullptr)
            {
                succesor_par = succesor;
                succesor = succesor->left;
            }
            if(par==nullptr){
                *root = succesor;
            }else if(isLeft){
                par->left = succesor;
            }else{
                par->right = succesor;
            }
            if(succesor==cur->right)
            {
                succesor->left = cur->left;
            }
            else
            {
                succesor_par->left = succesor->right;
                succesor->left = cur->left;
                succesor->right = cur->right;
            }
            
        }
        delete cur;
        cur = nullptr;
    }
}

void create_tree(Node **root){
    int num,n;
    cin >> n >> num;
    Node *e = new Node();
    e->left = nullptr;
    e->right = nullptr;
    e->data = num;
    (*root) = e;
    n--;
    while(n>0){
        cin >> num;
        insert(*root,num);
        n--;
    }
    cin >> n;
    while(n--){
        cin >> num;
        delete_node(root, num);
    }
}

void print_PreOrder(Node *root){
    if(root!=nullptr)
    {
        cout << root->data << " ";
        print_PreOrder(root->left);
        print_PreOrder(root->right);
    }
}

void destroyTree(Node *root)
{
    if(root != nullptr)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
        root = nullptr;
    }
}

int main(int argc, const char * argv[]) {
    Node *root = nullptr;
    create_tree(&root);
    print_PreOrder(root);
    cout << endl;
    destroyTree(root);
    return 0;
}
