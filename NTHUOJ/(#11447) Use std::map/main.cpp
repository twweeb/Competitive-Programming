//
//  main.cpp
//  (#11447) Use std::map
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include<cassert>
#include<iostream>
#include<map>
#include<ostream>
#include<string>
#include"function.h"

namespace oj
{
    String::String(const std::string &str_)
    :str(str_){}
    
    String::String(const String &rhs)
    :str(rhs.str){}
    
    String& String::operator=(const String &rhs)
    {
        str=rhs.str;
        return *this;
    }
    
    std::ostream& operator<<(std::ostream &os,const String &str)
    {
        return os<<str.str;
    }
}

int main()
{
    using namespace std;
    using namespace oj;
    map<int,String> ma;
    for(string cmd;cin>>cmd;)
    {
        if(cmd=="insert")
        {
            int key;
            cin>>key>>cmd;
            insert(ma,key,cmd);
        }
        else
            if(cmd=="range")
            {
                int begin,end;
                cin>>cmd>>begin>>end;
                if(cmd=="output")
                    output(ma,begin,end);
                else
                    if(cmd=="erase")
                        erase(ma,begin,end);
                    else
                        assert(false);
            }
            else
                assert(false);
        cout<<ma<<endl;
    }
}

