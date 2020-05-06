//
//  B.cpp
//  Codeforces Round #605 - B. Snow Walking Robot
//
//  Created by twweeb on 2020/05/06.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        string s;
        cin >> s;
        int left = 0, right = 0, up = 0, down = 0, horizontal = 0, vertical = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] - 'L' == 0) left++;
            else if (s[i] - 'R' == 0) right++;
            else if (s[i] - 'U' == 0) up++;
            else if (s[i] - 'D' == 0) down++;
        }
        horizontal = min(left,right);
        vertical = min(up,down);
        if (horizontal == 0 || vertical == 0) 
        {
            if (horizontal+vertical == 0) cout << "0\n\n";
            else if (horizontal == 0) cout << "2\nUD\n";
            else cout << "2\nRL\n";
        }
        else
        {
            cout << 2*(horizontal + vertical) << '\n';
            for (int i = 0; i < horizontal; ++i) cout << 'R';
            for (int i = 0; i < vertical; ++i) cout << 'U';
            for (int i = 0; i < horizontal; ++i) cout << 'L';
            for (int i = 0; i < vertical; ++i) cout << 'D';
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
