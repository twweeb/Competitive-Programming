//
//  C.cpp
//  NCTU CPI Final
//
//  Created by Lei Hsiung on 2020/06/19.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

bool isEqui(string &s, string &t)
{
    size_t n = s.size();
    if (n == 0) return false;
    else if (n == 1) return (s[0]-t[0]==0);
    else if (n == 2)
    {
        if (s[0]-t[0] == 0) return true;
        else return (s[1]-t[1] == 0);
    }

    // Check Rule 2 First
    int cnt = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (s[i]-t[i] != 0) 
        {
            cnt++;
            if (cnt == 2) break;
        }
    }
    if (cnt<=1) return true;

    // Divide and Conquer
    string s1(s, 0, n-n/2), s2(s, n-n/2, n/2), t1(t, 0, n-n/2), t2(t, n-n/2, n/2);
    return isEqui(s1,t1)&&isEqui(s2,t2);
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    s.reserve(n); t.reserve(n);
    cin >> s >> t;
    cout << (isEqui(s,t)? "True\n" : "False\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
