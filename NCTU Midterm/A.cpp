//
//  A.cpp  (This would cause TLE.)
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/15.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0 , k = 0;
    cin >> n >> k;
    vector <int> a(n), b(n);
    int cost = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i)
    {
        int tmp = b[i];
        for (int j = 0; j < a.size(); ++j)
        {
            if (a[j] == b[i]) 
            {
                a.erase (a.begin()+j);
                break;
            }
            cost += ((tmp%k) + (a[j]%k))%k ;
        }
    }
    cout << cost << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
