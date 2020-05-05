//
//  C.cpp
//  Codeforces Round #629 - C. Ternary XOR
//
//  Created by twweeb on 2020/05/05.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int n;
        char x[50001]={}, a[50001]={}, b[50001]={};
        bool hasMax = false;
        cin >> n >> x;
        for (int i = 0; i < n; ++i)
        {
            if (x[i] - '1' == 0)
            {
                if (hasMax) 
                {
                    a[i] = '0';
                    b[i] = '1';
                }
                else
                {
                    a[i] = '1';
                    b[i] = '0';
                    hasMax = true;
                }
            }
            else if (x[i] - '2' == 0)
            {
                if (hasMax) 
                {
                    a[i] = '0';
                    b[i] = '2';
                }
                else
                {
                    a[i] = '1';
                    b[i] = '1';
                }
            }
            else
            {
                a[i] = '0';
                b[i] = '0';
            }
        }
        cout << a << '\n';
        cout << b << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
