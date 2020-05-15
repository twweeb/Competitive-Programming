//
//  D.cpp
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/15.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > maze;

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

void solve() {
    int m, n, p, sx, sy, ex, ey;
    cin >> m >> n >> p;
    for(int i=0 ; i<m ; ++i)
    {
        vector<int> row;
        vector<bool> row_v;
        for(int j=0 ; j<n ; ++j)
        {
            int in;
            cin >> in;
            row.push_back(in);
        }
        maze.push_back(row);
    }
    cin >> sx >> sy >> ex >> ey;
    sx--;
    sy--;
    ex--;
    ey--;
    int l = 0, r = 1000000000, ans = 1000000000;
    while(l <= r)
    {
        int dist[m][n];
        for(int i=0 ; i<m ; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                dist[i][j] = 1000000;
            }
        }
        int mid = (l+r)/2;

        queue<pair<int, int> > Q;
        Q.push(make_pair(sx, sy));
        dist[sx][sy] = 0;
        while(!Q.empty())
        {
            int x = Q.front().first, y = Q.front().second;
            Q.pop();
            for(int i=0 ; i<4 ; ++i)
            {
                int nx = x+dx[i], ny = y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n)
                {
                    if(abs(maze[nx][ny]-maze[x][y]) <= mid)
                    {
                        if(dist[x][y] < dist[nx][ny])
                        {
                            dist[nx][ny] = dist[x][y];
                            Q.push(make_pair(nx, ny));
                        }
                    }
                    else
                    {
                        if(dist[x][y]+1 < dist[nx][ny])
                        {
                            dist[nx][ny] = dist[x][y]+1;
                            Q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
        bool valid = false;
        if(dist[ex][ey]<=p)
        {
            valid = true;
        }
        if(valid)
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
