//
//  A.cpp
//  NCTU CPI Final
//
//  Created by Lei Hsiung on 2020/06/19.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

long long square(long long n) {return n*n;}

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        long long a, b, c, d, t;
        cin >> a >> b >> c >> d;
        t = a;
        a = min(t, b);
        b = max(t, b);
        t = c;
        c = min(t,d);
        d = max(t,d);
        if (max(b,d)>=(a+c)) cout <<  square(max(b,d)) << '\n';
        else cout << ((a+c>max(b,d))? square(a+c): ((c<=b && (a+d<=b)))? square(a+d): square(c+b)) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
