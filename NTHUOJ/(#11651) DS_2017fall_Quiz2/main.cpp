//
//  main.cpp
//  (#11651) DS_2017fall_Quiz2
//
//  Created by Magic Bear on 2018/4/16.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class List{
public:
    struct Node
    {
        int data;
        Node* prev;
        Node* next;
    };
    List();
    ~List();
    void insert_back(int data);
    void insert_after(int data1, int data2);
    void delete_node(int data);
    void reverse();

private:
    Node *begin_;
    Node *end_;
};

List::List()
{
    begin_ = nullptr;
    end_ = new Node;
    end_->prev = end_->next = nullptr;
}

List::~List()
{
    if(begin_==nullptr){
        delete end_;
        end_ = nullptr;
        return;
    }
    Node *curr = begin_;
    while(curr!=nullptr){
        Node *e = curr;
        curr = curr->next;
        delete e;
        e->prev = e->next = nullptr;
    }
}

void List::insert_back(int data)
{
    if(begin_==nullptr)
    {
        begin_ = new Node;
        begin_->prev = end_;
        begin_->next = end_;
        end_->prev = begin_;
        end_->next = begin_;
        begin_->data = data;
        return;
    }
    Node *e = new Node;
    e->next = end_;
    e->prev = end_->prev;
    end_->prev->next = e;
    end_->prev = e;
    e->data = data;
}

void List::insert_after(int data1, int data2)
{
    if(begin_==nullptr) return;
    Node *curr = begin_;
    while(curr!=end_)
    {
        if(curr->data == data1) break;
        curr = curr->next;
        if(curr==end_) return;
    }
    
    if(curr==begin_)
    {
        Node *e = new Node;
        e->data = data2;
        e->next = begin_;
        e->prev = end_;
        begin_->prev = e;
        end_->next = e;
        begin_ = e;
        return;
    }
    Node *e = new Node;
    e->data = data2;
    e->next = curr->next;
    e->prev = curr;
    curr->next->prev = e;
    curr->next = e;
    return;
    
}

void List::delete_node(int data)
{
    if(begin_==nullptr) return;
    Node *curr = begin_;
    while(curr!=end_)
    {
        if(curr->data == data) break;
        curr = curr->next;
        if(curr==end_) return;
    }
    if(curr==begin_)
    {
        if(curr->next == end_)
        {
            delete begin_;
            begin_ = nullptr;
            end_->next = end_->prev = nullptr;
            return;
        }
        Node *e = begin_->next;
        e->prev = end_;
        end_->next = e;
        delete begin_;
        begin_ = e;
        return;
    }
    
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    curr = nullptr;
    return;
}

void List::reverse()
{
    if(begin_==nullptr) return;
    Node *curr = begin_;
    end_->next = end_->prev;
    end_->prev = begin_;
    while(curr!=end_){
        Node *e = curr->next;
        curr->next = curr->prev;
        curr->prev = e;
        curr = e;
    }
    begin_ = end_->next;
}

int main(int argc, const char * argv[]) {
    int N = 2;
    while(N--){
        int M = 0;
        cin >> M;
        string command ="";
        List lst1,lst2;
        
        while(M--){
            string str = "";
            cin >> command;
            if(command == "InsertBack")
            {
                
            }
            else if(command == "InsertAfter")
            {
                
            }
            else if(command == "Reverse")
            {
                
            }
        }
    }
    return 0;
}
