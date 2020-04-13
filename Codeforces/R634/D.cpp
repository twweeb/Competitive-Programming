//
//  D.cpp
//  Codeforces Round #634 - D. Anti-Sudoku
//
//  Created by twweeb on 2020/04/13.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int mat[9][9] = {0};
        string s;
        for (int i = 0; i < 9; ++i)
        {
            cin >> s;
            for(int j = 0; j < 9; ++j) 
                mat[i][j] = s[j] - '0';
        }
        int k = 0;
        for (int i = 0; i < 9; ++i)
        {
            mat[i][k%9] = mat[(i+1)%9][k%9];
            k+=3;
            if (i%3 == 2) k += 1;
        }
        for (int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
                cout << mat[i][j];
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
