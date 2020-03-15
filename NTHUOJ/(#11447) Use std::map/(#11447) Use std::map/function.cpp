//
//  function.cpp
//  (#11447) Use std::map
//
//  Created by Magic Bear on 2017/12/22.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include "function.h"
#include <string>
#include <iostream>
#include <map>
#include <array>

namespace oj{
    void insert(std::map<int,String> &ma,int key,const std::string &str){
        std::map<int,String>::iterator it = ma.find(key);
        if(it == ma.end()){
            String p(str);
            ma.insert(std::pair<int,String>(key,p));
        }
        else{
            std::map<int,String>::iterator it = ma.find(key);
            std::string p = str + it->second.str;
            ma.erase(it);
            ma.insert(std::pair<int, String>(key,p));
        }
    }
    
    void output(const std::map<int,String> &ma,int begin,int end){
        std::map<int,String> tmp = ma;
        std::map<int,String>::iterator it;
        for(int i = begin; i<=end;i++){
            it = tmp.find(i);
            if(it!=tmp.end())
                std::cout << it->second.str << " ";
        }
    }
    
    void erase(std::map<int,String> &ma,int begin,int end){
        std::map<int,String>::iterator it;
        for(int i = begin; i<=end;i++){
            it = ma.find(i);
            if(it!=ma.end())
                ma.erase(it);
        }
    }
    
    std::ostream& operator<<(std::ostream &os,const std::map<int,String> &ma){
        std::map<int,String>::iterator it;
        std::map<int,String> tmp = ma;
        for(it=tmp.begin();it!=tmp.end();it++)
            os << it->second << " ";
        return os;
    }
}

