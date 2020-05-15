//
//  E.cpp
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/15.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

long long fac(long long n)
{
    if(n==1)
        return 1;
    return n * fac(n-1);
}

void solve() {
    long long n, k, q;
    vector<string> in;
    vector<long long> W, Q;
    cin >> n >> k >> q;
    for(long long i=0 ; i<n ; ++i)
    {
        string t;
        cin >> t;
        in.push_back(t);
    }
    for(long long i=0 ; i<n-1 ; ++i)
    {
        long long t;
        cin >> t;
        W.push_back(t);
    }
    for(long long i=0 ; i<q ; ++i)
    {
        long long t;
        cin >> t;
        Q.push_back(t);
    }
    char letter[k];
    for(long long i=0 ; i<in[0].length() ; ++i)
    {
        letter[i] = in[0][i];
    }
    sort(letter, letter+k);
    map<string, long long> f;
    long long cnt = 1;
    do
    {
        string s = "";
        for(long long i=0 ; i<k ; ++i)
        {
            s.push_back(letter[i]);
        }
        f[s] = cnt++;
    }
    while(next_permutation(letter, letter+k));

    long long perm[n];
    for(long long i=0 ; i<n ; ++i)
    {
        perm[i] = i;
    }

    long long ans[fac(n)];

    long long ans_cnt = 0;

    do
    {
        long long res = 0;
        for(long long i=0 ; i<n-1 ; ++i)
        {
            res += (f[in[perm[i+1]]] - f[in[perm[i]]]) * W[i];
        }
        ans[ans_cnt++] = res;
    }
    while(next_permutation(perm, perm+n));

    sort(ans, ans+fac(n));
    reverse(ans, ans+fac(n));

    for(long long i = 0 ; i<q; ++i)
    {
        cout << ans[Q[i]-1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
