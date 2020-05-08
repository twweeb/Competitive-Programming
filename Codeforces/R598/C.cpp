//
//  C.cpp
//  Codeforces Round #598 - C. Platforms Jumping
//
//  Created by twweeb on 2020/05/06.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m ,d, total_wooden_len = 0;
    cin >> n >> m >> d;
    vector<int> c(m+1);
    for (int i = 1; i <= m; ++i) 
    {
        cin >> c[i];
        total_wooden_len += c[i];
    }
    if ((m+1)*(d-1) + total_wooden_len < n) cout << "NO\n";
    else
    {
        cout << "YES\n";
        int c_i = 1;
        while (total_wooden_len <= n)
        {
            int blank = min(n - total_wooden_len, d-1);
            total_wooden_len += blank;

            for (int i = 0; i < blank; ++i)
            {
                if (c_i == 1 && i == 0) cout << "0";
                else cout << " 0";
            }
            if (c_i <= m)
            {
                for (int i = 0; i < c[c_i]; ++i) cout << " " << c_i;
                c_i ++;
            }
            else break;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
