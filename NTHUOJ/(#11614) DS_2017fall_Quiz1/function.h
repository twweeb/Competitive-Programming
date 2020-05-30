//
//  function.hpp
//  (#11614) DS_2017fall_Quiz1
//
//  Created by Magic Bear on 2018/4/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <string>

class abstract
{
public:
    abstract(){};
    ~abstract(){};
    virtual double myFunc(std::string t) = 0;
    
};

class Implement;

#endif

