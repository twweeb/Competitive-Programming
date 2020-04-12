//
//  1_Vestigium.cpp
//  Code Jam Qualification Round 2020 1. Vestigium
//
//  Created by Lei Hsiung on 2020/04/04.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int nCases, cur_case = 0;
    cin >> nCases;
    while (cur_case < nCases)
    {
        int n = 0, trace = 0, r_rows = 0, r_cols = 0;
        cin >> n;
        int mat[n][n];
        bool *cnt = (bool *)malloc(sizeof(bool*)*n);
        for (int i = 0; i < n; ++i)
        {
            bool isRepeatRow = false;
            for(int k = 0; k < n; ++k) cnt[k] = 0;
            for (int j = 0; j < n; ++j)
            {
                cin >> mat[i][j];
                if (cnt[mat[i][j]-1] && !isRepeatRow)
                {
                    ++r_rows;
                    isRepeatRow = true;
                }
                else cnt[mat[i][j]-1] = true;
                if(i == j) trace += mat[i][j];
            }
        }
        for(int j = 0; j < n; ++j)
        {
            bool isRepeatCol = false;
            for(int k = 0; k < n; ++k) cnt[k] = 0;
            for(int i = 0; i < n; ++i)
            {
                if (cnt[mat[i][j]-1] && !isRepeatCol)
                {
                    ++r_cols;
                    isRepeatCol = true;
                }
                else cnt[mat[i][j]-1] = true;
            }
        }
        cout << "Case #" << ++cur_case << ": " 
             << trace << " " << r_rows << " " << r_cols << "\n";
    }
    return 0;
}