//
//  3_Parenting_Partnering_Returns.cpp
//  Code Jam Qualification Round 2020 3. Parenting Partnering Returns
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
        int n;
        cin >> n;
        char *ans = (char*)malloc(n*sizeof(char *));
        int Jamie[1440] = {0},
            Cameron[1440] = {0};
        int start, end;
        bool possible = true, done = true;
        vector<pair<pair<int, int>, int> > vec;
        memset(ans, ' ', n);
        for(int i = 0; i < n; ++i)
        {
            cin >> start >> end;
            vec.push_back(make_pair(make_pair(start, end), i));
        }
        sort(vec.begin(), vec.end());
        for(int z = 0; z < n; ++z)
        {
            if (!possible) break;
            start = vec[z].first.first;
            end = vec[z].first.second;
            done = true;
            for (int i = start; i < end; ++i)
                if (Jamie[i]){
                    done = false;
                    break;
                }
            if (done) 
            {
                for (int i = start; i < end; ++i) Jamie[i] = 1;
                ans[vec[z].second] = 'J';
            }
            else
            {
                done = true;
                for (int i = start; i < end; ++i)
                    if (Cameron[i]){
                        done = false;
                        break;
                    }
                if (done) 
                {
                    for (int i = start; i < end; ++i) Cameron[i] = 1;
                    ans[vec[z].second] = 'C';
                }
                else possible = false;
            }
        }
        ans[n] = '\0';
        cout << "Case #" << ++cur_case << ": ";
        if (!possible) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
    return 0;
}