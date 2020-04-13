//
//  sat.cpp
//  Applied Mathematical Logic Programming Assignment - Boolean Satisfiability Problem
//
//  Created by Lei Hsiung on 2020/04/13.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string str = "";
    int n = 0, m = 0;
    while(getline(cin, str))
    {
        if (str[0] - p != 0) continue;
        stringstream ss(str);
        string in;
        for (int i = 0; i < 4; ++i)
        {
            ss >> in;
            if (i < 2) continue;
            else if (i == 2) n = stoi(in); // variable numbers
            else if (i == 3) m = stoi(in); // clause numbers
        }
        break;
    }
    bool sat = true, var[n];
    vector<vector<int> > clause;
    for (int i = 0; i < m; ++i)
    {
        vector<int> tmp(n) = {-1};
        int t;
        cin >> t;
        while (t != 0)
        {
            if (t > 0) tmp[t] = 1;
            else tmp[-t] = 0;
            cin >> t;
        }
        clause.push_back(tmp);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
