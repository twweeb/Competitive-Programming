//
//  AnimalKingElection.cpp
//  2019 ICPC Taiwan Online Programming Contest
//
//  Created by twweeb on 2020/05/11.
//  Copyright © 2020 twweeb. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

void solve() {
    char vote[10];
    int tiger = 0, lion = 0;
    while (cin >> vote)
    {
        if (vote[0] - 'T' == 0) tiger ++;
        else lion ++;
    }
    if (tiger > lion) cout << "Tiger\n";
    else cout << "Lion\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
