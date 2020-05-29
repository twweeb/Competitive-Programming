//
//  Cantor.cpp
//  Waterloo Programming Contest 2009-10-03
//  Concept: Ternary expansion
//
//  Created by Lei Hsiung on 2020/05/13.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string c = "";
    while (getline(cin, c))
    {
        if (c[0] - 'E' == 0) break;
        stringstream ss(c);
        double t;
        ss >> t;
        bool isCantor = true;
        for (int i = 0; i < 20; ++i) 
        // Since having at most 6 digits after the decimal point, need around 20 times iteration to check.
        {
            if (t == 1 || t == 0) break;
            if (t < 1) t*=3.0;
            else if (t < 2)
            {
                isCantor = false;
                break;
            }
            else if (t < 3) 
            {
                t -= 2.0;
                t*=3.0;
            }
        }
        if (isCantor) cout << "MEMBER\n";
        else cout << "NON-MEMBER\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
