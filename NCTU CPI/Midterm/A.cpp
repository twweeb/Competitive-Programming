//
//  A.cpp
//  Concept: Divide and Conquer
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/24.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int k;
map<int, int> goal;

long long cost_dnc(vector<int> &vec)
{
    size_t n = vec.size();
    if (n <= 1) return 0LL;
    vector<int> left, right;
    for (int i = 0; i < n/2; ++i) left.push_back(vec[i]);
    for (int i = n/2; i < n; ++i) right.push_back(vec[i]);
    
    // Divide and Conquer
    long long cost = cost_dnc(left) + cost_dnc(right);
    vector<int> cnt(k);
    for (auto c: left) cnt[c%k]++;
    int p, q, r;
    for (p = q = r = 0; p < left.size() && q < right.size(); )
    {
        if (goal[left[p]] < goal[right[q]])
        {
            --cnt[left[p]%k];
            vec[r++] = left[p++];
        }
        else
        {
            for (int i = 0; i < k; ++i)
            {
                cost += cnt[i] * ((i+right[q])%k);
            }
            vec[r++] = right[q++];
        }
    }
    while (p < left.size()) vec[r++] = left[p++];
    while (q < right.size()) vec[r++] = right[q++];
    return cost;
}

void solve() {
    int n = 0;
    cin >> n >> k;
    vector<int> orig(n);
    for (int i = 0; i < n; ++i) cin >> orig[i];
    for (int i = 0; i < n; ++i)
    {
        int t = 0;
        cin >> t;
        goal[t] = i;
    }
    cout << cost_dnc(orig) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
