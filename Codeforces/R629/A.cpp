//
//  A.cpp
//  Codeforces Round #629 - A. Divisibility Problem
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
        int a, b;
        cin >> a >> b;
        if (a%b == 0) cout << "0\n";
        else cout << b - a%b << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
