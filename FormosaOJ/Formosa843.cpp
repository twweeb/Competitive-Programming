//
//  Formosa843.cpp
//  Extra Chocolate! Chocolate!!
//
//  Created by Lei Hsiung on 5/27/20.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    map<int, int> choco;
    choco[0] = 1<<30; choco[1<<30] = 0;
    long long remain = (long long) n * m;
    while (q--)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        auto it = choco.lower_bound(x); // return an iterator it, and it->first is a key that first larger or equal to x
        if (it->second >= y)
        {
            cout << "QAQ\n";
            continue;
        }
        int cur_bottom = it->second;
        long long cnt = 0LL;
        vector<int> to_removed_pt;
        while (true)
        {
            it--;
            cnt += (long long)(x - it->first) * (min(it->second, y) - cur_bottom);
            cur_bottom = it->second;
            if (it->second <= y) to_removed_pt.push_back(it->first);
            else break;
        }
        for (auto &key: to_removed_pt) choco.erase(key);
        choco[x] = y;
        remain -= cnt;
        cout << cnt << '\n';
    }
    cout << remain << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}