//
//  C.cpp
//  Codeforces Round #605 - C. Yet Another Broken Keyboard
//
//  Created by twweeb on 2020/05/06.
//  Copyright © 2020 twweeb. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

long long cnt_substring_num (long long n)
{
    return n*(n+1)/2;
}

void solve() {
    int n, k, available[26] = {0}, cnt = 0;
    long long avail_substring = 0LL;
    cin >> n >> k;
    char s[n+1], c;
    cin >> s;
    for (int i = 0; i < k; ++i) 
    {
        cin >> c;
        available[c-'a'] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (available[s[i] - 'a']) cnt ++;
        else
        {
            avail_substring += cnt_substring_num(cnt);
            cnt = 0;
        }
    }
    avail_substring += cnt_substring_num(cnt);
    cout << avail_substring << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
