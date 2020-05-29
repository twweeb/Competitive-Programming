//
//  OceansAnti-11.cpp
//  Concept: Pre-generate a map.
//  2016 Atlantic Canadian Preliminary Contest
//
//  Created by Lei Hsiung on 2020/05/13.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int mod(int x)
{
    uint64_t MOD_P = 1e9+7;
    return x % MOD_P;
}

void solve() {
    int nCases, N;
    cin >> nCases;
    int anti11[10001] = {0};
    anti11[0] = 1; anti11[1] = 2;
    for (int i = 2; i < 10001; ++i) anti11[i] = mod(anti11[i-1] + anti11[i-2]);
    while(nCases--)
    {
        cin >> N;
        cout << anti11[N] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
