//
//  function.h
//  (#11719) Implement a list 6 (operator new)
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<iosfwd>
#include<new>
#include<string>

namespace oj
{
    struct String
    {
        std::string str;
        String(const std::string &str);
        String(const String &rhs);
        String& operator=(const String &rhs);
    };
    
    std::ostream& operator<<(std::ostream &os,const String &str);
    
    class List
    {
        friend std::ostream& operator<<(std::ostream &os,const List &lst);
    public:
        typedef std::size_t size_type;
        typedef String value_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
    private:
        struct Node
        {
            Node *next;
            Node *prev;
            value_type data;
        };
        Node *begin_;
        //to help you reduce code size, you can use these functions
        Node* new_Node_();
        Node* new_Node_(const_reference val);
        void delete_Node_(Node *node);
    public:
        List();
        List(const List &rhs);
        List& operator=(const List &rhs);
        ~List();
        
        reference back();
        const_reference back() const;
        reference front();
        const_reference front() const;
        
        void clear();
        void erase(size_type pos);
        void insert(size_type pos,const_reference val);
    };
    
    std::ostream& operator<<(std::ostream &os,const List &lst);
}

//you don't have to pay attention on these 4 functions
void* operator new(std::size_t count);
void* operator new[](std::size_t count);
void operator delete(void *p) noexcept;
void operator delete[](void *p) noexcept;

#endif

