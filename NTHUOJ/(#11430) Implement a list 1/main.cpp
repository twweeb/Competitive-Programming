//
//  main.cpp
//  (#11430) Implement a list 1
//
//  Created by Magic Bear on 2017/11/15.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>
#include<string>
#include"function.h"

int main()
{
    using namespace std;
    {
        oj::List lst;
        for(string command;cin>>command;)
            if(command=="erase")
            {
                oj::List::size_type pos;
                cin>>pos;
                lst.erase(pos);
            }
            else
                if(command=="insert")
                {
                    oj::List::size_type pos;
                    oj::List::value_type val;
                    cin>>pos>>val;
                    lst.insert(pos,val);
                }
            else
                if(command=="show")
                    cout<<lst<<endl;
    }
}
