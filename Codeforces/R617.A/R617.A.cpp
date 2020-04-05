//
//  R617.A.cpp
//  CodeForces Round #617 (Div. 3) A. Array with Odd Sum
//
//  Created by Magic Bear on 2020/03/30.
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
        int n;
        bool isSameParity = true;
        cin >> n;
        int *a = (int *) malloc(n*sizeof(int*));
        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
            isSameParity = (i > 0) ? ((a[i] + a[i-1]) % 2 == 0) ? isSameParity : false :isSameParity;
        }
        if (isSameParity)
        {
            if (n%2 == 0) cout << "NO\n";
            else if (a[0]%2 == 1) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "YES\n";
    }
    return 0;
}