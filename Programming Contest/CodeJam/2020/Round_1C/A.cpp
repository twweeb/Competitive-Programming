//
//  A.cpp
//  2020 Google Code Jam Round 1C A.Overexcited Fan
//
//  Created by Lei Hsiung on 2020/05/02.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

pair<int,int> after_t(int X, int Y, string M, int t)
{
    int cnt_N = 0, cnt_E = 0;
    for(int i = 0; i < t; ++i)
    {
        if(M[i] - 'N' == 0) cnt_N++;
        if(M[i] - 'S' == 0) cnt_N--;
        if(M[i] - 'E' == 0) cnt_E++;
        if(M[i] - 'W' == 0) cnt_E--;
    }
    return make_pair(X+cnt_E, Y+cnt_N);
}

int short_meet(int X, int Y, string M)
{
    int max_step = abs(X) + abs(Y);

    for (int i = 0; i <= M.size(); ++i)
    {
        pair<int,int> z = after_t(X, Y, M, i);
        int need_step = abs(z.first) + abs(z.second);
        if (need_step <= i) return i;
    }
    return -1;
}

void solve() {
    int nCases;
    cin >> nCases;
    for (int i = 1; i <= nCases; ++i)
    {
        int X, Y;
        string M;
        cin >> X >> Y >> M;
        int s = short_meet(X, Y, M);
        cout << "Case #" << i << ": " ;
        if (s == -1) cout << "IMPOSSIBLE\n";
        else cout << s << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
