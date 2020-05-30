//
//  Header.h
//  (#11410) Implement a vector 2
//
//  Created by Magic Bear on 2017/11/13.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//
#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<iosfwd>

namespace oj
{
    typedef int data_t;
    
    class Vector
    {
        data_t *begin_;    //begin of array
        data_t *end_;    //end of array
        data_t *last_;    //end of current element
    public:
        Vector();
        
        //std::size_t is an unsigned integer
        std::size_t capacity() const;
        std::size_t size() const;
        
        //ignore the keyword "inline"
        //operator[] makes Vector like a C-array, for example
        //int a[2]{2,1};
        //Vector vec;
        //vec.push_back(1);
        //vec.push_back(2);
        //vec[0] is equal to a[1]
        //vec[1] is equal to a[0]
        inline data_t& operator[](const std::size_t pos)
        {
            return begin_[pos];
        }
        inline const data_t& operator[](const std::size_t pos) const
        {
            return begin_[pos];
        }
        
        void pop_back();
        void push_back(data_t val);
        void insert(std::size_t pos,std::size_t count,data_t val);
        
        void reserve(std::size_t new_capacity);
        void resize(std::size_t new_size);
        
        ~Vector();
    };
    
    std::ostream& operator<<(std::ostream &os,const Vector &vec);    //for cout
}

#endif
