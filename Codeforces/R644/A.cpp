//
//  A.cpp
//  Codeforces Round #644 - A. Minimal Square
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
        int a, b, t;
        cin >> a >> b;
        t = a;
        a = min(t, b);
        b = max(t, b);
        if (a+a >= b) cout <<  pow(a+a, 2) << '\n';
        else cout << pow(b, 2) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
