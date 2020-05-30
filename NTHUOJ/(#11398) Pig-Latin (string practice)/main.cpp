//
//  main.cpp
//  (#11398) Pig-Latin (string practice)
//
//  Created by Magic Bear on 2017/12/21.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>
#include "function.h"

int main(){
    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;
    
    string str, s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    while(getline(cin, str)){
        str = string_replace(str, s1, s2);
        str = string_change_word(str);
        cout <<  str  <<endl;
    }
    
    return 0;
}

