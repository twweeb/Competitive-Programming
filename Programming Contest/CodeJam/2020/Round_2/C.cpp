//
//  C.cpp
//  2020 Google Code Jam Round 2 C. Wormhole in One
//
//  Created by Lei Hsiung on 2020/05/16.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

double cnt_s(int x1, int y1, int x2, int y2)
{
    return (y1-y2)/(x1-x2);
}

void solve() {
    int nCases;
    cin >> nCases;
    for (int i = 1; i <= nCases; ++i)
    {
        int holes = 0;
        cin >> holes;
        vector<pair<int,int>> hole(holes);
        for (int j = 0; j < holes; ++j) 
        {
            int x, y;
            cin >> x >> y;
            hole[j] = {x,y};
        }
        map<double, int> slope;
        for (int j = 0; j < holes-1; ++j)
            for (int k = j+1; k < holes; ++k)
            {
                int slop = cnt_s(hole[j].first, hole[j].second, hole[k].first, hole[k].second);
                if (slope.find(slop) == slope.end()) slope[slop] = 0;
                else slope[slop]++;
            }
        for ()

        cout << "Case #" << i << ": " ;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
