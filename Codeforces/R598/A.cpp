//
//  A.cpp
//  Codeforces Round #598 - A. Payment Without Change
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
        long long a = 0, b = 0, n = 0, S = 0;
        cin >> a >> b >> n >> S;
        if (a*n+b < S) cout << "NO\n";
        else if (a*n+b == S) cout << "YES\n";
        else if (S%n > b) cout << "NO\n";
        else cout << "YES\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
