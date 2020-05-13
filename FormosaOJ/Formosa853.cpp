//
//  Formosa853.cpp
//  Dragon Raiders
//
//  Created by Lei Hsiung on 5/14/20.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void add (long long *a, long long *b, long long *res, int n)
{
    for (int i = 0; i < n; ++i)
        res[i] = a[i] + b[i];
}

void sub (long long *a, long long *b, long long *res, int n)
{
    for (int i = 0; i < n; ++i)
        res[i] = a[i] - b[i];
}

void mul (long long *a, long long *b, long long *res, int n)
{
    if (n <= 64)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res[i+j] += a[i]*b[j];
        return;
    }
    int h = n>>1;
    long long ah[h], al[h], bh[h], bl[h];
    for (int i = 0; i < h; ++i)
    {
        al[i] = a[i];
        ah[i] = a[h+i];
        bl[i] = b[i];
        bh[i] = b[h+i];
    }
    
    long long ahbh[n], albl[n], mid[n];
    for (int i = 0; i < n; ++i) ahbh[i] = albl[i] = mid[i] = 0;
    mul(ah, bh, ahbh, h);
    mul(al, bl, albl, h);
    add(ah, al, ah, h);
    add(bh, bl, bh, h);
    mul(ah, bh, mid, h);
    sub(mid, ahbh, mid, n);
    sub(mid, albl, mid, n);
    for (int i = 0; i < n; ++i) 
    {
        res[i] += albl[i];
        res[n+i] += ahbh[i];
        res[h+i] += mid[i];
    }
}

void karatsuba_solve()
{
    int n = 0, m = 0, q = 0, idx = 0;
    cin >> n >> m >> q;
    long long sword[1<<16]={0}, shield[1<<16]={0}, ans[1<<17]={0};
    
    sword[0] = 1; shield[0] = 1; //Important!!
    for (int i = 0; i < n; ++i) 
    {
        cin >> idx;
        sword[idx]++;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> idx;
        shield[idx]++;
    }
    
    mul(sword, shield, ans, 1<<16);
    while (q--)
    {
        int monster = 0;
        cin >> monster;
        if (monster > 1e5) cout << "0\n";
        else cout << ans[monster] << '\n';
    }
}

void bfsolve()
{
    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;
    int sword[n+1], shield[m+1];
    long long mons[100001] = {0};
    sword[0] = 0; shield[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> sword[i];
    for (int i = 1; i <= m; ++i) cin >> shield[i];
    sort(sword, sword+n+1); sort(shield, shield+m+1);
    int max_cp = sword[n] + shield[n];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            mons[sword[i]+shield[j]] ++;

    while (q--)
    {
        int monster = 0;
        cin >> monster;
        if (monster > 1e5) cout << "0\n";
        else cout << mons[monster] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //bfsolve();
    karatsuba_solve();
    return 0;
}