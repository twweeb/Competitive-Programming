//
//  B.cpp
//  Codeforces Round #644 - B. Honest Coach
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
        int n;
        cin >> n;
        int prev, cur, min_diff = 1<<29;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 1; i < n; ++i) min_diff = min(min_diff, a[i] - a[i-1]);
        cout << min_diff << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
