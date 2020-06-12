//
//  B.cpp
//  Codeforces Round #595 - B2. Books Exchange (hard version)
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
        int n;
        cin >> n;
        vector<int> rep(n,0);
        
        int mp_num = 1, t, arr[n];
        map<int, int> mp;
        for (int i = 0; i < n; ++i) 
        {
            cin >> t;
            arr[i] = t-1;
        }
        for (int i = 0; i < n; ++i)
        {
            if (rep[i]) continue;
            int cnt = 1, j = i, start = i;
            while (arr[j]!=start)
            {
                rep[j] = mp_num;
                j = arr[j];
                cnt++;
            }
            rep[j] = mp_num;
            mp[mp_num++] = cnt;
        }
        for (int i = 0; i < n; ++i) cout << mp[rep[i]] << ((i!=n-1) ? ' ' : '\n');
        mp.clear();
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
