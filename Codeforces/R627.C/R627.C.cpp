//
//  R626.C.cpp
//  CodeForces Round #627 (Div. 3) C. Frog Jumps
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
    while (nCases --)
    {
        string str;
        cin >> str;
        int d = 0, cnt = 0;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == 'L') cnt ++;
            else cnt = 0;
            d = max(d, cnt);
        }
        cout << d+1 << endl;
    }
    return 0;
}