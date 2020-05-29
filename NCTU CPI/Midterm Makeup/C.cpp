//
//  C.cpp
//  NCTU CPI Midterm Makeup
//
//  Created by Lei Hsiung on 2020/05/29.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

long long modPow(long long a, long long p, long long mod)
{
    if (p == 0) return 1;
    if (p == 1) return a%mod;
    if (p % 2 == 0)
    {
        long long t = modPow(a, p/2, mod);
        return (t*t)%mod;
    }
    else 
    {
        long long t = modPow(a, (p-1)/2, mod);
        return ((a%mod) * t * t)%mod;
    }
}

void solve() {
    int n = 0;
    cin >> n;
    while (n--)
    {
        long long b, n, m;
        cin >> b >> n >> m;
        long long ans = 0LL;
        b %= m;
        for (int i = 1; i <= n; ++i)
        {
            cout << i << endl;
            ans += ((i%m) * modPow(b,i,m));
            ans %= m;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
