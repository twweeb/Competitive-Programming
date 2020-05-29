//
//  R611.A.cpp
//  CodeForces Round #611 (Div. 3) A. Minutes Before the New Year
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
        int h, m;
        cin >> h >> m;
        cout << (24-h)*60 - m << '\n';
    }
    return 0;
}

