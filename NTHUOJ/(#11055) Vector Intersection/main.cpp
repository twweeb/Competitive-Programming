//
//  main.cpp
//  (#11055) Vector Intersection
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

using namespace std;

typedef vector<int> vec_t;


vec_t inter(const vec_t &lhs, const vec_t &rhs) {
    vec_t ret, ls(lhs), rs(rhs);
    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end());
    set_intersection(ls.begin(), ls.end(), rs.begin(), rs.end(), std::inserter(ret, ret.begin()));
    return ret;
}

void show(const vec_t &vec)
{
    if(vec.size()!=0){
        copy(vec.begin(), vec.end()-1, std::ostream_iterator<int>(std::cout, " "));
        cout << *(vec.end()-1);
    }
    else
        cout << "empty";
    std::cout << std::endl;
}

int main()
{
    vec_t vec1,vec2;
    long long int N,M;
    int val;
    while(cin >> N, N!=0){
        for(long long int i = 0; i < N;i++)
        {
            cin >> val;
            vec1.push_back(val);
        }
        cin >> M;
        for(long long int i = 0; i < M;i++)
        {
            cin >> val;
            vec2.push_back(val);
        }
        show(inter(vec1,vec2));
        vec1.clear();
        vec2.clear();
    }
    return 0;
}

