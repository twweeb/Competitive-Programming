//
//  D.cpp
//  NCTU CPI Quiz 3
//
//  Created by Lei Hsiung on 2020/05/01.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int inf = 1<<29;

int cnt_dec(double x)
{
    int count = 0;
    x = abs(x);
    x = x - (int)x;
    while (x != 0)
    {
        x = 10*x;
        count = count + 1;
        x = x - (int)x;
    }
    return count;
}

void solve() {
    int n, m, max_length = 0;
    double need, needsAmounmt = 0.0, buyAmount = 0.0;
    string str;
    cin >> n >> m;
    vector<double> shopColour(n);

    sort(shopColour.begin(), shopColour.end());
    for (int i = 0; i < n; ++i) cin >> shopColour[i];

    while (m--)
    {
        cin >> str;
        for (int i = 0; i < str.size(); ++i)
            if (str[i] - '.' == 0) max_length = max((int)(str.size() - i - 1), max_length);
        need = stod(str);
        needsAmounmt += need;
        for(double i : shopColour) 
        {
            if (i >= need)
            {
                buyAmount += i;
                break;
            }
        }
    }
    cout << fixed << setprecision(max_length) << buyAmount-needsAmounmt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
