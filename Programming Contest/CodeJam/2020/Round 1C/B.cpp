//
//  B.cpp
//  2020 Google Code Jam Round 1C B.Overrandomized
//
//  Created by Lei Hsiung on 2020/05/02.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nCases;
    cin >> nCases;
    for (int i = 1; i <= nCases; ++i)
    {
        int alpha[26] = {0};
        string s, unused;
        set<char> mem;
        vector<pair<int, char> > ve;
        cin >> unused;
        for (int j = 0; j < 10000; ++j)
        {
            cin >> unused >> s;
            alpha[s[0] - 'A'] ++;
            for (int z = 0; z < s.size(); z++) mem.insert(s[z]);
        }
        for(set<char>::iterator it=mem.begin() ; it!=mem.end() ; ++it)
        {
            char c = *it;
            ve.push_back(make_pair(alpha[c - 'A'], c));
        }
        sort(ve.begin(), ve.end());

        cout << "Case #" << i << ": " << ve[0].second;
        for (int j = ve.size()-1; j >= 1; --j) cout << ve[j].second;
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}