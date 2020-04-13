//
//  R624.B.cpp
//  CodeForces Round #624 (Div. 3) B. WeirdSort
//
//  Created by Magic Bear on 2020/03/23.
//  Copyright © 2020 Magic Bear. All rights reserved.
//

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int nCases;
    cin >> nCases;
    while (nCases -- )
    {
        int n, m, tmp;
        cin >> n >> m;
        vector<int> a, p;

        for (int i = 0; i < n + m; ++i)
        {
            cin >> tmp;
            if(i < n) a.push_back(tmp);
            else p.push_back(tmp - 1);
        }

        sort(p.begin(), p.end());
        int left = 0, right = 0;
        for (int i = 0; i < p.size(); ++i)
        {
            left = p[i];
            right = p[i] + 1;
            while (i+1 < p.size() && p[i+1] - p[i] == 1) right = p[++i]+1;
            sort(a.begin()+left, a.begin()+right+1);
        }
        if (is_sorted(a.begin(), a.end())) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}