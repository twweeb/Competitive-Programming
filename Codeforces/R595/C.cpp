//
//  C.cpp
//  Codeforces Round #595 - C2. Good Numbers (hard version)
//  Concept: Ternary Number, Carry Out.
//
//  Created by twweeb on 2020/06/13.
//  Copyright © 2020 twweeb. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

long long exp(long long n, int p) // Fast Exp
{
    if (p == 0) return 1LL;
    if (p == 1) return n;
    long long half = exp(n, p/2);
    if (p&1) return half*half*n;
    else return half*half;
}

string trit(long long n)
{
    string s = "";
    while (n!=0LL)
    {
        int r = n%3;
        s.push_back('0'+r);
        n/=3;
    }
    reverse(s.begin(),s.end());
    return s;
}

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        long long n;
        cin >> n;
        string tri = trit(n);
        bool changed = false;
        int zero_pos = -1;
        for (int i = 0; i < tri.size(); ++i)
        {
            if (tri[i] - '0' == 0 && !changed) zero_pos = i;
            else if (tri[i] - '2' == 0 && !changed) changed = true;
            else if (changed) tri[i] = '0';
        }
        if (changed)
        {
            if (zero_pos == -1) n = exp(3,tri.size());
            else 
            {
                n = 0LL;
                for (int i = 0; i < tri.size(); ++i)
                {
                    if (i == zero_pos)
                    {
                        n += exp(3,tri.size()-1-zero_pos);
                        break;
                    }
                    else n += (tri[i]-'0')*exp(3,tri.size()-1-i);
                }
            }
        }
        cout << n << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
