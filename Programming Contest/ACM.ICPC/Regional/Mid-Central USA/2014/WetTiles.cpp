//
//  C.cpp
//  NCTU CPI Quiz 2
//
//  Created by Lei Hsiung on 2020/04/24.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void minutes(int X, int Y, int T, int L, int W)
{
    int inf = X*Y;
    vector<vector<int> > mat(Y), step(Y), visit(Y); //mat 0: leak, -1: wall, -2: unset
    queue<pair<int, int> > q;
    int l_x, l_y, w_sx, w_sy, w_ex, w_ey, cnt = L;
    for(int i = 0; i < Y; ++i) 
    {
        mat[i].reserve(X);
        step[i].reserve(X);
        visit[i].reserve(X);
    }
    for(int i = 0; i < Y; ++i)
    {
        for(int j = 0; j < X; ++j) 
        {
            mat[i][j] = -2;
            step[i][j] = inf;
            visit[i][j] = false;
        }
    }
    for(int i = 0; i < L; ++i)
    {
        cin >> l_x >> l_y;
        l_x -= 1; l_y -= 1;
        q.push(make_pair(l_y,l_x));
        mat[l_y][l_x] = 0;
        step[l_y][l_x] = 1;
    }

    for(int i = 0; i < W; ++i)
    {
        cin >> w_sx >> w_sy >> w_ex >> w_ey;
        w_sx -= 1; w_sy -= 1; w_ex -= 1; w_ey -= 1;
        int cur_x = w_sx, cur_y = w_sy;
        if(abs(w_sx-w_ex) == abs(w_sy-w_ey))
        {
            int i_x = (w_ex-w_sx > 0) ? 1 : -1, i_y = (w_ey-w_sy > 0) ? 1 : -1;;
            while(cur_x != w_ex)
            {
                mat[cur_y][cur_x] = -1;
                visit[cur_y][cur_x] = true;
                cur_x+=i_x;
                cur_y+=i_y;
            }
            mat[cur_y][cur_x] = -1;
            visit[cur_y][cur_x] = true;
        }
        else
        {
            if(abs(w_sx-w_ex)>0)
            {
                int i_x = (w_ex-w_sx > 0) ? 1 : -1;
                while(cur_x != w_ex)
                {
                  mat[cur_y][cur_x] = -1;
                  visit[cur_y][cur_x] = true;
                  cur_x+=i_x;
                }
                mat[cur_y][cur_x] = -1;
                visit[cur_y][cur_x] = true;
            }
            else
            {
                int i_y = (w_ey-w_sy > 0) ? 1 : -1;
                while(cur_y != w_ey)
                {
                    mat[cur_y][cur_x] = -1;
                    visit[cur_y][cur_x] = true;
                    cur_y+=i_y;
                }
                mat[cur_y][cur_x] = -1;
                visit[cur_y][cur_x] = true;
            }
        }
    }

    pair<int, int> p;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if (visit[p.first][p.second] || step[p.first][p.second] == T) continue;
        else
        {
            visit[p.first][p.second] = true;
            if(p.first - 1 != -1 && mat[p.first - 1][p.second] == -2) 
            {
                cnt ++;
                mat[p.first - 1][p.second] = 0;
                q.push(make_pair(p.first - 1, p.second));
                step[p.first - 1][p.second] = (step[p.first - 1][p.second] == inf) ? step[p.first][p.second] + 1 : inf;
            }
            if(p.first + 1 != Y && mat[p.first + 1][p.second] == -2) 
            {
                cnt ++;
                mat[p.first + 1][p.second] = 0;
                q.push(make_pair(p.first + 1, p.second));
                step[p.first + 1][p.second] = (step[p.first + 1][p.second] == inf) ? step[p.first][p.second] + 1 : inf;
            }
            if(p.second - 1 != -1 && mat[p.first][p.second - 1] == -2)
            {
                cnt ++;
                mat[p.first][p.second - 1] = 0;
                q.push(make_pair(p.first, p.second - 1));
                step[p.first][p.second - 1] = (step[p.first][p.second - 1] == inf) ? step[p.first][p.second] + 1 : inf;
            }
            if(p.second + 1 != X && mat[p.first][p.second + 1] == -2)
            {
                cnt ++;
                mat[p.first][p.second + 1] = 0;
                q.push(make_pair(p.first, p.second + 1));
                step[p.first][p.second + 1] = (step[p.first][p.second + 1] == inf) ? step[p.first][p.second] + 1 : inf;
            }
        }
    }
    cout << cnt << endl;
    mat.clear(); step.clear(); visit.clear();
}

void solve() {
    int X, Y, T, L, W;
    cin >> X;
    while(X != -1)
    {
        cin >> Y >> T >> L >> W;
        minutes(X, Y, T, L, W);
        cin >> X;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
