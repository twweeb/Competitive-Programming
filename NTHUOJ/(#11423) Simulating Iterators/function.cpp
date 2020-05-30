//
//  function.cpp
//  (#11423) Simulating Iterators
//
//  Created by Magic Bear on 2017/11/27.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>
#include"function.h"

using namespace std;
oj::Node::Node(){
    next = prev = nullptr;
}
oj::Iter::Iter(data_t *begin){
    p_ = begin;
}
ptrdiff_t oj::Random_iter::distance_(const Iter &begin,const Iter &end) const{
    ptrdiff_t dis = end.get()-begin.get();
    return dis;
}
void oj::Random_iter::next_(Iter &des) const{
    Random_iter iter(this->get()+1);
    des = iter;
}
void oj::Random_iter::prev_(Iter &des) const{
    Random_iter iter(this->get()-1);
    des = iter;
}
oj::Random_iter::Random_iter(data_t *begin):oj::Iter(begin){}
ptrdiff_t oj::Bidirect_iter::distance_(const Iter &begin,const Iter &end) const{
    ptrdiff_t dis = 0;
    oj::Node *curr = begin.get();
    while(curr!=end.get()){
        curr = curr->next;
        dis++;
    }
    return dis;
}
void oj::Bidirect_iter::next_(Iter &des) const{
    Bidirect_iter iter(this->get()->next);
    des = iter;
}
void oj::Bidirect_iter::prev_(Iter &des) const{
    Bidirect_iter iter(this->get()->prev);
    des = iter;
}

oj::Bidirect_iter::Bidirect_iter(data_t *begin):oj::Iter(begin){}
