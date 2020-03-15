//
//  function.hpp
//  (#11447) Use std::map
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<map>
#include<string>

namespace oj
{
    struct String
    {
        std::string str;
        String(const std::string &);
        String(const String &);
        String& operator=(const String &);
    };
    
    std::ostream& operator<<(std::ostream &,const String &);
    
    void insert(std::map<int,String> &ma,int key,const std::string &str);
    void output(const std::map<int,String> &ma,int begin,int end);
    void erase(std::map<int,String> &ma,int begin,int end);
    
    std::ostream& operator<<(std::ostream &,const std::map<int,String> &);
}

#endif

