//
//  main.cpp
//  (#9416) Lexicographic Order
//
//  Created by Magic Bear on 2017/12/21.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <string>

using namespace std;

class mycomparison
{
    bool reverse;
public:
    mycomparison(const bool& revparam=false){
        reverse=revparam;
    }
    bool operator() (const string& lhs, const string& rhs) const{
        if (reverse) return (lhs>rhs);
        else return (lhs<rhs);
    }
};

int main (){
    typedef std::priority_queue<string,vector<string>,mycomparison> mypq_type;
    
    mypq_type p (mycomparison(true));   // greater-than comparison
    
    int num;
    string word;
    while(cin>>num){
        if(num==0)break;
        else{
            for(int j = 0; j< num;j++){
                cin >> word;
                p.push(word);
            }
            for(int j = 0; j< num;j++){
                cout << p.top() << endl;
                p.pop();
            }
            cout << endl;
        }
    }
    return 0;
}
