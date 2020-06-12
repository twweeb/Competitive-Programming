//
//  A.cpp
//  Codeforces Round #595 - A. Yet Another Dividing into Teams
//
//  Created by twweeb on 2020/06/13.
//  Copyright © 2020 twweeb. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int n, t;
        cin >> n;
        set<int> odd, even;
        odd.clear(); even.clear();
        for (int i = 0; i < n; ++i)
        {
            cin >> t;
            if (t&1) odd.insert(t);
            else even.insert(t);
        }
        bool split = false;
        if (!odd.empty() && !even.empty())
        {
            if (odd.size() <= even.size())
            {
                for (auto z:odd)
                {
                    if (even.find(z-1) != even.end() || even.find(z+1) != even.end())
                    {
                        split = true;
                        break;
                    }
                }
            }
            else
            {
                for (auto z:even)
                {
                    if (odd.find(z-1) != odd.end() || odd.find(z+1) != odd.end())
                    {
                        split = true;
                        break;
                    }
                }
            }
        }

        cout << ((split) ? "2\n" : "1\n");
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
