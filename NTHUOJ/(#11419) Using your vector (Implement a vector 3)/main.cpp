//
//  main.cpp
//  (#11419) Using your vector (Implement a vector 3)
//
//  Created by Magic Bear on 2017/11/21.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//
#include<cstddef>
#include<iostream>
#include<string>
#include"function.h"

namespace oj
{
    Employee::Employee(const Employee &rhs)
    :name_(rhs.name_),id_(rhs.id_){}
    
    unsigned Employee::ID_(0);
    
    Vector::Vector()
    :begin_(NULL),end_(NULL),last_(NULL){}
}

int main()
{
    using namespace std;
    {
        oj::Vector vec[2];
        for(string command,name;cin>>command;)
        {
            if(command=="recruit")
            {
                cin>>name;
                add_employee(vec[0],name);
            }
            else if(command=="quit")
            {
                unsigned id;
                cin>>id;
                if(id)
                {
                    cin>>id;
                    quit(vec[0],id);
                }
                else
                {
                    cin>>name;
                    quit(vec[0],name);
                }
            }
            else if(command=="reserve")
            {
                size_t size;
                cin>>size;
                vec[0].reserve(size);
            }
            else if(command=="capacity")
                cout<<vec[0].capacity()<<endl;
            else if(command=="size")
                cout<<vec[0].size()<<endl;
            print(vec[0]);
        }
    }
}
