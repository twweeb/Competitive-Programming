//
//  A.cpp
//  2020 Google Code Jam Round 1B A.Expogo
//
//  Created by Lei Hsiung on 2021/03/05.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

bool isX(char c) {return ((c - 'E')*(c - 'W') == 0);}

char opposite (char c)
{
    if (c - 'N' == 0) return 'S';
    if (c - 'S' == 0) return 'N';
    if (c - 'W' == 0) return 'E';
    if (c - 'E' == 0) return 'W';
} 

void case_solve()
{
    int x, y;
    cin >> x >> y;
    bool x_sign, y_sign; // true: pos, false: neg
    x_sign = x > 0; y_sign = y > 0;

    x = abs(x); y = abs(y);

    bool feasible = ((x+y) % 2 == 1);

    if (!feasible) 
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    string ans="";
    while (x != 0 && y != 0)
    {
        if (x % 2 == 0)
        {
            x /= 2;
            if (x % 2 == 1)
            {
                y = (y+1)/2;
                if (y % 2 == 1)
                {
                    --y;
                    ans.push_back('N');
                }
                else ans.push_back('S');
            }
            else
            {
                y = (y+1)/2;
                if (y % 2 == 1) ans.push_back('S');
                else 
                {
                    --y;
                    ans.push_back('N');
                }
            }
        }
        else
        {
            y /= 2;
            if (y % 2 == 1)
            {
                x = (x + 1) / 2;
                if (x % 2 == 1)
                {
                    --x;
                    ans.push_back('E');
                }
                else ans.push_back('W');
            }
            else
            {
                x = (x + 1) / 2;
                if (x % 2 == 1) ans.push_back('W');
                else 
                {
                    --x;
                    ans.push_back('E');
                }
            }
        }
    }

    if (x != 0)
    {
        while(x != 1)
        {
            x /= 2;
            if (x % 2 == 0) 
            {
                ++x;
                ans.push_back('W');
            }
            else ans.push_back('E');
        }
        ans.push_back('E');
    }
    else if (y != 0)
    {
        while (y != 1)
        {
            y /= 2;
            if (y % 2 == 0) 
            {
                ++y;
                ans.push_back('S');
            }
            else ans.push_back('N');
        }
        ans.push_back('N');
    }

    for (auto c: ans)
    {
        if (isX(c))
        {
            if (x_sign) cout << c;
            else cout << opposite(c);
        }
        else
        {
            if (y_sign) cout << c;
            else cout << opposite(c);
        }
    }
    ans = "";
    cout << '\n';
    return;
}

void solve() {
    int nCases;
    cin >> nCases;
    for (int i = 1; i <= nCases; ++i)
    {
        cout << "Case #" << i << ": " ;
        case_solve();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
