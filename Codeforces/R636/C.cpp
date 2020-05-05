//
//  C.cpp
//  Codeforces Round #636 - C. Alternating Subsequence
//
//  Created by twweeb on 2020/05/05.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

bool isChangeSign(int a, int b)
{
    return ((a<0)&(b>0))|((a>0)&(b<0));
}

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int n = 0, cur_max = 0, prev = 0, cur = 0;
        long long sum = 0LL;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> cur;
            if (i == 0 || isChangeSign(cur, prev))
            {
                sum += cur_max;
                cur_max = cur;
            }
            else cur_max = max(cur_max, cur);
            
            prev = cur;
        }
        cout << sum+cur_max << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
