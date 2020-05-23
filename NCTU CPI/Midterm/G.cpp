//
//  G.cpp
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/23.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

long long MOD_P = 1e9+7;
long long mod(long long x){return (long long)(x % MOD_P);};
long long c = 0, b = 0, k = 1;

struct ans{
    long long m, k;
    ans(long long m=0, long long k=0) : m(mod(m)), k(mod(k)){}
    ans operator+(const ans& a) const
    {
        return ans(a.m+m, a.k+k);
    }
    ans operator-(const ans& a) const
    {
        return ans(m-a.m, k-a.k);
    }
    ans operator*(const ans& a) const
    {
        return ans(mod(a.m*m)+mod(mod(a.k*k)*mod(c)), mod(a.m*k)+mod(a.k*m));
    }
    ans operator/(ans& a) const
    {
        return (*this)*a.inv();
    }
    ans& operator=(const ans& a)
    {
        m = a.m;
        k = a.k;
        return *this;
    }
    ans pow(int n)
    {
        if (n == 0) return ans(1LL,0LL);
        if (n == 1) return *this;
        if (n % 2 == 0)
        {
            ans h = (*this).pow(n/2);
            return h*h;
        }
        else 
        {
            ans h = (*this).pow((n-1)/2);
            return *this * h * h;
        }
    }
    ans inv()
    {
        ans mag = ans(mod(m*m)-mod(mod(k*k)*mod(c))+MOD_P, 0LL);
        return mag.pow(MOD_P-2)*ans(m,MOD_P-k);
    }
};

void determine_ck()
{
    c = 1LL + b*b; k = 1LL;
    for (long long i = 2; i <= min(b,c); ++i)// Type should use long long
    {
        long long j = i*i;
        if (j > c) break;
        while (c % j == 0LL) 
        {
            c /= j;
            k *= i;
            k = mod(k);
        }
    }
}

ans geo_sum(ans& a1, ans& r, int n)
{
    ans minusOne(MOD_P-1LL, 0LL), z = r + minusOne;
    return a1*(r.pow(n) + minusOne)/z;
}

void solve() {
    int T = 0;
    cin >> T;
    while (T--)
    {
        long long a;
        int n;
        cin >> a >> b >> n;
        determine_ck();

        ans perimeter, area, r = ans(1+b, k), r2 = r*r, area1(a*b,0);
        perimeter = geo_sum(r, r, n);
        area = geo_sum(area1, r2, n);

        cout << perimeter.m << ' ' << perimeter.k << ' ' << ((perimeter.k > 0) ? c : 1) << '\n';
        cout << area.m << ' ' << area.k << ' ' << ((area.k > 0) ? c : 1) << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
