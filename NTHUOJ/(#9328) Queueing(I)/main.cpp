//
//  main.cpp
//  (#9328) Queueing(I)
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
    queue<string> p;
    
    string str;
    while(cin>>str){
        if(str == "Push"){
            string i;
            cin >> i;
            p.push(i);
        }
        else if(str == "Pop"){
            if(!p.empty())
                p.pop();
        }
        else if(str == "Front"){
            if(!p.empty())
                cout << p.front() << endl;
            else
                cout << "empty" << endl;
        }
    }
    
    return 0;
}

