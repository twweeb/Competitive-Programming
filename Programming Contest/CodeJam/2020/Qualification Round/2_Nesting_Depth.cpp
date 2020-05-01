//
//  2_Nesting_Depth.cpp
//  Code Jam Qualification Round 2020 2. Nesting Depth
//
//  Created by Lei Hsiung on 2020/04/04.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int nCases, cur_case = 0;
    cin >> nCases;
    while (cur_case < nCases)
    {
        string str, ans;
        cin >> str;
        int depth = 0, num;
        for(int i = 0; i < str.size(); ++i)
        {
            num = str[i] - '0';
            while(depth > num)
            {
                ans.push_back(')');
                --depth;
            }
            while(depth < num)
            {
                ans.push_back('(');
                ++depth;
            }
            ans.push_back(str[i]);
        }
        while(depth > 0)
        {
            ans.push_back(')');
            --depth;
        }
        cout << "Case #" << ++cur_case << ": " << ans << "\n";
    }
    return 0;
}