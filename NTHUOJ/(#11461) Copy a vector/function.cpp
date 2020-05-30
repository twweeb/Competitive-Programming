//
//  function.cpp
//  (#11461) Copy a vector
//
//  Created by Magic Bear on 2017/12/4.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>
#include"function.h"

using namespace std;

oj::Vector::Vector(){
    begin_ = end_ = last_ = nullptr;
}
oj::Vector::~Vector(){
    if(capacity()>0)
        operator delete [] (begin_);
    begin_ = last_ = end_ = nullptr;
}
oj::Vector::Vector(const oj::Vector &vec){
    if(vec.size()==0){
        begin_ = last_ = end_ = nullptr;
        return;
    }
    begin_ = static_cast<pointer>(operator new [] (vec.size()*sizeof(value_type)));
    for(size_type i = 0;i<vec.size();i++){
        new (begin_+i) value_type(vec[i]);
    }
    last_ = end_ = begin_+vec.size();
}
oj::Vector& oj::Vector::operator=(const Vector &vec){
    size_type new_s = vec.size(),
              new_c = max(this->capacity(), vec.size());
    pointer A = static_cast<pointer>(operator new [] (new_c*sizeof(value_type)));
    for(size_type i = 0;i<new_s;i++)
        new (A+i) value_type(vec[i]);
    operator delete [] (this->begin_);
    this->begin_ = A;
    this->last_ = this->begin_+new_s;
    this->end_ = this->begin_+new_c;
    return *this;
}

void oj::Vector::erase(size_type pos){
    if(pos<size()){
        for(size_type i = pos;i<size()-1;i++){
            begin_[i] = begin_[i+1];
        }
        last_--;
    }
}
void oj::Vector::insert(size_type pos,const_reference val){
    if(pos<=size()){
        if(size()==capacity()){
            size_type new_c = max(capacity()*3,capacity()+1),old_s = size();
            pointer A = static_cast<pointer>(operator new [] (new_c*sizeof(value_type)));
            
            if(capacity()>0){
                for(size_type i = 0;i<old_s;i++)
                    new (A+i) value_type(begin_[i]);
                operator delete [] (begin_);
            }
            
            begin_ = A;
            last_ = begin_+old_s;
            end_ = begin_+new_c;
        }
        new (begin_+size()) value_type("");
        for(size_type i = size();i>pos;i--){
            begin_[i] = begin_[i-1];
        }
        new (begin_+pos) value_type(val);
        last_++;
    }
}
void oj::Vector::reserve(size_type new_capacity){
    if(new_capacity>capacity()){
        size_type old_s = size();
        pointer A = static_cast<pointer>(operator new [] (new_capacity*sizeof(value_type)));
        if(capacity()>0){
            for(size_type i = 0;i<old_s;i++)
                new (A+i) value_type(begin_[i]);
            operator delete [] (begin_);
        }
        begin_ = A;
        last_ = begin_+old_s;
        end_ = begin_+new_capacity;
    }
}
