//
//  R615.B.cpp
//  CodeForces Round #615 (Div. 3) B. Collecting Packages
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
        int n, m_i, m_j;
        cin >> n;
        pair<int, int> vec[1000];
        for (int i = 0; i < n; ++i)
        {
            cin >> m_i >> m_j;
            vec[i] = make_pair(m_i, m_j);
        }
        sort(vec, vec + n);

        string str;
        m_i = m_j = 0;
        int sum = 0, len = 0;
        bool isPossible = true;
        for(int i = 0; i < n; ++i)
        {
            if(vec[i].first + vec[i].second <= sum)
            {
                isPossible = false;
                cout << "NO\n";
                break;
            }
            else sum = vec[i].first + vec[i].second;

            while(m_i != vec[i].first)
            {
                str.insert(len++,"R");
                ++m_i;
            }
            while(m_j != vec[i].second)
            {
                str.insert(len++,"U");
                ++m_j;
            }
        }
        if (isPossible)
            cout << "YES\n" << str << "\n";
    }
    return 0;
}