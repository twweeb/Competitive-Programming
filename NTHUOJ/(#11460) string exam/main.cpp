//
//  main.cpp
//  (#11460) string exam
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include "function.h"

int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    
    for(string str;getline(cin, str);)
        cout<<string_change_order(str)<<endl;
    return 0;
}

