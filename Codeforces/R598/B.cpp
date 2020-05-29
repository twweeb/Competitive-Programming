//
//  B.cpp
//  Codeforces Round #598 - B. Minimize the Permutation
//
//  Created by twweeb on 2020/05/06.
//  Copyright © 2020 twweeb. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int n = 0, watch = 1, cur = 0;
        cin >> n;
        vector<int> a(n);
        set<int> passd;
        vector<int>::iterator front_pos = a.begin();
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (auto it = a.begin(); it != a.end(); ++it)
        {
            passd.insert(*it);
            if(*it == watch) 
            {
                if (it != front_pos && front_pos != a.end())
                {
                    //it = a.erase(it);
                    a.insert(front_pos, watch);
                    //front_pos = it;
                    cout << "tmp\n";
                }
                else if (front_pos != a.end()) front_pos++;
            }
                    cout << "tmp2\n";
            while (passd.find(watch) != passd.end())
            {
                if(watch == n)
                {
                    watch = -1;
                    break;
                }
                watch ++;
            }
        }
        cout << "wow\n";
        for (int i = 0; i < n; ++i) 
        {
            if (i==0) cout << a[0];
            else cout << " " << a[i];
        }
        cout << " \n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
