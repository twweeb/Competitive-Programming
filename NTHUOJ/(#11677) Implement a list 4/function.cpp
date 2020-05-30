//
//  function.cpp
//  (#11677) Implement a list 4
//
//  Created by Magic Bear on 2017/11/17.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>
#include"function.h"
using namespace std;
oj::List::List(){
    begin_ = nullptr;
}
oj::List::~List(){
    int count = 1;
    Node *curr = begin_;
    while(curr->next!=begin_){
        curr = curr->next;
        count++;
    }
    curr = begin_;
    for(int i = 1; i<=count ;i++){
        Node *e = curr;
        curr = curr->next;
        e->next = nullptr;
        e->prev = nullptr;
        delete e;
        e = nullptr;
    }
}

void oj::List::push_back(const_reference val){
    if(begin_ == nullptr){
        Node *e = new Node;
        e->data = val;
        e->prev = e->next = e;
        begin_ = e;
        return;
    }
    Node *e = new Node;
    e->data = val;
    e->next = begin_;
    e->prev = begin_->prev;
    begin_->prev->next = e;
    begin_->prev = e;
}
void oj::List::remove(const_reference val){
    if(begin_!=nullptr){
        Node *curr = begin_;
        while(curr->next!=begin_){
            if(curr->data == val){
                if(curr == begin_){
                    begin_ = curr->next;
                }
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
                Node *e = curr;
                curr = curr->next;
                delete e;
            }
            else{
                curr = curr->next;
            }
        }
        if(begin_->next == begin_ && begin_->data == val){
            delete begin_;
            begin_ = nullptr;
        }
        else if(curr->data == val){
            begin_->prev = curr->prev;
            curr->prev->next = begin_;
            delete curr;
        }
        if(begin_==nullptr) return;
    }
}
namespace oj{
    std::ostream& operator<<(ostream &os,const List &list)
    {
        oj::List::Node *curr = list.begin_;
        if(curr!=nullptr){
            os << curr->data << ' ';
            curr = curr->next;
            while(curr!=list.begin_)
            {
                os << curr->data << ' ';
                curr = curr->next;
            }
        }
        return os;
    }
}

