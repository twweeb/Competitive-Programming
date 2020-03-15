//
//  function.cpp
//  (#11719) Implement a list 6 (operator new)
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include "function.h"
#include <iostream>

oj::List::Node* oj::List::new_Node_(){
    begin_ = static_cast<Node*>(operator new [] (sizeof(Node)));
    begin_->next = begin_->prev = begin_;
    return begin_;
}

oj::List::Node* oj::List::new_Node_(const_reference val){
    new_Node_();
    begin_->data = val;
    return begin_;
}

void oj::List::delete_Node_(Node *node){
    delete node;
    node = nullptr;
}

oj::List::List(){
    new_Node_();
}

oj::List::List(const List &rhs){
    begin_ = new_Node_(rhs.begin_->data);
    Node *Cur = rhs.begin_->next, *thisCur=begin_;
    
    while(Cur!=rhs.begin_){
        Node *e = new_Node_(Cur->data);
        e->prev = thisCur;
        e->next = begin_;
        thisCur->next = begin_->prev = e;
        thisCur = e;
        Cur = Cur->next;
    }
}

oj::List& oj::List::operator=(const List &rhs){
    if(this->begin_!=nullptr) operator delete [] (this->begin_);
    this->begin_ = new_Node_(rhs.begin_->data);
    Node *Cur = rhs.begin_->next, *thisCur=this->begin_;
    while(Cur!=rhs.begin_){
        Node *e = new_Node_(Cur->data);
        e->prev = thisCur;
        e->next = begin_;
        thisCur->next = begin_->prev = e;
        thisCur = e;
        Cur = Cur->next;
    }
    return *this;
}

oj::List::~List(){
    delete begin_;
    begin_ = nullptr;
}

oj::List::reference oj::List::back(){
    return begin_->prev->data;
}

oj::List::const_reference oj::List::back() const{
    return begin_->prev->data;
}

oj::List::reference oj::List::front(){
    return begin_->data;
}

oj::List::const_reference oj::List::front() const{
    return begin_->data;
}

void oj::List::clear(){
    delete begin_;
    begin_ = new_Node_();
}

void oj::List::erase(size_type pos){
    Node *Cur = begin_;
    for(int i = 0; i< pos;i++)Cur = Cur->next;
    Cur->prev->next = Cur->next;
    Cur->next->prev = Cur->prev;
    delete Cur;
    Cur = nullptr;
}

void oj::List::insert(size_type pos,const_reference val){
    Node *Cur = begin_;
    for(int i = 0; i< pos;i++)Cur = Cur->next;
    Node *e = new_Node_(val);
    Cur->prev->next = e;
    e->prev = Cur->prev;
    e->next = Cur;
    Cur->prev = e;
}

std::ostream& oj::operator<<(std::ostream &os,const List &lst){
    List::Node *Cur = lst.begin_;
    os << Cur->data << " ";
    Cur = Cur->next;
    while(Cur!=lst.begin_)
    {
        os << Cur->data << " ";
        Cur = Cur->next;
    }
    return os;
}
