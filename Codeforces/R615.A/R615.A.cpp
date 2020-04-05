//
//  R615.A.cpp
//  CodeForces Round #615 (Div. 3) A. Collecting Coins
//
//  Created by Magic Bear on 2020/04/03.
//  Copyright © 2020 Magic Bear. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int nCases;
    cin >> nCases;
    while (nCases --)
    {
        
        int a, b, c, n, tmp;
        cin >> a >> b >> c >> n;
        tmp = a + b + c + n;
        if (tmp%3 == 0)
        {
            tmp /= 3;
            if (a <= tmp && b <= tmp && c <= tmp)cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";

    }
    return 0;
}