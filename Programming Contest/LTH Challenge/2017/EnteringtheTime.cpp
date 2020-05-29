//
//  EnteringtheTime.cpp
//  LTH Challenge 2017
//  Concept: Rounding
//
//  Created by twweeb on 2020/05/30.
//  Copyright © 2020 twweeb. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

void solve() 
{
    string cur = "", goal = "";
    cin >> cur >> goal;
    int abscomp[5] = {abs(cur[0]-goal[0]),abs(cur[1]-goal[1]), 0, abs(cur[3]-goal[3]), abs(cur[4]-goal[4])},
        comp[5] = {cur[0]-goal[0],cur[1]-goal[1], 0, cur[3]-goal[3], cur[4]-goal[4]},
        j = 0, total = 1; 
    for (int i = 0; i < 5; ++i)
    {
        if (i==3 || abscomp[i] <= 5) total+=abscomp[i];
        else total += ((min(cur[i]-'0', goal[i]-'0')+10) - max(cur[i]-'0', goal[i]-'0'));
    }
    cout << total << '\n' << cur << '\n';
    while (cur.compare(goal)!=0)
    {
        if (comp[j] == 0)
        {
            j++;
            continue;
        }
        if (j==0)
        {
            if (goal[j]-'2'!=0)
                while (cur[j]-goal[j] != 0)
                {
                    cur[j] += (abscomp[j]<5)? ((comp[j]<0) ? 1 : -1) : ((comp[j]<0) ? -1 : 1);
                    cout << cur << '\n';
                }
                    
            else 
            {
                ++j;
                while (cur[j]-goal[j] != 0)
                {
                    cur[j] += (abscomp[j]<5)? ((comp[j]<0) ? 1 : -1) : ((comp[j]<0) ? -1 : 1);
                    cur[j] = (cur[j]-'9'==1) ? '0' : (cur[j]-'0'==-1) ? '9' : cur[j];
                    cout << cur << '\n';
                }
                --j;
                while (cur[j]-goal[j] != 0)
                {
                    cur[j] += (abscomp[j]<5)? ((comp[j]<0) ? 1 : -1) : ((comp[j]<0) ? -1 : 1);
                    cout << cur << '\n';
                }
            }
        }
        else if (j==1)
            while (cur[j]-goal[j] != 0)
            {
                cur[j] += (abscomp[j]<5)? ((comp[j]<0) ? 1 : -1) : ((comp[j]<0) ? -1 : 1);
                cur[j] = (cur[j]-'9'==1) ? '0' : (cur[j]-'0'==-1) ? '9' : cur[j];
                cout << cur << '\n';
            }
        else if (j==3)
            while (cur[j]-goal[j] != 0)
            {
                cur[j] += (comp[j]<0) ? 1 : -1;
                cout << cur << '\n';
            }
        else if (j==4)
            while (cur[j]-goal[j] != 0)
            {
                cur[j] += (abscomp[j]<5)? ((comp[j]<0) ? 1 : -1) : ((comp[j]<0) ? -1 : 1);
                cur[j] = (cur[j]-'9'==1) ? '0' : (cur[j]-'0'==-1) ? '9' : cur[j];
                cout << cur << '\n';
            }
        j++;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
