//
//  A.cpp
//  NCTU CPI Midterm Makeup
//
//  Created by Lei Hsiung on 2020/05/29.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > op(vector<vector<int> > &mat, int opcode, bool ClockWise)
{
    vector<vector<int> > new_mat = mat;
    int i = opcode/3, j =opcode%3;
    if (ClockWise) 
    {
        new_mat[i+0][j+0] = mat[i+1][j+0]; new_mat[i+0][j+1] = mat[i+0][j+0]; new_mat[i+1][j+1] = mat[i+0][j+1]; new_mat[i+1][j+0] = mat[i+1][j+1];
    }
    else 
    {
        new_mat[i+1][j+0] = mat[i+0][j+0]; new_mat[i+0][j+0] = mat[i+0][j+1]; new_mat[i+0][j+1] = mat[i+1][j+1]; new_mat[i+1][j+1] = mat[i+1][j+0];
    }
    return new_mat;
}

long long _hash(vector<vector<int> > &mat)
{
    long long l = 0LL;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            l = (l << 4) + (mat[i][j]-1);
    return l;
}

void show(vector<vector<int> > &mat) //For debug
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "--------------------------\n";
}

void bfs (vector<vector<int> > &cur, vector<vector<int> > &goal)
{
    if (_hash(cur) == _hash(goal)) { cout << "0\n"; return; }
    queue<vector<vector<int> >> head, back;
    unordered_set<long long> hVisited, bVisited;
    head.push(cur); back.push(goal);
    hVisited.insert(_hash(cur));
    bVisited.insert(_hash(goal));
    int step = 1;
    long long hashed = 0LL;
    while (true)
    {
        int p = head.size(), q = back.size();
        while (p--)
        {
            vector<vector<int> > p = head.front();
            head.pop();
            for (int j = 0; j < 9; ++j)
            {
                vector<vector<int> > t = op(p, j, true);
                hashed = _hash(t);
                if (bVisited.find(hashed) != bVisited.end())
                {
                    cout << step << '\n';
                    return;
                }
                else if (hVisited.find(hashed) == hVisited.end())
                {
                    head.push(t);
                    hVisited.insert(hashed);
                }
            }
        }
        step++;
        while (q--)
        {
            vector<vector<int> > p = back.front();
            back.pop();
            for (int j = 0; j < 9; ++j)
            {
                vector<vector<int> > t = op(p, j, false);
                hashed = _hash(t);
                if (hVisited.find(hashed) != hVisited.end())
                {
                    cout << step << '\n';
                    return;
                }
                else if (bVisited.find(hashed) == bVisited.end())
                {
                    back.push(t);
                    bVisited.insert(hashed);
                }
            }
        }
        if(step++ == 10) break;
    }
    cout << "HARD ARIES\n";
}

void solve() {
    int n = 0;
    cin >> n;
    while (n--)
    {
        vector<vector<int> > orig(4, vector<int>(4)), goal(4, vector<int>(4));
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                cin >> orig[i][j];
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                goal[i][j] = i*4+j+1;
        bfs(orig, goal);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
