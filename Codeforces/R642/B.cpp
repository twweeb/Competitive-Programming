//
//  B.cpp
//  Codeforces Round #642 - B. Two Arrays And Swaps
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        
        int a_i = n - 1, b_i = n - 1, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[a_i]>=b[b_i] || k == 0)
            {
                sum += a[a_i];
                a_i--;
            }
            else
            {
                sum+=b[b_i];
                b_i--;
                k--;
            }
        }
        cout << sum << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
