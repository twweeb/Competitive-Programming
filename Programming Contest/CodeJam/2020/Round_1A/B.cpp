//
//  B.cpp
//  2020 Google Code Jam Round 1A B. Pascal Walk
//
//  Created by Lei Hsiung on 2021/03/09.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void row_a_to_row_b (int a, int b, bool from_right)
{
    if (b < a) return;
    int cur_col = (from_right) ? a : 1;
    int cur_row = a;
    int cnt = b-a+1;
    cout << cur_row << ' ' << cur_col << '\n';
    for (int i = cnt - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if ((cnt - i) % 2 == 0)
            {
                --cur_row;
                if (from_right) --cur_col;
            }
            else
            {
                ++cur_row;
                if (from_right) ++cur_col;
            }
            cout << cur_row << ' ' << cur_col << '\n';
        }
        if (i == 0) break;
        if (from_right)
        {
            if (cur_row == b) --cur_col;
            else ++cur_row;
        } 
        else
        {
            if (cur_row == b) ++cur_col;
            else 
            {
                ++cur_col;
                ++cur_row;
            }
        }
        cout << cur_row << ' ' << cur_col << '\n';
    }
}

void trace_row (int row, int skip, bool from_right)
{
    int cur_row = row, cur_col = ((from_right) ? (row-skip) : (skip+1));
    for (int i = 0; i < row - skip; ++i)
    {
        cout << cur_row << ' ' << cur_col << '\n';
        cur_col = (from_right) ? (cur_col - 1) : (cur_col + 1);
    }
}

void get_path(int goal)
{
    int cur_row = 1, cur_col = 1, goal_copy = goal, row_cnt = 1;
    vector<int> required_rows;
    while (goal_copy)
    {
        if (goal_copy % 2 == 1) required_rows.push_back(row_cnt);
        ++row_cnt;
        goal_copy >>= 1;
    }
    bool go_right = true;
    
    for (auto r: required_rows)
    {
        if (r == cur_row)
        {
            trace_row (r, r - cur_row, go_right);
        }
        else
        {
            row_a_to_row_b (cur_row, r - 1, go_right);
            trace_row (r, r - cur_row, go_right);
        }
        go_right = !go_right;
        cur_row = r + 1;
    }
    cout << '\n';
    required_rows.clear();
}

void case_solve()
{
    int goal;
    cin >> goal;
    get_path(goal);
}

void solve() {
    int nCases;
    cin >> nCases;
    for (int i = 1; i <= nCases; ++i)
    {
        cout << "Case #" << i << ":\n" ;
        case_solve();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
