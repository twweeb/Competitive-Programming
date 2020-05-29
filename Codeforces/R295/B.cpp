//
//  R295.B.cpp
//  CodeForces Round #295 (Div. 2) B. Two Buttons
//
//  Created by Magic Bear on 2020/04/30.
//  Copyright © 2020 Magic Bear. All rights reserved.
//
 
#include <bits/stdc++.h>

using namespace std;

int inf = 1<<29;

int bfs(int n, int m)
{
    map<int, int> dist;
    queue<int> q;
    q.push(n*2); q.push(n-1);
    dist[n] = 0; dist[n*2] = 1; dist[n-1] = (n-1 == 0) ? inf : 1;
    if (m == n || m == n-1 || m == 2*n) return dist[m];
    int max_over = inf;
    while(!q.empty())
    {
        int p = q.front();
        if (p-1 == m || 2*p == m) return dist[p] + 1;
        q.pop();
        if (p > max_over) continue;
        else if (p > m) max_over = min(p, max_over);
        if (p*2 < max_over && dist.find(p*2) == dist.end()) 
        {
            q.push(p*2);
            dist[p*2] = dist[p] + 1;
        }
        if (p-1 < max_over && dist.find(p-1) == dist.end()) 
        {
            q.push(p-1);
            dist[p-1] = dist[p] + 1;
        }
    }
    return inf;
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << bfs(n, m) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
