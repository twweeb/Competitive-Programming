//
//  C.cpp
//  Codeforces Round #634 - C. Two Teams Composing
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
        int n = 0, tmp = 0, diffExpert = 0, maxExpert = 0;
        cin >> n;
        vector<int> expert(n+1);
        for (int i = 0; i <= n; ++i) expert[i] = 0;
        for (int i = 0; i < n; ++i) 
        {
            cin >> tmp;
            expert[tmp] ++;
            if(expert[tmp] == 1) diffExpert++;
            maxExpert = max(maxExpert, expert[tmp]);
        }
        diffExpert--;
        if (diffExpert != 0) 
        {
            if (diffExpert + 1 < maxExpert)  cout << diffExpert + 1 <<endl;
            else cout << min(maxExpert, diffExpert) << endl;
        }
        else if (maxExpert > 1) cout << "1" << endl;
        else cout << "0" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
