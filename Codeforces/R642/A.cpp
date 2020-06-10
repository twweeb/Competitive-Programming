//
//  A.cpp
//  Codeforces Round #642 - A. Most Unstable Array
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
        int n, m;
        cin >> n >> m;
        if (n == 1) cout << "0\n";
        else if (n == 2) cout << m << '\n';
        else cout << 2*m << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
