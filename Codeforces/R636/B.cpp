//
//  B.cpp
//  Codeforces Round #636 - B. Balanced Array
//
//  Created by twweeb on 2020/05/05.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int n = 0;
        cin >> n;
        if (n%4 != 0) cout << "NO\n";
        else
        {
            cout << "YES\n";
            int sum = 0;
            for (int i = 1; i <= n/2; ++i) 
            {
                cout << 2*i << " ";
                sum += 2*i;
            }
            for (int i = 1; i < n/2; ++i) 
            {
                cout << 2*i-1 << " ";
                sum -= 2*i-1;
            }
            cout << sum << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
