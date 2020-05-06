//
//  A.cpp
//  Codeforces Round #605 - A. Three Friends
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
        int a = 0, b = 0, c = 0, max_p, min_p;
        cin >> a >> b >> c;
        max_p = max(abs(a-b), max(abs(b-c), abs(a-c)));
        if (max_p < 3) cout << "0\n";
        else cout << 2*(max_p-2) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
