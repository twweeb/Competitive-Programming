//
//  main.cpp
//  (#11401) vector and STL
//
//  Created by Magic Bear on 2017/12/21.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<algorithm>
#include<iostream>
#include<vector>
#include"function.h"

int main()
{
    using namespace std;
    using namespace oj;
    vec_t vec,vec2;
    read_input(vec);
    read_input(vec2);
    cout<<"vec : ";
    output(vec);
    cout<<"vec2 : ";
    output(vec2);
    sort(vec);
    sort(vec2);
    cout<<"vec : ";
    output(vec);
    cout<<"vec2 : ";
    output(vec2);
    cout<<"cat(vec,vec2) : ";
    output(cat(vec,vec2));
    vec_t vec3(mix(vec,vec2));
    cout<<"vec3 : ";
    output(vec3);
    erase_equivalent(vec3);
    cout<<"vec3 : ";
    output(vec3);
    cout<<odd_num_count(vec3)<<endl;
    make_size_to(vec3,max(sum(inter(vec,vec2)),0));
    cout<<"rotate_half(vec3) : ";
    output(rotate_half(vec3));
    cout<<"rotate_half(reverse(inter(vec,vec2))) : ";
    output(rotate_half(reverse(inter(vec,vec2))));
}

