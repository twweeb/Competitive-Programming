//
//  B.cpp
//  NCTU CPI Quiz 2
//
//  Created by Lei Hsiung on 2020/04/24.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int inf = 1<<29;

void bfs(int nButtons, int goal)
{
    vector<int> button(nButtons);
    map<int, int> step;
    for(int i = 0; i < nButtons; ++i) cin >> button[i];
    queue<int> q;

    q.push(0);
    step[0] = 0;
    int p = 0, cur = 0;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i : button)
        {
            cur = (p + i < 0) ? 0 : (p + i > 3600) ? 3600 : p + i;
            if (step.find(cur) != step.end()) continue;
            step[cur] = step[p] + 1;
            q.push(cur);
            if (cur == goal) break;
        }
        if (cur == goal) break;
    }
    for(int i = goal; i<=3600; ++i)
    {
        if(step.find(i) != step.end())
        {
            cout << step[i] << " " << i - goal << endl;
            break;
        }
    }
}


void solve() {
    int nCases;
    cin >> nCases;
    while(nCases --)
    {
        int nButtons, goal;
        cin >> nButtons >> goal;
        bfs(nButtons, goal);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
