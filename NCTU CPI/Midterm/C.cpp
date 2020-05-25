//
//  C.cpp
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/25.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int leftmost[500] = {0}, upmost[500] = {0}, rowCnt[500] = {0}, colCnt[500] = {0};
int r, c;

void pointer_reset(vector<vector<int>> &mat, pair<int, int> &pos)
{
    for (int j = 0; j < c; ++j)
    {
        if (upmost[j] != -1)
        {
            pos.first = upmost[j];
            pos.second = j;
            return;
        }
    }
}

void right_shift(vector<vector<int>> &mat, pair<int, int> &pos)
{
    if (pos.second + 1 < c)
    {
        ++pos.second;
        while (mat[pos.first][pos.second] != 1) 
        // Notice that the pointer will omit the removed pointer, and point to the next remaining!! 
        {
            if (pos.second + 1 < c)
                ++pos.second;
            else 
            {
                pos.second = leftmost[pos.first];
                return;
            }
        }
    }
    else pos.second = leftmost[pos.first];
}

void down_shift(vector<vector<int>> &mat, pair<int, int> &pos)
{
    if (pos.first + 1 < r)
    {
        ++pos.first;
        while (mat[pos.first][pos.second] != 1)
        // Notice that the pointer will omit the removed pointer, and point to the next remaining!!
        {
            if (pos.first + 1 < r)
                ++pos.first;
            else 
            {
                pos.first = upmost[pos.second];
                return;
            }
        }
    }
    else pos.first = upmost[pos.second];
}

void update(vector<vector<int>> &mat, pair<int, int> &pos)
{
    int x = pos.first, y = pos.second;
    --rowCnt[x]; --colCnt[y];
    if (rowCnt[x] != 0)
    {
        if (y==leftmost[x])
        for (int j = leftmost[x]; j < c; ++j)
            if (mat[x][j] == 1) 
            {
                leftmost[x] = j;
                break;
            }
    }
    else leftmost[x] = -1;

    if (colCnt[y] != 0)
    {
        if (x==upmost[y])
        for (int i = upmost[y]; i < r; ++i)
            if (mat[i][y] == 1) 
            {
                upmost[y] = i;
                break;
            }
    }
    else upmost[y] = -1;
}

void remove_p(vector<vector<int>> &mat, pair<int, int> &pos)
{
    // Debug Purpose
    // cout << "remove " << pos.first << ' ' << pos.second << '\n';
    mat[pos.first][pos.second] = 0;
    update(mat, pos);
}

void show(pair<int, int> &pos, vector<vector<int>> &mat) //For Debug
{
    cout << "point to " << pos.first << ' ' << pos.second << '\n';
    cout << "     ";
    for (int i = 0; i < c; ++i)
        cout << upmost[i] << ' ';
    cout << "\n-------------------------\n";
    for (int i = 0; i < r; ++i)
    {
        cout << leftmost[i] << "  | ";
        for(int j = 0; j < c; ++j)
        {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    int k;
    cin >> r >> c >> k;
    vector<vector<int>> mat(r,vector<int>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            mat[i][j] = 1;
    for (int i = 0; i < r; ++i) rowCnt[i] = c;
    for (int i = 0; i < c; ++i) colCnt[i] = r;
    int cnt = 0, stop = r*c-1;
    pair <int, int> cur = {0,0};
    if (stop != 0)
    {
        while (true)
        {
            for (int i = 0; i < k; ++i) right_shift(mat, cur);
            remove_p(mat, cur);
            if (rowCnt[cur.first] != 0) right_shift(mat, cur);
            else pointer_reset(mat, cur);
            if (++cnt == stop) break;
            //show(cur, mat);
            
            for (int i = 0; i < k; ++i) down_shift(mat, cur);
            remove_p(mat, cur);
            if (colCnt[cur.second] != 0) down_shift(mat, cur);
            else pointer_reset(mat, cur);
            if (++cnt == stop) break;
            //show(cur, mat);
        }
    }
    cout << cur.first << ' ' << cur.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
