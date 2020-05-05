//
//  A.cpp
//  Codeforces Round #636 - A. Candies
//
//  Created by twweeb on 2020/05/05.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

bool feasible_2k(int k, int n)
{
    return n % (int)(pow(2,k)-1) == 0;
}

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int n, k = 1;
        cin >> n;
        while (++k)
        {
            if (feasible_2k(k, n))
            {
                cout << n/(int)(pow(2,k)-1) << endl;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
