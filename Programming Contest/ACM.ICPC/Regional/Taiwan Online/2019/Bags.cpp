//
//  Bags.cpp
//  2019 ICPC Taiwan Online Programming Contest
//
//  Created by twweeb on 2020/05/11.
//  Copyright © 2020 twweeb. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

void solve() {
    int n = 0, tmp = 0;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
