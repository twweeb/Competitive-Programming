//
//  B.cpp
//  Codeforces Round #629 - B. K-th Beautiful String
//
//  Created by twweeb on 2020/05/05.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int possComb(int k) { return k+1;}

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int n = 0, k = 0, a_length = 0, cumulative_rank = 0;
        cin >> n >> k;
        while(cumulative_rank + possComb(a_length) < k) 
        {
            cumulative_rank += possComb(a_length);
            a_length++;
        }

        for (int i = 0; i < n-a_length-2; ++i) cout <<'a';
        cout << 'b';
        for (int i = 0; i < possComb(a_length) - (k - cumulative_rank); ++i) cout << 'a';
        cout << 'b';
        for (int i = 0; i < k - cumulative_rank - 1; ++i) cout << 'a';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
