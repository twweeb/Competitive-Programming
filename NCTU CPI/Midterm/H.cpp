//
//  H.cpp
//  Concept: Segement Tree, Map
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/27.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int bit[1000001], n = 0;

void update(int x, int y) {
    for(int pos = x; pos <= n && bit[pos] < y; pos += pos & -pos)
        bit[pos] = y;
}

int query(int x) {
    int res = 0;
    for(int pos = x; pos > 0; pos -= pos & -pos)
        res = max(res, bit[pos]);
    return res;
}

void solve() {
    cin >> n;
    vector<int> cmd(n), y(n);
    vector<long long> timestamp(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> cmd[i] >> timestamp[i];
        if (cmd[i] == 1) cin >> y[i];
    }

    vector<long long> sorted_time = timestamp;
    sort(sorted_time.begin(), sorted_time.end());

    for(int i = 0; i < n; ++i)
    {
        int x = 1 + (lower_bound(sorted_time.begin(), sorted_time.end(), timestamp[i]) - sorted_time.begin());
        if (cmd[i] == 1) update(x, y[i]);
        else cout << query(x) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
