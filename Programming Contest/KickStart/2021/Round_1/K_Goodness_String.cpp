//
//  K_Goodness_String.cpp
//  2021 Google Kick Start Round 1, K-Goodness String
//
//  Created by Lei Hsiung on 2021/03/21.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int goodness_score(string str)
{
    int score = 0, str_len = str.length();
    for (int i = 0; i < str_len/2; ++i)
        if (str[i] - str[str_len - 1 - i] != 0) score ++;
    return score;
}

void case_solve()
{
    int N, K;
    string str;

    cin >> N >> K >> str;

    int cur_score = goodness_score(str);

    cout << abs(K - cur_score) << '\n';
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
