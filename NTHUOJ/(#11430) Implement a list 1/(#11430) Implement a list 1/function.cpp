//
//  function.cpp
//  (#11430) Implement a list 1
//
//  Created by Magic Bear on 2017/11/15.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//
#include<iostream>
#include "function.h"

oj::List::List(){
    begin_ = nullptr;
}

oj::List::~List(){
    if(begin_ != nullptr){
        Node *curr = begin_;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        while(curr->prev!=nullptr){
            curr = curr->prev;
            delete curr->next;
        }
        delete curr;
    }
}

void oj::List::erase(size_type pos){
    if(pos == 0){
        if(begin_->next!=nullptr){
            begin_ = begin_->next;
            delete begin_->prev;
            begin_->prev = nullptr;
        }
        else{
            delete begin_;
            begin_ = nullptr;
        }
        return;
    }
    Node *curr = begin_;
    for(size_type i = 0; i < pos ; i++)
        curr = curr->next;
    if(curr->next == nullptr){
        curr->prev->next = nullptr;
    }
    else{
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    delete curr;
}
void oj::List::insert(size_type pos,const_reference val){
    if(begin_ == nullptr){
        Node *e = new Node;
        e->data = val;
        e->prev = e->next = nullptr;
        begin_ = e;
        return;
    }
    Node *curr = begin_;
    Node *e = new Node;
    e->data = val;
    
    if(pos==0){
        curr->prev = e;
        e->next = curr;
        e->prev = nullptr;
        begin_ = e;
    }
    else{
        for(size_type i = 0; i < pos-1 ; i++){
            if(curr->next == nullptr) break;
            curr = curr->next;
        }
        if(curr->next != nullptr){
            curr->next->prev = e;
        }
        e->next = curr->next;
        e->prev = curr;
        curr->next = e;
    }
}
namespace oj{
    std::ostream& operator<<(std::ostream &os,const List &lst)
    {
        List curr = lst;
        while(curr.begin_!=nullptr){
            os << curr.begin_->data << ' ';
            curr.begin_ = curr.begin_->next;
        }
        return os;
    }
}
