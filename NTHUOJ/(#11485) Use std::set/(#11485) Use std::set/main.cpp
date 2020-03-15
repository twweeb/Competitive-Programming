//
//  main.cpp
//  (#11485) Use std::set
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> int_seq;

int key(const int_seq& seq){
    int key = 0;
    for(int i = 0;i<seq.size();i++){
        key += seq[i]*(seq.size()-i);
    }
    return key;
}

struct CustomCompare
{
    bool operator()(const int_seq& lhs, const int_seq& rhs)
    {
        return key(lhs) < key(rhs);
    }
};

int main() {
    set<vector<int>>::iterator it;
    set<vector<int>,CustomCompare> IntSeqSet;
    string command;
    int t;
    while(cin >> command){
        if(command == "insert"){
            vector<int> p;
            while(cin>>t, t){
                p.push_back(t);
            }
            if((it = IntSeqSet.find(p))!=IntSeqSet.end())
            {
                cout << "exist" << endl;
                IntSeqSet.erase(it);
                reverse(p.begin(), p.end());
            }
            IntSeqSet.insert(p);
        }
        if(command == "range_out"){
            vector<int> first,second;
            while(cin>>t, t){
                first.push_back(t);
            }
            while(cin>>t, t){
                second.push_back(t);
            }
            
            auto iter = IntSeqSet.upper_bound(second);
            for (it = IntSeqSet.lower_bound(first); it != iter; it++)
            {
                vector<int> v = *it;
                for (int i = 0; i < v.size(); ++i)
                    cout << v[i] << ' ';
                cout << endl;
            }
        }
        if (command == "output") {
            for (it = IntSeqSet.begin(); it != IntSeqSet.end(); it++) {
                vector<int> v = *it;
                for (int i = 0; i < v.size(); ++i)
                    cout << v[i] << ' ';
                cout << endl;
            }
        }
    }
    
}
