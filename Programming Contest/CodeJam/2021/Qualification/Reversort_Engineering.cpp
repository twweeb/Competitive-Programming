//
//  Moons_and_umbrellas.cpp
//  2021 Google Code Jam Qualification Round, Reversort Engineering
//
//  Created by Lei Hsiung on 2021/03/26.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>
#define INF 1<<30

using namespace std;

void generate_list (vector<int>& cost_seq, int N)
{
    vector<int> ans_map(N),ans(N);
    for (int i = 0; i < N; ++i) ans_map[i] = i;
    for (int i = 0; i < N-1; ++i) reverse(ans_map.begin()+i, ans_map.begin()+i+cost_seq[i]);

    for (int i = 0; i < N; ++i) ans[ans_map[i]]=i+1;
    for (auto elem: ans) cout << ' ' << elem;
    cout << '\n';
}

bool find_cost_seq (vector<int>& cost_seq, int N, int C)
{
    if (N*(N+1)/2-1 < C || C < N - 1) return false;
    for (int i = 1; i <= N-1; ++i)
    {
        if (2*(N-i) <= C)
        {
            cost_seq[i-1] = N-i+1;
            C -= (N-i+1);
        }
        else
        {
            cost_seq[i-1] = C-(N-1-i);
            C -= cost_seq[i-1];
        }
    }
    return true;
}

void case_solve ()
{
    int N, C;
    cin >> N >> C;
    vector<int> cost_seq(N-1);
    bool feasible = find_cost_seq(cost_seq, N, C);
    if (feasible) generate_list(cost_seq, N);
    else cout << " IMPOSSIBLE\n";
}

void solve() {
    int nCases;
    cin >> nCases;
    for (int i = 1; i <= nCases; ++i)
    {
        cout << "Case #" << i << ":" ;
        case_solve();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}