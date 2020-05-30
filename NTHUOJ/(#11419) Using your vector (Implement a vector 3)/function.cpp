//
//  function.cpp
//  (#11419) Using your vector (Implement a vector 3)
//
//  Created by Magic Bear on 2017/11/26.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>
#include"function.h"

using namespace std;

void oj::Vector::push_back(const data_t &val)
{
    if(size()==capacity()){
        size_t old_s = size(), new_c = max(capacity()+1,capacity()*3);
        data_t *A = static_cast<data_t*>(operator new [](sizeof(data_t)*new_c));
        if(capacity()>0){
            for(size_t i = 0; i< old_s;i++){
                new (A+i) data_t(begin_[i]);
            }
            operator delete [] (begin_);
        }
        begin_ = A;
        last_ = begin_+old_s;
        end_ = begin_+new_c;
    }
    new (begin_+size()) data_t(val);
    last_++;
}

void oj::Vector::erase(std::size_t pos)
{
    if(pos<size()){
        for(size_t i = pos;i<size()-1;i++){
            new (begin_+i) data_t(begin_[i+1]);
        }
        last_--;
    }
}

void oj::Vector::reserve(std::size_t new_capacity)
{
    if(new_capacity>capacity()){
        size_t old_s = size();
        data_t *A = static_cast<data_t*>(operator new[](sizeof(data_t)*new_capacity));
        if(capacity()>0){
            for(size_t i = 0; i<old_s;i++){
                new (A+i) data_t(begin_[i]);
            }
            operator delete [] (begin_);
        }
        begin_ = A;
        last_ = begin_+old_s;
        end_ = begin_+new_capacity;
    }
}

oj::Vector::~Vector(){
    operator delete[](begin_);
    begin_ = last_ = end_ = nullptr;
}

oj::Employee::Employee(const string &n): name_(n),id_(ID_++){}

class oj::God
{
    public:
        Employee create(const string &name);
        string getName(const Employee e);
        unsigned getID(const Employee e);
};

oj::Employee oj::God::create(const string &name)
{
    Employee e(name);
    return e;
}
string oj::God::getName(const oj::Employee e)
{
    return e.name_;
}
unsigned oj::God::getID(const oj::Employee e)
{
    return e.id_;
}
void oj::add_employee(Vector &vec,const std::string &name)
{
    God g;
    vec.push_back(g.create(name));
}
void oj::print(const Vector &vec)
{
    God g;
    for(size_t i = 0;i<vec.size();i++)
        cout << g.getID(vec[i]) << " " << g.getName(vec[i]) << endl;
}
void oj::quit(Vector &vec,unsigned id){
    God g;
    for(size_t i = 0;i<vec.size();i++){
        if(g.getID(vec[i])==id){
            vec.erase(i);
            return;
        }
    }
}
void oj::quit(Vector &vec,const std::string &name){
    God g;
    for(size_t i = 0;i<vec.size();i++){
        if(g.getName(vec[i])==name){
            vec.erase(i);
            i--;
        }
    }
}
