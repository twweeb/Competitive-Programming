//
//  A.cpp
//  NCTU CPI Quiz 2
//
//  Created by Lei Hsiung on 2020/04/24.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;
int floors, start, goals, up, down, cnt;
bool isSolve = false;

void bfs()
{
    if(start == goals) 
    {
        isSolve = true;
        cnt = 0;
        return;
    }

    vector<bool> visit(floors+1);
    vector<int> adj(floors+1), step(floors+1);
    queue<int> q;
    int cur = start;

    for (int i = 1; i < floors+1; ++i) 
    {
        visit[i] = false;
        adj[i] = 0;
        step[i] = 0;
    }
    visit[cur] = true;
    step[cur] = 0;
    adj[cur] = cur;

    if (cur + up <= floors) 
    {
        q.push(cur + up);
        adj[cur + up] = cur;
    }
    if (cur - down >= 1) 
    {
        q.push(cur - down);
        adj[cur - down] = cur;
    }
    while (!q.empty())
    {
        cur = q.front();
        if (cur == goals) 
        {
            cnt = step[adj[cur]] + 1;
            isSolve = true;
            return;
        }
        q.pop();

        if (visit[cur]) continue;
        else
        {
            visit[cur] = true;
            step[cur] = 1+step[adj[cur]];
            //cout << step[adj[cur]] << "+10 = " << step[cur]<<endl;
            if (cur + up <= floors) 
            {
                q.push(cur + up);
                if(adj[cur+up] == 0)
                {
                    adj[cur+up] = cur;
                } 
            }
            if (cur - down >= 1) 
            {
                q.push(cur - down);
                if(adj[cur-down] == 0) adj[cur-down] = cur;
            }
        }
    }
}


void solve() {
    cin >> floors >> start  >> goals >> up >> down;
    bfs();
    if(isSolve) cout << cnt << endl;
    else cout << "use the stairs" <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}