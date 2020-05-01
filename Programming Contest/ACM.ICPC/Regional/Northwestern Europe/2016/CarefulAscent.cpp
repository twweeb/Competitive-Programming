//
//  B.cpp
//  NCTU CPI Quiz 3
//
//  Created by Lei Hsiung on 2020/05/01.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int goal_x, goal_y, nShields, low_b, hig_b, depth = 0;
    cin >> goal_x >> goal_y >> nShields;
    double alpha, sum;
    while (nShields--)
    {
        cin >> low_b >> hig_b >> alpha;
        depth += hig_b-low_b;
        sum += alpha*(hig_b-low_b);
    }
    sum += goal_y - depth;
    cout << fixed << setprecision(8) << goal_x/sum <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
