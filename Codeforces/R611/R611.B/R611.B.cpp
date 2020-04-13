//
//  R611.B.cpp
//  CodeForces Round #611 (Div. 3) B. Candies Division
//
//  Created by Magic Bear on 2020/04/05.
//  Copyright © 2020 Magic Bear. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    int nCases;
    cin >> nCases;
    while (nCases --)
    {
        int n, k;
        cin >> n >> k;
        if (n % k == 0) cout << n << '\n';
        else
        {
            int max_candies = int(n/k) + 1, remain = 0;
            remain = max_candies * k - n;
            if (remain > k/2) cout << n << '\n';
            else cout << max_candies*(int)(k/2) + (max_candies-1)*(int)((k+1)/2) << '\n';
        }
    }
    return 0;
}
