//
//  main.cpp
//  (#11184) A Naughty Boy
//
//  Created by Magic Bear on 2018/4/16.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class List{
public:
    struct Node{
        char data;
        Node* next;
        Node* prev;
    };
    List();
    ~List();
    Node* insert_back(Node *curr,char c);
    Node* move_back(Node *curr);
    Node* move_forth(Node *curr);
    void print();
private:
    Node* begin_;
    Node* top_;
};

List::List()
{
    begin_ = nullptr;
    top_ = new Node;
    top_->next = top_->prev = nullptr;
}

List::~List()
{
    if(begin_==nullptr)
    {
        return;
    }
    else
    {
        Node* curr = begin_;
        while(curr!=nullptr)
        {
            Node *e = curr;
            curr = curr->next;
            delete e;
            e->prev = e->next = nullptr;
        }
    }
}

List::Node* List::insert_back(List::Node *curr, char c)
{
    if(begin_==nullptr)
    {
        begin_ = new Node;
        begin_->next = nullptr;
        begin_->prev = nullptr;
        begin_->data = c;
        top_->next = begin_;
        top_->prev = nullptr;
        begin_->prev = top_;
        
        return begin_;
    }
    
    if(curr->next==nullptr)
    {
        Node *e = new Node;
        e->prev = curr;
        e->next = nullptr;
        e->data = c;
        curr->next = e;
        return e;
    }
    if(curr==top_)
    {
        Node *e = new Node;
        e->prev = top_;
        e->next = begin_;
        e->data = c;
        curr->next = e;
        begin_->prev = e;
        begin_ = e;
        return e;
    }
    Node *e = new Node;
    e->prev = curr;
    e->next = curr->next;
    e->data = c;
    curr->next->prev = e;
    curr->next = e;
    return e;
}

List::Node* List::move_forth(List::Node *curr)
{
    if(begin_ == nullptr) return nullptr;
    if(curr->next == nullptr) return curr;
    return curr->next;
}

List::Node* List::move_back(List::Node *curr)
{
    if(begin_ == nullptr) return nullptr;
    if(curr == top_) return top_;
    return curr->prev;
}

void List::print()
{
    Node *curr = begin_;
    while(curr!=nullptr)
    {
        cout << curr->data;
        curr = curr->next;
    }
}

int main(int argc, const char * argv[]) {
    string str = "";
    cin >> str;
    size_t length = str.length();
    List lst;
    List::Node *curr = nullptr;
    for(size_t i = 0; i < length; i++)
    {
        switch(str[i])
        {
            case '>' :
                curr = lst.move_forth(curr);
                break;
            case '<' :
                curr = lst.move_back(curr);
                break;
            default:
                curr = lst.insert_back(curr, str[i]);
                break;
        }
    }
    lst.print();
    return 0;
}
