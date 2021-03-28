//
//  Reversort.cpp
//  2021 Google Code Jam Qualification Round, Reversort
//
//  Created by Lei Hsiung on 2021/03/26.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define INF 1<<30

int get_min_index(vector<int>& seq, int start, int seq_len)
{
    int min_val = INF, min_idx = start;
    for (int i = start; i < seq_len; ++i)
    {
        if (seq[i] < min_val)
        {
            min_val = seq[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int reversort(vector<int>& seq)
{
    int seq_len = seq.size();
    int cost = 0;
    for (int i = 0; i < seq_len - 1; ++i)
    {
        int j = get_min_index(seq, i, seq_len);
        reverse(seq.begin()+i, seq.begin()+j+1);
        cost += j - i + 1;
    }
    return cost;
}

void case_solve()
{
    int N;
    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; ++i) cin >> seq[i];
    cout << reversort(seq) << '\n';
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