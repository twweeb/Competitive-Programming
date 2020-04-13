//
//  R624.A.cpp
//  CodeForces Round #624 (Div. 3) A. Add Odd or Subtract Even
//
//  Created by Magic Bear on 2020/03/21.
//  Copyright © 2020 Magic Bear. All rights reserved.
//

#include<iostream>
#include<string>

using namespace std;

int main()
{
    int nCases;
    cin >> nCases;
    while (nCases -- )
    {
        int a, b;
        cin >> a >> b;
        if ( a == b )
            cout << "0\n";
        else if (a < b)
        {
            if ((b - a)%2 == 1) cout << "1\n";
            else cout << "2\n";
        }
        else if (a > b)
        {
            if((a - b) % 2 == 0) cout << "1\n";
            else cout << "2\n";
        }
    }

    return 0;
}