//
//  function.cpp
//  (#11410) Implement a vector 2
//
//  Created by Magic Bear on 2017/11/13.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//
/*
#include<iostream>
#include"function.h"

using namespace std;

oj::Vector::Vector()
{
    begin_ = end_ = last_ = nullptr;
}

oj::Vector::~Vector()
{
    if(capacity()>0) delete [] begin_;
    begin_ = last_ = end_ = nullptr;
}

size_t oj::Vector::size() const
{
    if(last_==nullptr)return 0;
    else return (last_ - begin_) + 1;
}

size_t oj::Vector::capacity() const
{
    if(end_==nullptr) return 0;
    else return (size_t)(end_ - begin_ )+ 1;
}

void oj::Vector::pop_back()
{
    if(size()==1)
        last_ = nullptr;
    else if(size()>1)
        last_ = &begin_[size()-2];
}

void oj::Vector::push_back(data_t val)
{
    if(size()==capacity()){
        size_t new_c = max(capacity()+1,capacity()*3),old_s = size();
        data_t *A = new data_t[new_c];
        if(capacity()>0){
            for(size_t i = 0; i <size(); i++)A[i] = begin_[i];
            delete [] begin_;
        }
        begin_ = A;
        last_ = &begin_[old_s-1];
        end_ = &begin_[new_c-1];
    }
    begin_[size()] = val;
    last_ = &begin_[size()];
}

void oj::Vector::insert(size_t pos, size_t count, data_t val)
{
    if((size()+count)>capacity()){
        size_t new_c = max(capacity() + capacity()/2,capacity()+count),old_s = size();
        data_t *A = new data_t[new_c];
        if(capacity()>0){
            for(size_t i = 0; i <old_s; i++)A[i] = begin_[i];
            delete [] begin_;
        }
        begin_ = A;
        last_ = &begin_[old_s-1];
        end_ = &begin_[new_c-1];
    }
    if(pos==size()){
        while(count--)
            push_back(val);
        return;
    }
    else if(pos<size()){
        for(size_t i = size()-1;i>=pos;i--){
            begin_[i+count] = begin_[i];
            if(i==0) break;
        }
        for(size_t i = pos; i<pos+count;i++)
            begin_[i] = val;
        last_ = &begin_[size()-1+count];
    }
}

void oj::Vector::reserve(size_t new_capacity)
{
    if(new_capacity>capacity()){
        size_t old_s = size();
        data_t *A = new data_t[new_capacity];
        if(capacity()>0){
            for(size_t i = 0; i < size(); i++) A[i] = begin_[i];
            delete [] begin_;
        }
        begin_ = A;
        last_ = &begin_[old_s-1];
        end_ = &begin_[new_capacity-1];
    }
}

void oj::Vector::resize(size_t new_size)
{
    if(new_size==0)
        last_ = nullptr;
    else{
        size_t old_s = size();
        if(new_size>capacity()){
            data_t *A = new data_t[new_size];
            if(capacity()>0){
                for(size_t i = 0; i <size(); i++)A[i] = begin_[i];
                delete [] begin_;
            }
            begin_ = A;
            end_ = &begin_[new_size-1];
        }
        for(size_t i = old_s;i<new_size;i++) begin_[i]=0;
        last_ = &begin_[new_size-1];
    }
}
*/
#include<iostream>
#include "function.h"

using namespace std;

oj::Vector::Vector(){//constructor
    begin_ = last_ = end_ = nullptr;
}
oj::Vector::~Vector(){//destructor
    if(capacity()>0)
        delete [] begin_;
    begin_ = last_ = end_ = nullptr;
}
size_t oj::Vector::size() const{
    if(last_==nullptr)
        return 0;
    return (size_t)(last_-begin_)+1;
}
size_t oj::Vector::capacity() const{
    if(end_ == nullptr) return 0;
    return (size_t)(end_-begin_)+1;
}

void oj::Vector::pop_back(){
    if(size()==1){
        delete begin_;
        begin_ = nullptr;
    }
    else{
        last_ --;
    }
}
void oj::Vector::push_back(data_t val){
    if(size()==capacity()){
        size_t new_c = max(capacity()+1, capacity()*3),
        old_s = size();
        data_t *A = new data_t[new_c];
        if(capacity()>0){
            for(int i = 0; i < old_s; i++)
                A[i] = begin_[i];
            delete [] begin_;
        }
        begin_ = A;
        last_ = &begin_[old_s-1];
        end_ = &begin_[new_c-1];
    }
    begin_[size()] = val;
    last_ = &begin_[size()];
}
void oj::Vector::insert(std::size_t pos,std::size_t count,data_t val){
    if((size()+count)==capacity()){
        size_t new_c = max(capacity() + capacity()/ 2, capacity()+count),
        old_s = size();
        data_t *A = new data_t[new_c];
        if(capacity()>0){
            for(int i = 0; i < old_s; i++)
                A[i] = begin_[i];
            delete [] begin_;
        }
        begin_ = A;
        last_ = &begin_[old_s];
        end_ = &begin_[new_c];
    }
    if(pos == size()){
        while(count--)
            push_back(val);
    }
    else{
        for(size_t i = size(); i>pos;i--)
            begin_[i+count-1] = begin_[i-1];
        for(size_t i = 0;i<count;i++)
            begin_[pos+i] = val;
    }
}

void oj::Vector::reserve(std::size_t new_capacity){
    if(new_capacity>capacity()){
        size_t new_c = new_capacity, old_s = size();
        data_t *A = new data_t[new_c];
        if(capacity()>0){
            for(int i = 0; i < old_s; i++)
                A[i] = begin_[i];
            delete [] begin_;
        }
        begin_ = A;
        last_ = &begin_[old_s];
        end_ = &begin_[new_c];
    }
}
void oj::Vector::resize(std::size_t new_size){
    if(new_size>capacity()){
        size_t new_c = new_size+1, old_s = size();
        data_t *A = new data_t[new_c];
        if(capacity()>0){
            for(int i = 0; i < old_s; i++)
                A[i] = begin_[i];
            delete [] begin_;
        }
        begin_ = A;
        last_ = &begin_[old_s];
        end_ = &begin_[new_c];
    }
    for(size_t i = size(); i<new_size;i++ )
        begin_[i] = 0;
    last_ = &begin_[new_size-1];
}
