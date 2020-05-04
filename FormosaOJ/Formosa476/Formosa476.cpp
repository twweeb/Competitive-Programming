//
//  Formosa476.cpp
//  
//
//  Created by Lei Hsiung on 5/5/20.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

bool feasible(int size, vector<int>& vec)
{
    long long int cur = size;// It might be very large during estimation
    for (int i = 0; i < vec.size(); ++i)
    {
        if (cur == 0LL) return false;
        if (cur == vec[i]) continue;
        else if (cur > vec[i]) cur += (vec[i]+1)/2;
        else cur /= 2;
    }
    if (cur) return true;
    else return false;
}

void solve() 
{
    int read_bytes = 4 * 1000000;
    char buffer[read_bytes];

    while(cin.getline(buffer,read_bytes))
    {
        if (!buffer[0]) break;
        stringstream ss(buffer);
        vector<int> vec;
        int in, min_size = 1;
        while(ss >> in) vec.push_back(in);
        if (feasible(1, vec)) cout << "1" << endl;
        else
        {
            for (int step = 1<<29; step >= 1; step >>= 1)
                if (!feasible(min_size+step, vec))
                    min_size += step;
            cout << min_size+1 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}