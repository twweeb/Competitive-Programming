//
//  main.cpp
//  (#11410) Implement a vector 2
//
//  Created by Magic Bear on 2017/11/13.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<cstdlib>
#include<iostream>
#include<string>
#include"function.h"

namespace oj
{
    std::ostream& operator<<(std::ostream &os,const Vector &vec)
    {
        for(std::size_t i(0);i!=vec.size();++i)
            os<<vec[i]<<' ';
        return os;
    }
}

int main()
{
    using namespace std;
    {
        oj::Vector v;
        string command;
        
        for(oj::data_t n;cin>>command;)
        {
            if(command=="pop_back")
            {
                v.pop_back();
                cout<<v<<endl;
            }
            else if(command=="push_back")
            {
                cin>>n;
                v.push_back(n);
                cout<<v<<endl;
            }
            else if(command=="insert")
            {
                size_t pos,count;
                cin>>pos>>count>>n;
                v.insert(pos,count,n);
                cout<<v<<endl;
            }
            else if(command=="capacity")
                cout<<v.capacity()<<endl;
            else if(command=="size")
                cout<<v.size()<<endl;
            else if(command=="reserve")
            {
                cin>>n;
                v.reserve(n);
                cout<<v<<endl;
            }
            else if(command=="resize")
            {
                cin>>n;
                v.resize(n);
                cout<<v<<endl;
            }
        }
        cout<<v<<endl;
    }
}
