//
//  Increasing_Substring.cpp
//  2021 Google Kick Start Round 2, Increasing Substring
//
//  Created by Lei Hsiung on 2021/04/22.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void case_solve()
{
    int N;
    string str;
    cin >> N >> str;
    vector<int> longest_substring(N);
    longest_substring[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        if (str[i] - str[i-1] > 0) longest_substring[i] = longest_substring[i-1] + 1;
        else longest_substring[i] = 1;
    }
    for (int i = 0; i < N; ++i)
    {
        if (i!=0) cout << ' ';
        cout << longest_substring[i];
    }
    cout << '\n';
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
