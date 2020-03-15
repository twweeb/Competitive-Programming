//
//  main.cpp
//  (#11029) extend
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> extend(vector<int> v)
{
    set<vector<int>> S;
    for(int i = 0;i<v.size()-1;i++){
        vector<int> t(v);
        swap(t[i],t[i+1]);
        S.insert(t);
    }
    vector<int> t(v);
    swap(t[0],t[t.size()-1]);
    S.insert(t);
    return S;
}

// Define "extend" here.
int main()
{
    vector<int> v; // = {6, 1, 4, 3, 5, 2};
    int e;
    while (cin >> e) { // press Ctrl + Z to end the input
        v.push_back(e);
    }
    auto S = extend(v); // the type of S will depend on the return type of extend
    for (auto s : S) {
        cout << s[0];
        for (unsigned i=1; i<s.size(); ++i) {
            cout << " " << s[i];
        }
        cout << "\n";
    }
}

