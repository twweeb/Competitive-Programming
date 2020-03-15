//
//  main.cpp
//  (#12293) AVL Tree Insertion
//
//  Created by LeiHsiung on 2019/6/1.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> vec;
class AVLTree;

class Node{
public:
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int key): key(key), right(nullptr), left(nullptr), height(1) {};
    
    friend class AVLTree;
};

int getheight(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

class AVLTree{
private:
    Node *root;
public:
    AVLTree();
    Node* rotateL(Node* x);
    Node* rotateR(Node* x);
    int balance(Node* x);
    Node* insert(Node* x, int key);
    void insertkey(int key);
    void print_LevelOrder();
    void DestroyRecursive(Node* node);
    ~AVLTree();
};

AVLTree::AVLTree()
{
    root = nullptr;
}

void AVLTree::DestroyRecursive(Node* node)
{
    if (node)
    {
        DestroyRecursive(node->left);
        DestroyRecursive(node->right);
        delete node;
    }
}

AVLTree::~AVLTree()
{
    DestroyRecursive(root);
}

Node* AVLTree::rotateL(Node* x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return y;
}

Node* AVLTree::rotateR(Node* y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    return x;
}

int AVLTree::balance(Node* N)
{
    if (N == NULL) return 0;
    return getheight(N->left) - getheight(N->right);
}

Node* AVLTree::insert(Node* x, int key)
{
    if (x == NULL) return new Node(key);
    
    if (key < x->key)
        x->left = insert(x->left, key);
    else if (key > x->key)
        x->right = insert(x->right, key);
    else
        return x;
    
    x->height = 1 + max(getheight(x->left), getheight(x->right));
    
    int bal = balance(x);
    
    if (bal > 1 && key < x->left->key) return rotateR(x);
    if (bal < -1 && key > x->right->key) return rotateL(x);
    if (bal > 1 && key > x->left->key)
    {
        x->left = rotateL(x->left);
        return rotateR(x);
    }
    if (bal < -1 && key < x->right->key)
    {
        x->right = rotateR(x->right);
        return rotateL(x);
    }
    return x;
}

void AVLTree::insertkey(int key)
{
    root = insert(root, key);
}

void AVLTree::print_LevelOrder(){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();
        if(cur==nullptr) continue;
        vec.push_back(cur->key);
        q.push(cur->left);
        q.push(cur->right);
    }
}

int main(int argc, const char * argv[]) {
    int T, N, key;
    
    cin >> T;
    while(T--)
    {
        AVLTree tre;
        cin >> N;
        while(N--){
            cin >> key;
            tre.insertkey(key);
        }
        tre.print_LevelOrder();
        for(int i = 0; i < vec.size(); i++){
            if(i != 0) cout << " ";
            cout << vec[i];
        }
        cout << endl;
        vec.clear();
    }
    return 0;
}
