//
//  function.hpp
//  (#11419) Using your vector (Implement a vector 3)
//
//  Created by Magic Bear on 2017/11/26.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<iosfwd>
#include<string>

namespace oj
{
    //this is only for OJ
    //do not design class like this (this is a very bad coding style)
    class Employee
    {
        friend struct God;
        static unsigned ID_;    //start from 0
        const std::string name_;
        const unsigned id_;
        Employee(const std::string &name);
        //constructor (only God can construct Employee)
    public:
        Employee(const Employee &);
    };
    
    typedef Employee data_t;
    
    class Vector
    {
        data_t *begin_;    //begin of array
        data_t *end_;    //end of array
        data_t *last_;    //end of current size
    public:
        Vector();
        
        std::size_t capacity() const
        {
            return end_-begin_;
        }
        std::size_t size() const
        {
            return last_-begin_;
        }
        data_t& operator[](const std::size_t pos)
        {
            return begin_[pos];
        }
        const data_t& operator[](const std::size_t pos) const
        {
            return begin_[pos];
        }
        
        void push_back(const data_t &val);
        void erase(std::size_t pos);
        void reserve(std::size_t new_capacity);
        
        ~Vector();
    };
    
    struct God;
    void add_employee(Vector &vec,const std::string &name);
    void print(const Vector &vec);
    void quit(Vector &vec,unsigned id);
    void quit(Vector &vec,const std::string &name);
}

#endif

