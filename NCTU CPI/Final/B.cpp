//
//  B.cpp
//  NCTU CPI Final
//
//  Created by Lei Hsiung on 2020/06/19.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> mp;

const int MAX_INT = 214748364;
int goalH, goalT;

int hashing(pair<int, int> &t) { return (t.first+t.second)*(t.first+t.second+1)/2+t.second;}

pair<int, int> op(pair<int, int> t, int opcode)
{
    if (opcode == 1) t.first+=3;
    else if (opcode == 2) 
    {
        t.first-=2;
        t.second+=3;
    }
    else if (opcode == 3) 
    {
        t.first+=2;
        t.second-=1;
    }
    else if (opcode == 4) t.second-=2;
    return t;
}

int bfs()
{
    int H = 0, T = 0;
    queue<pair<int, int>> q;
    unordered_set<int> h;
    if (goalH==0 && goalT==0) return 0;
    q.push({H,T});
    map<pair<int,int>, int> mp;
    mp[{0,0}] = 0;
    h.insert(0);

    int _h = 0;
    while (true)
    {
        pair<int, int> t = q.front();
        q.pop();
        pair<int, int> p;
        int cnt = mp[t];
        for (int i = 1; i <= 4; ++i) 
        {
            if (i == 2 && t.first<2) continue;
            else if (i == 3 && t.second<1) continue;
            else if (i == 4 && t.second<2) continue;
            p = op(t, i);

            if (max(p.first, p.second) >= 1500) continue;
            else if (p.first == goalH && p.second == goalT) return cnt+1;

            _h = hashing(p);
            if (h.find(_h) != h.end()) continue;
            else h.insert(_h);
            q.push(p);
            mp[p] = cnt+1;
        }
    }
}

void solve() {
    int ans;
    cin >> goalH >> goalT;
    cout << bfs() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
