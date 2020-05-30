//
//  function.cpp
//  (#11401) vector and STL
//
//  Created by Magic Bear on 2017/12/22.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include "function.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace oj{
    vec_t cat(const vec_t &lhs,const vec_t &rhs){
        vec_t cat(lhs);
        for(size_t i=0;i<rhs.size();i++)
        {
            cat.push_back(rhs[i]);
        }
        return cat;
    }

    void erase_equivalent(vec_t &vec){
        sort(vec);
        for(size_t i = 1;i<vec.size();i++){
            if(vec[i]==vec[i-1]){
                vec.erase(vec.begin()+i);
                i--;
            }
        }
    }

    vec_t inter(const vec_t &lhs,const vec_t &rhs){
        vec_t v1(lhs), v2(rhs),inter;
        std::sort(v1.begin(),v1.end());
        std::sort(v2.begin(),v2.end());
        for(int i = 0; i < v1.size(); i++){
            for(int j = 0; j < v2.size(); j++){
                if(v1[i]==v2[j]){
                    inter.push_back(v1[i]);
                    v1.erase(v1.begin()+i);
                    v2.erase(v2.begin()+j);
                    i--;
                    j--;
                }
            }
        }
        std::sort(inter.begin(),inter.end());
        return inter;
    }

    void make_size_to(vec_t &vec,int new_size){
        vec.resize(new_size);
    }

    vec_t mix(const vec_t &lhs,const vec_t &rhs){
        vec_t cat(lhs);
        for(size_t i=0;i<rhs.size();i++)
        {
            cat.push_back(rhs[i]);
        }
        sort(cat);
        return cat;
    }

    std::size_t odd_num_count(const vec_t &vec){
        size_t N = 0;
        for(size_t i = 0; i < vec.size(); i++){
            if(vec[i]%2) N++;
        }
        return N;
    }

    void output(const vec_t &vec){
        vec_t tmp(vec);
        for(vec_t::iterator it = tmp.begin();it!=tmp.end();it++){
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    vec_t rotate_half(const vec_t &vec){
        vec_t rotate,tmp(vec);
        size_t half = tmp.size()/2;
        for(vec_t::iterator it = tmp.begin()+half;it!=tmp.end();it++){
            rotate.push_back(*it);
        }
        for(vec_t::iterator it = tmp.begin();it!=tmp.begin()+half;it++){
            rotate.push_back(*it);
        }
        return rotate;
    }

    void read_input(vec_t &vec){
        int i;
        while(static_cast<void>(std::cin>>i),i)
            vec.push_back(i);
    }

    vec_t reverse(const vec_t &vec){
        vec_t reverse;
        size_t i = vec.size();
        while(i--){
            reverse.push_back(vec[i]);
        }
        return reverse;
    }

    void sort(vec_t &vec){
        std::sort(vec.begin(), vec.end(),std::greater<int>());
    }

    int sum(const vec_t &vec){
        int sum = 0;
        for(size_t i = 0;i<vec.size();i++){
            sum += vec[i];
        }
        return sum;
    }
}
/*
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include "function.h"

namespace oj {
    vec_t cat(const vec_t &lhs, const vec_t &rhs) {
        vec_t ret(lhs);
        ret.insert(ret.end(), rhs.begin(), rhs.end());
        return ret;
    }
    void erase_equivalent(vec_t &vec) {
        sort(vec.begin(), vec.end(), std::greater<int>());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        
    }
    vec_t inter(const vec_t &lhs, const vec_t &rhs) {
        vec_t ret, ls(lhs), rs(rhs);
        sort(ls.begin(), ls.end());
        sort(rs.begin(), rs.end());
        set_intersection(ls.begin(), ls.end(), rs.begin(), rs.end(), std::inserter(ret, ret.begin()));
        return ret;
    }
    void make_size_to(vec_t &vec, int new_size) {
        vec.resize(new_size);
    }
    vec_t mix(const vec_t &lhs, const vec_t &rhs) {
        vec_t ret(lhs);
        ret.insert(ret.end(), rhs.begin(), rhs.end());
        sort(ret.begin(), ret.end(), std::greater<int>());
        return ret;
    }
    std::size_t odd_num_count(const vec_t &vec) {
        return count_if(vec.begin(), vec.end(), [](int rhs) { return rhs & 1; });
    }
    void output(const vec_t &vec) {
        copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
    vec_t rotate_half(const vec_t &vec) {
        vec_t ret;
        rotate_copy(vec.begin(), vec.begin() + vec.size() / 2, vec.end(), std::inserter(ret, ret.begin()));
        return ret;
    }
    void read_input(vec_t &vec) {
        int n;
        while (std::cin >> n, n) vec.push_back(n);
    }
    vec_t reverse(const vec_t &vec) {
        vec_t ret;
        reverse_copy(vec.begin(), vec.end(), std::inserter(ret, ret.begin()));
        return ret;
    }
    void sort(vec_t &vec) {
        sort(vec.begin(), vec.end(), std::greater<int>());
    }
    int sum(const vec_t &vec) {
        return accumulate(vec.begin(), vec.end(), 0);
    }
}
*/
