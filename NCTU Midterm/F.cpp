//
//  F.cpp
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/15.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int T;
    cin >> T;
    while(T--)
    {
        int n, m, t;
        cin >> n >> m >> t;
        int cnt = 1;
        cout << 1;
        n--;
        while(n--)
        {
            if(cnt==m)
            {
                cnt=0;
            }
            if(cnt==m-1)
            {
                cout << " " << t-m+1;
            }
            else
            {
                cout << " 1";
            }
            cnt++;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
