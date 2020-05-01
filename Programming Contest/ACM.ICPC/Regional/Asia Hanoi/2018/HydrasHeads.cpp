//
//  E.cpp
//  NCTU CPI Quiz 2
//
//  Created by Lei Hsiung on 2020/04/24.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> mp;
int MAX_INT = 214748364;

int dfs(int H, int T)
{
    int cnt = MAX_INT;
    if(mp.find({H,T}) != mp.end()) return mp[{H, T}];
    if(H < 3 && T < 3) cnt = min(dfs(H, T+1), cnt);
    if(T > 1) cnt = min(dfs(H+1, T-2), cnt);
    if(H > 1) cnt = min(dfs(H-2, T), cnt);
    mp[{H,T}] = ++cnt;
    return cnt;
}

void solve() {
    int H, T, ans;
    cin >> H >> T;
    mp[{1,0}] = MAX_INT; mp[{0,0}] = 0; mp[{2,0}] = 1; mp[{1,2}] = 2; mp[{0,4}] = 3;
    while(H != 0 || T != 0) 
    {
        ans = dfs(H, T);
        if(ans == MAX_INT) cout << "-1" << endl;
        else cout << ans << endl;
        cin >> H >> T;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
