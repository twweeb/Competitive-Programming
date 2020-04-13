//
//  R615.C.cpp
//  CodeForces Round #615 (Div. 3) C. Product of Three Numbers
//
//  Created by Magic Bear on 2020/04/05.
//  Copyright © 2020 Magic Bear. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

vector<int> factor(int n)
{
    vector<int> fac,tmp;
    for (int i = 2; i <= int(sqrt(n)); ++i)
    {
        if (n % i == 0) fac.push_back(i);
    }
    return (fac.size() == 1 && pow(fac[0],2) == n) ? tmp : fac;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    int nCases;
    cin >> nCases;
    while (nCases --)
    {
        int n;
        cin >> n;
        auto fac = factor(n);
        string ans = "";
        bool isPossible = false;
        if (fac.size() >= 3)
        {
            for (int i = 0; i < fac.size(); ++i)
            {
                auto first = factor(fac[i]);
                if (first.size())
                {
                    ans = to_string(first[0]) + " " + to_string(fac[i]/first[0]) + " " + to_string(n/fac[i]);
                    isPossible = true;
                    break;
                }
            }
            if(!isPossible && fac[0] * fac[1] * fac[2] == n)
            {
                ans = to_string(fac[0]) + " " + to_string(fac[1]) + " " + to_string(fac[2]);
                isPossible = true;
            }
        }
        
        if (isPossible) cout << "YES\n" << ans << '\n';
        else cout << "NO\n";
    }
    return 0;
}
