//
//  C.cpp
//  NCTU CPI Midterm Makeup
//  Concept: Using Matrix Multiplication to ensure time complexity.
//
//  Created by Lei Hsiung on 2020/06/06.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

long long mod = 0LL;

struct mat{
    long long a, b, c, d, e, f, g, h, i;
    mat(long long a, long long b, long long c,
        long long d, long long e, long long f,
        long long g, long long h, long long i) : a{a}, b{b}, c{c}, d{d}, e{e}, f{f}, g{g}, h{h}, i{i}{}

    mat operator*(const mat& mul) const
    {
        return mat((a*mul.a+b*mul.d+c*mul.g) % mod, (a*mul.b+b*mul.e+c*mul.h) % mod, (a*mul.c+b*mul.f+c*mul.i) % mod,
                   (d*mul.a+e*mul.d+f*mul.g) % mod, (d*mul.b+e*mul.e+f*mul.h) % mod, (d*mul.c+e*mul.f+f*mul.i) % mod,
                   (g*mul.a+h*mul.d+i*mul.g) % mod, (g*mul.b+h*mul.e+i*mul.h) % mod, (g*mul.c+h*mul.f+i*mul.i) % mod);
    }

    mat pow(long long n){
        if (n == 0) return mat(1LL, 0LL, 0LL, 0LL, 1LL, 0LL, 0LL, 0LL, 1LL);
        if (n == 1) return *this;
        mat half = (*this).pow(n/2);
        if (n&1) return (*this)*half*half;
        else return half*half;
    }
};

void solve() {
    int T = 0;
    cin >> T;
    while (T--)
    {
        long long b, n;
        cin >> b >> n >> mod;
        mat f = mat(b, 0LL, 0LL, b, b, 0LL, 0LL, 1LL, 1LL).pow(n);
        cout << (b*(f.g+f.h))%mod << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
