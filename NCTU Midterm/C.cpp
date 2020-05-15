//
//  C.cpp  (This was WA.)
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/15.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int leftmost[501] = {0}, upmost[501] = {0}, k;

pair<int, int> pointer_reset(vector<vector<int>> &mat)
{
    for (int j = 0; j < mat[0].size(); ++j)
        for (int i = 0; i < mat.size(); ++i)
            if (mat[i][j] == 1) 
            {
                return make_pair(i, j);
            }
    return {-1, -1};
}

pair<int, int> right_shift(vector<vector<int>> &mat, int x, int y)
{
    if (leftmost[x] < 0) return {-1,-1};
    if (y + k < mat[x].size())
    {
        bool fail = false;
        for (int i = 1; i <= k; ++i) 
        {
            if (mat[x][y+i] == 0)
            {
                y = leftmost[x];
                fail = true;
                break;
            }
        }
        if (!fail) y += k;
    }
    else y = leftmost[x];
    return make_pair(x,y);
}

pair<int, int> down_shift(vector<vector<int>> &mat, int x, int y)
{
    if (upmost[y] < 0) return {-1,-1};
    if (x + k < mat.size())
    {
        bool fail = false;
        for (int i = 1; i <= k; ++i) 
        {
            if (mat[x+i][y] == 0)
            {
                x = upmost[y];
                fail = true;
                break;
            }
        }
        if (!fail) x += k;
    }
    else x = upmost[y];
    return make_pair(x,y);
}

void show(int x, int y, vector<vector<int>> &mat)
{
    cout << x << ' ' << y << '\n';
    for (int i = 0; i < mat.size(); ++i)
    {
        for(int j = 0; j < mat[i].size(); ++j)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
}

void update_most(vector<vector<int>> &mat, int x, int y)
{
    leftmost[x] = -1; upmost[y] = -1;
    for (int j = mat[x].size()-1; j >= 0; --j)
    {
        if (mat[x][j] == 1) leftmost[x] = j;
    }
    for (int i = mat.size()-1; i >= 0; --i)
    {
        if (mat[i][y] == 1) upmost[y] = i;
    }
}

void remove_p(vector<vector<int>> &mat, int x, int y)
{
    mat[x][y] = 0;
    update_most(mat,x,y);
}

void solve() {
    int r, c;
    cin >> r >> c >> k;
    vector<vector<int>> mat(r,vector<int>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            mat[i][j] = 1;

    int cnt = 0;
    pair <int, int> cur = {0,0};
    while (true)
    {
        //show(cur.first, cur.second, mat);
        cur = right_shift(mat, cur.first, cur.second);
        remove_p(mat, cur.first, cur.second);
        cur = right_shift(mat, cur.first, cur.second);
        //cout << cur.first << ' ' << cur.second << '\n';
        if (cur.first == -1) cur = pointer_reset(mat);
        if (++cnt == r*c - 1) break;
        
        //show(cur.first, cur.second, mat);
        cur = down_shift(mat, cur.first, cur.second);
        remove_p(mat, cur.first, cur.second);
        cur = down_shift(mat, cur.first, cur.second);
        //cout << cur.first << ' ' << cur.second << '\n';
        if (cur.first == -1) cur = pointer_reset(mat);
        if (++cnt == r*c - 1) break;
    }
    //show(cur.first, cur.second, mat);
    cout << cur.first << ' ' << cur.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
