//
//  H.cpp
//  NCTU CPI Quiz 3
//
//  Created by Lei Hsiung on 2020/05/01.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int inf = 1 << 29;

double burteS(double left, double right, double d, double s) {
    double a = (left+right)/2;
    double tmp = a*cosh(d/2/a) - a - s;

    if (abs(tmp) < 0.0000001) return a;
    else if (tmp > 0) return burteS(a, right, d, s);
    else if (tmp < 0) return burteS(left, a, d, s); 
    else return a;
}

void solve() {
    double d, s, a, length;
    cin >> d >> s;
    a = burteS(0, inf, d, s);
    length = 2*a*sinh(d/2/a);
    cout << fixed << setprecision(9) << length << endl; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
