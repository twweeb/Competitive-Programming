//
//  A.cpp
//  Codeforces Round #634 - A. Candies and Two Sisters
//
//  Created by twweeb on 2020/04/13.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int n, cnt = 0;
        cin >> n;
        if (n == 1) cout << "0\n";
        else if (n == 2) cout << "0\n";
        else cout << (int) ((n-1)/2) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
