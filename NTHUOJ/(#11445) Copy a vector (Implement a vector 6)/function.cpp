//
//  function.cpp
//  (#11445) Copy a vector (Implement a vector 6)
//
//  Created by Magic Bear on 2017/11/27.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>
#include"function.h"

using namespace std;
/*
oj::Vector::Vector()
{
    begin_ = end_ = last_ = nullptr;
}

oj::Vector::~Vector()
{
    if(capacity()>0)
    {
        operator delete [] (begin_);
    }
    begin_ = end_ = last_ = nullptr;
}

oj::Vector::Vector(const oj::Vector &vec)
{
    if(vec.size()==0)
    {
        begin_ = end_ = last_ = nullptr;
    }
    else
    {
        begin_ = static_cast<pointer>(operator new [] (vec.size()*sizeof(value_type)));
        for(oj::Vector::size_type i=0 ; i<vec.size() ; i++)
        {
            new (begin_+i) value_type(vec[i]);
        }
        end_ = last_ = begin_+vec.size();
    }
}

oj::Vector& oj::Vector::operator=(const Vector &vec)
{
    if(this->capacity()>0) operator delete [] (this->begin_);
    this->begin_ = static_cast<pointer>(operator new [] (vec.size()*sizeof(oj::Vector::value_type)));
    for(oj::Vector::size_type i=0 ; i<vec.size() ; i++)
    {
        new (this->begin_+i) oj::Vector::value_type(vec[i]);
    }
    this->end_ = this->last_ = this->begin_+vec.size();
    return *this;
}

void oj::Vector::erase(size_type pos)
{
    if(pos<size())
    {
        for(oj::Vector::size_type i=pos ; i<size()-1 ; i++)
        {
            begin_[i] = begin_[i+1];
        }
        last_--;
    }
}

void oj::Vector::insert(size_type pos,const_reference val)
{
    if(pos<=size())
    {
        if(size()==capacity())
        {
            oj::Vector::size_type old_s = size(), new_c = max(capacity()+1,capacity()*3);
            pointer A = static_cast<pointer>(operator new [] (new_c*sizeof(oj::Vector::value_type)));
            if(capacity()>0)
            {
                for(oj::Vector::size_type i=0 ; i<old_s ; i++)
                {
                    new (A+i) oj::Vector::value_type(begin_[i]);
                }
                operator delete [] (begin_);
            }
            
            begin_ = A;
            end_ = begin_ + new_c;
            last_ = begin_ + old_s;
        }
        new (begin_+size()) oj::Vector::value_type("");
        for(oj::Vector::size_type i=size() ; i>pos ; i--)
        {
            begin_[i] = begin_[i-1];
        }
        new (begin_+pos) oj::Vector::value_type(val);
        last_++;
    }
}

void oj::Vector::reserve(size_type new_capacity)
{
    if(new_capacity>capacity())
    {
        oj::Vector::size_type old_s = size();
        pointer A = static_cast<pointer>(operator new [] (new_capacity*sizeof(oj::Vector::value_type)));
        if(capacity()>0)
        {
            for(oj::Vector::size_type i=0 ; i<old_s ; i++)
            {
                new (A+i) oj::Vector::value_type(begin_[i]);
            }
            operator delete [] (begin_);
        }
        
        begin_ = A;
        end_ = begin_ + new_capacity;
        last_ = begin_ + old_s;
    }
}
*/

oj::Vector::Vector(){
    begin_ = last_ = end_ = nullptr;
}
oj::Vector::~Vector(){
    if(capacity()>0){
        operator delete [] (begin_);
    }
    begin_ = last_ = end_ = nullptr;
}
oj::Vector::Vector(const Vector &vec){
    if(vec.size()==0){
        begin_ = last_ = end_ = nullptr;
        return;
    }
    else{
        begin_ = static_cast<pointer>(operator new [](vec.size()*sizeof(value_type)));
        for(size_type i = 0;i<vec.size();i++)
            new (begin_+i) value_type(vec[i]);
        last_ = end_ =  begin_+vec.size();
    }
}
oj::Vector& oj::Vector::operator=(const Vector &vec){
    if(this->capacity()>0){
        operator delete [] (this->begin_);
    }
    this->begin_ = static_cast<pointer>(operator new [](vec.size()*sizeof(value_type)));
    for(size_type i = 0;i<vec.size();i++)
        new (this->begin_+i) value_type(vec[i]);
    this->last_ = this->end_ =  this->begin_+vec.size();
    return *this;
}
void oj::Vector::erase(size_type pos){
    if(pos<size()){
        for(size_type i = pos;i<size()-1;i++)
            new (begin_+i) value_type(begin_[i+1]);
        last_--;
    }
}
void oj::Vector::insert(size_type pos,const_reference val){
    if(pos<=size()){
        if(size()==capacity()){
            size_type new_c = max(capacity()+1,3*capacity()),old_s = size();
            pointer A = static_cast<pointer>(operator new [](new_c*sizeof(value_type)));
            for(size_type i = 0;i<old_s;i++)
                new (A+i) value_type(begin_[i]);
            operator delete [] (begin_);
            begin_ = A;
            last_ = begin_+old_s;
            end_ = begin_+new_c;
        }
        new (begin_+size()) value_type("");
        for(size_type i = size();i>pos;i--)
            new (begin_+i) value_type(begin_[i-1]);//Or Just Write begin_[i] = begin_[i-1]
        new (begin_+pos) value_type(val);
        last_++;
    }
}
void oj::Vector::reserve(size_type new_capacity){
    if(new_capacity>capacity()){
        size_type old_s = size();
        pointer A = static_cast<pointer>(operator new [](new_capacity*sizeof(value_type)));
        for(size_type i = 0;i<old_s;i++)
            new (A+i) value_type(begin_[i]);
        operator delete [] (begin_);
        begin_ = A;
        last_ = begin_+old_s;
        end_ = begin_+new_capacity;
    }
}
