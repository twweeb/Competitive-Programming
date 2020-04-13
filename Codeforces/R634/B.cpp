//
//  B.cpp
//  Codeforces Round #634 - B. Construct the String
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
        int n = 0, a = 0, b = 0, i = 0;
        cin >> n >> a >> b;
        string str = "";
        while (str.size()!=n)
        {
            str.push_back('a' + ((i++)%b));
        }
        cout << str << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
