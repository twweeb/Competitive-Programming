//
//  C.cpp
//  Codeforces Round #644 - C. Similar Pairs
//
//  Created by twweeb on 2020/06/11.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int n, t, odd_num = 0, even_num = 0;
        unordered_set<int> odd, even;
        odd.clear(); even.clear();
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> t;
            if (t&1) 
            {
                odd.insert(t);
                odd_num++;
            }
            else 
            {
                even.insert(t);
                even_num++;
            }
        }
        bool isdivisible = false;
        if (odd_num&1)
        {
            for (auto z: odd)
            {
                if (even.find(z+1)!= even.end() || even.find(z-1)!=even.end())
                {
                    isdivisible = true;
                    break;
                }
            }
        }
        else isdivisible = true;
        cout << ((isdivisible) ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
