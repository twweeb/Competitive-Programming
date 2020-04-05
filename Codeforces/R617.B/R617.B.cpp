//
//  R617.B.cpp
//  CodeForces Round #617 (Div. 3) B. Food Buying
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
        int burles, maxburles = 0, tmp = 0;
        cin >> burles;
        while (burles)
        {
            if(burles < 10) break;
            maxburles += burles - burles%10;
            tmp = burles/10;
            burles %= 10;
            burles += tmp;
        }
        cout << maxburles + burles << "\n";
    }
    return 0;
}