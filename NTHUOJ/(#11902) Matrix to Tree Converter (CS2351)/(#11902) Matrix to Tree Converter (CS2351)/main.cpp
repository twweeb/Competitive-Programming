//
//  main.cpp
//  (#11902) Matrix to Tree Converter (CS2351)
//
//  Created by Magic Bear on 2018/5/5.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <vector>
//#include <queue>

using namespace std;

#define MAXN 100
int mat[MAXN][MAXN];
vector<int> vec;
int W = 0, H = 0, S_W = 0, S_H = 0;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* up;
    Node* down;
};

class Queue{
public:
    // Constructor
    Queue (int queueCapacity = 10);
    ~Queue();
    // Check if the stack is empty
    bool IsEmpty();
    // Return the front element
    Node* Front();
    // Return the rear element
    void Push(Node* x);
    Node* queue;
    int front, rear; // init. value = -1
private:
    int capacity;
};


Queue::Queue(int queueCapacity){
    queue = (Node*) malloc((queueCapacity)*sizeof(Node*));
    capacity = queueCapacity;
    front = rear = 0;
}

Queue::~Queue(){
    
}

bool Queue::IsEmpty(){ return front==rear; }

Node* Queue::Front(){
    //if(IsEmpty()) throw "Queue is empty!";
    Node * e = &queue[(++front)%capacity];
    front = front%capacity;
    return e;
}

void Queue::Push (Node* x)
{ // Add x at rear of queue
    if(x==nullptr) return;
    if((rear+1)%capacity == front)
    {// queue is going to full, double the capacity!
        Node* e = (Node*) malloc((2*capacity)*sizeof(Node*));
        int cur = front,i = 0;
        while((cur+1)%capacity!=front)
        {
            e[i++] = queue[(++cur)%capacity];
        }
        queue = e;
        capacity*=2;
    }
    rear = (rear+1)%capacity;
    queue[rear] = *x;
}

void init(){
    cin >> W >> H >> S_W >> S_H;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> mat[i][j];
            //cout << mat[i][j] << ' ';
        }
        //cout << endl;
    }
    vec.clear();
}

void preOrder(Node *root)
{
    if(root==nullptr) return;
    vec.push_back(root->data);
    preOrder(root->left);
    preOrder(root->down);
    preOrder(root->right);
    preOrder(root->up);
}

void postOrder(Node *root)
{
    if(root==nullptr) return;
    postOrder(root->left);
    postOrder(root->down);
    postOrder(root->right);
    postOrder(root->up);
    vec.push_back(root->data);
}

void levelOrder(Node *root)
{
    if(root==nullptr) return;
    Queue q;
    q.Push(root);
    while (!q.IsEmpty()) {
        Node *cur = q.Front();
        if(cur==nullptr) continue;
        vec.push_back(cur->data);
        q.Push(cur->left);
        q.Push(cur->down);
        q.Push(cur->right);
        q.Push(cur->up);
    }
}

Node* create(Node** root, int x, int y, char dir){
    if(!mat[x][y] || x>=H || x<0 || y>=W || y<0) return nullptr;
    *root = new Node();
    (*root)->up = (*root)->down = (*root)->left = (*root)->right = nullptr;
    (*root)->data = mat[x][y];
    //cout << x << " " << y << ": " << mat[x][y] << endl;
    //cout << x << " "<< y << endl;
    if(dir!='u') (*root)->down = create(&(*root)->down,x+1,y,'d');
    if(dir!='d') (*root)->up = create(&(*root)->up,x-1,y,'u');
    if(dir!='l') (*root)->right = create(&(*root)->right, x, y+1, 'r');
    if(dir!='r') (*root)->left = create(&(*root)->left, x, y-1, 'l');
    return *root;
}

int main(int argc, const char * argv[]) {
    int N;// = 0;
    cin >> N;
    //cout << N;
    while(N--){
        init();
        Node *root = nullptr;
        //cout << mat[S_H][S_W] <<endl;
        root = create(&root,S_H,S_W,'t');
        string str;
        cin >> str;
        if(str[0]=='L') levelOrder(root);
        else if(str[1]=='r') preOrder(root);
        else postOrder(root);
        for(int i=0 ; i<vec.size() ; ++i)
        {
            if(i!=0) cout << ' ';
            cout << vec[i];
        }
        cout << endl;
    }
    return 0;
}
