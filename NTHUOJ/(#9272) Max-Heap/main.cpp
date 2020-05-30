//
//  main.cpp
//  (#9272) Max-Heap
//
//  Created by Magic Bear on 2017/12/21.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <string>

using namespace std;

int main ()
{
    priority_queue<int> p;
    
    string str;
    while(cin>>str){
        if(str == "PUSH"){
            int i;
            cin >> i;
            p.push(i);
        }
        else if(str == "POP"){
            p.pop();
        }
        else if(str == "TOP"){
            if(!p.empty())
                cout << p.top() << endl;
            else
                cout << "Null" << endl;
        }
    }

    return 0;
}
