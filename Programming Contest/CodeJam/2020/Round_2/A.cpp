//
//  A.cpp
//  2020 Google Code Jam Round 2 A. Incremental House of Pancakes
//
//  Created by Lei Hsiung on 2020/05/16.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

long long start(long long d)
{
    return floor(sqrt(d*2));
}

long long need(long long n)
{
    return n*(n+1)/2;
}

bool isEnd(long long L, long long R, long long need)
{
    return (L < need) || (R < need);
}

long long serve_cnt(long long s, long long remain)
{
    return floor((1-s+sqrt(s*s-2*s+1+4*remain))/2);
}

long long reduce(long long s, long long serve)
{
    return (serve == 1) ? s : serve*(serve+s-1);
}

void solve() {
    long long nCases;
    cin >> nCases;
    for (long long i = 1; i <= nCases; ++i)
    {
        long long L, R, n = 0;
        cin >> L >> R;
        cout << "Case #" << i << ": " ;
        bool isLeftTurn = true;
        if (L != R)
        {
            long long d = abs(L - R);
            n += start(d);
            if (d == need(n)) 
            {
                L = R = min(L, R);
                isLeftTurn = true;
            }
            else {
                if (L > R) 
                {
                    L -= need(n);
                    isLeftTurn = false;
                }
                else 
                {
                    R -= need(n);
                    isLeftTurn = true;
                }
            }
        }
        long long left_serv, right_serv;
        if (isLeftTurn)
        {
            left_serv = max(0LL, serve_cnt(n+1, L));
            right_serv = max(0LL, serve_cnt(n+2, R));
        }
        else
        {
            left_serv = max(0LL, serve_cnt(n+2, L));
            right_serv = max(0LL, serve_cnt(n+1, R));
        }

        long long more_serve = 0;

        if(left_serv < right_serv)
        {
            more_serve = (isLeftTurn) ? 2*left_serv:2*left_serv+1;
            L -= (isLeftTurn) ? reduce(n+1, left_serv) : reduce(n+2, left_serv);
            R -= (isLeftTurn) ? reduce(n+2, left_serv): reduce(n+1, left_serv+1);
        }
        else if (left_serv > right_serv)
        {
            more_serve = (isLeftTurn) ? 2*right_serv+1:2*right_serv;
            L -= (isLeftTurn) ? reduce(n+1, right_serv+1) : reduce(n+2, right_serv);
            R -= (isLeftTurn) ? reduce(n+2, right_serv): reduce(n+1, right_serv);
        }
        else 
        {
            more_serve = 2*left_serv;
            L -= (isLeftTurn) ? reduce(n+1, right_serv) : reduce(n+2, right_serv);
            R -= (isLeftTurn) ? reduce(n+2, right_serv): reduce(n+1, right_serv);
        }
        cout << more_serve+n << ' ' << L << ' ' << R << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
