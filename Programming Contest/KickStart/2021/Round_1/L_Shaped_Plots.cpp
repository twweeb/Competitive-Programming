//
//  L_Shaped_Plots.cpp
//  2021 Google Kick Start Round 1, L Shaped Plots
//
//  Created by Lei Hsiung on 2021/04/14.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define INF 1<<30

void compute_available(vector<vector<int>>& mat, 
                        vector<vector<int>>& up, vector<vector<int>>& right, 
                        vector<vector<int>>& down, vector<vector<int>>& left)
{
    int R = mat.size(), C = mat[0].size();
    for (int i = 0; i < R; ++i)
    {
        if (i == 0)
        {
            for (int j = 0; j < C; ++j) 
                if(mat[i][j]) up[i][j] = 1;
            for (int j = C-1; j >= 0; --j) 
                if(mat[R-1-i][j]) down[R-1-i][j] = 1;
        }
        else
        {
            for (int j = 0; j < C; ++j)
                if (mat[i][j]) up[i][j] = up[i-1][j] + 1;
            for (int j = C-1; j >= 0; --j) 
                if(mat[R-1-i][j]) down[R-1-i][j] = down[R-i][j] + 1;
        }
    }
    for (int j = 0; j < C; ++j)
    {
        if (j == 0)
        {
            for (int i = 0; i < R; ++i) 
                if(mat[i][j]) left[i][j] = 1;
            for (int i = R-1; i >= 0; --i) 
                if(mat[i][C-1-j]) right[i][C-1-j] = 1;
        }
        else
        {
            for (int i = 0; i < R; ++i)
                if (mat[i][j]) left[i][j] = left[i][j-1] + 1;
            for (int i = R-1; i >= 0; --i) 
                if(mat[i][C-1-j]) right[i][C-1-j] = right[i][C-j] + 1;
        }
    }
}

void print_mat(vector<vector<int>>& mat)
{
    cout << '\n';
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[0].size(); ++j)
        {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}

void case_solve()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> mat(R, vector<int>(C, 0)), res(R, vector<int>(C, 0)),
                        up(R, vector<int>(C, 0)), right(R, vector<int>(C, 0)), 
                        down(R, vector<int>(C, 0)), left(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> mat[i][j];

    compute_available(mat, up, right, down, left);
    int ans = 0, cnt = 0;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cnt = 0;
            for (int k = 2; k <= up[i][j]; ++k)
            {
                if (right[i][j] >= 2*k) cnt++;
                if (k >=4 && k%2 == 0 && right[i][j] >= k/2) cnt++;
                if (left[i][j] >= 2*k) cnt++;
                if (k >=4 && k%2 == 0 && left[i][j] >= k/2) cnt++;
            }
            for (int k = 2; k <= down[i][j]; ++k)
            {
                if (right[i][j] >= 2*k) cnt++;
                if (k >=4 && k%2 == 0 && right[i][j] >= k/2) cnt++;
                if (left[i][j] >= 2*k) cnt++;
                if (k >=4 && k%2 == 0 && left[i][j] >= k/2) cnt++;
            }
            ans += cnt;
            res[i][j] = cnt;
        }
    }
    cout << ans << '\n';
}

void solve() {
    int nCases;
    cin >> nCases;
    for (int i = 1; i <= nCases; ++i)
    {
        cout << "Case #" << i << ": " ;
        case_solve();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
