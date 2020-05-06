//
//  Grid.cpp
//  2015 Southeast USA Regionals Division 1
//
//  Created by Lei Hsiung on 2020/05/01.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > maze;

int bfs(int x, int y)
{
    map<pair<int,int>, int> step;
    queue<pair<int,int> > q;
    q.push(make_pair(0,0)); step[{0,0}] = 0;
    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        //cout << p.first << " " << p.second << endl;
        if (p.first == x-1 && p.second == y-1) break;
        if (p.first - maze[p.first][p.second] >= 0 && step.find({p.first - maze[p.first][p.second],p.second}) == step.end())
        {
            step[{p.first - maze[p.first][p.second],p.second}] = step[{p.first, p.second}] + 1;
            q.push(make_pair(p.first - maze[p.first][p.second],p.second));
        }
        if (p.first + maze[p.first][p.second] < x && step.find({p.first + maze[p.first][p.second],p.second}) == step.end())
        {
            step[{p.first + maze[p.first][p.second],p.second}] = step[{p.first, p.second}] + 1;
            q.push(make_pair(p.first + maze[p.first][p.second],p.second));
        }
        if (p.second - maze[p.first][p.second] >= 0 && step.find({p.first,p.second - maze[p.first][p.second]}) == step.end())
        {
            step[{p.first,p.second - maze[p.first][p.second]}] = step[{p.first, p.second}] + 1;
            q.push(make_pair(p.first,p.second - maze[p.first][p.second]));
        }
        if (p.second + maze[p.first][p.second] < y && step.find({p.first,p.second + maze[p.first][p.second]}) == step.end())
        {
            step[{p.first,p.second + maze[p.first][p.second]}] = step[{p.first, p.second}] + 1;
            q.push(make_pair(p.first,p.second + maze[p.first][p.second]));
        }
    }
    if (step.find({x-1,y-1}) != step.end()) return step[{x-1,y-1}];
    else return -1;
}

void solve() {
    int x, y;
    string str;
    cin >> x >> y;
    maze.reserve(x);
    for (int i = 0; i < x; ++i)
    {
        maze[i].reserve(y);
        cin >> str;
        for (int j = 0; j < y; ++j) maze[i][j] = str[j] - '0';
    }
    cout << bfs(x,y) <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
