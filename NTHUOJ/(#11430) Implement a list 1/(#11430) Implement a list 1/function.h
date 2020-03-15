//
//  function.h
//  (#11430) Implement a list 1
//
//  Created by Magic Bear on 2017/11/15.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<iosfwd>

namespace oj
{
    class List
    {
        friend std::ostream& operator<<(std::ostream &,const List &);
    public:
        typedef std::size_t size_type;
        typedef int value_type;
        typedef const value_type &const_reference;
    private:
        struct Node
        {
            Node *next;
            Node *prev;
            value_type data;
        };
        Node *begin_;
    public:
        List();
        ~List();
        
        void erase(size_type pos);
        void insert(size_type pos,const_reference val);
    };
    
    std::ostream& operator<<(std::ostream &,const List &);
}

#endif
