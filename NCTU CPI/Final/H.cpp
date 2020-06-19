//
//  H.cpp
//  NCTU CPI Final
//
//  Created by Lei Hsiung on 2020/06/19.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int P, N;
    cin >> P >> N;
    int p[N+1], s[N+1];
    for(int i=1 ; i<=N ; ++i)
    {
        cin >> p[i] >> s[i];
    }
    int dp[P+1]; // dp[i]:= max value end at p
    for(int i=0 ; i<=P ; ++i)
    {
        dp[i] = 0;
    }
    for(int i=1 ; i<=N ; ++i)
    {
        int max_val = 0;
        for(int j=0 ; j<=p[i] ; ++j)
        {
            max_val = max(max_val, dp[j]);
        }
        if(max_val+s[i] > dp[p[i]])
        {
            dp[p[i]] = max_val+s[i];
        }
    }
    int ans = 0;
    for(int j=0 ; j<=P ; ++j)
    {
        ans = max(ans, dp[j]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
