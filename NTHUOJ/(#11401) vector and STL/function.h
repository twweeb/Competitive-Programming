//
//  function.hpp
//  (#11401) vector and STL
//
//  Created by Magic Bear on 2017/12/22.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<vector>

namespace oj
{
    typedef std::vector<int> vec_t;//using vec_t=std::vector<int>;    //for C++11
    
    vec_t cat(const vec_t &lhs,const vec_t &rhs);
    void erase_equivalent(vec_t &vec);
    vec_t inter(const vec_t &lhs,const vec_t &rhs);
    void make_size_to(vec_t &vec,int new_size);
    vec_t mix(const vec_t &lhs,const vec_t &rhs);
    std::size_t odd_num_count(const vec_t &vec);
    void output(const vec_t &vec);
    vec_t rotate_half(const vec_t &vec);
    void read_input(vec_t &vec);
    vec_t reverse(const vec_t &vec);
    void sort(vec_t &vec);
    int sum(const vec_t &vec);
}

#endif

