//
//  E.cpp
//  NCTU CPI Final
//
//  Created by Lei Hsiung on 2020/06/19.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long const MOD = 1e9+7;
    long long n;
    cin >> n;
    if(n==1)
    {
        cout << 1 << '\n';
        return;
    }
    if(n==2)
    {
        cout << 4 << '\n';
        return;
    }
    long long A[2][2];
    A[0][0] = 2; A[0][1] = 4; A[1][0] = 1; A[1][1] = 0;
    long long tmp[2][2], An[2][2];
    An[0][0] = An[1][1] = 1; An[0][1] = An[1][0] = 0;
    n -= 2;
    for(long long cur=1 ; cur<=n ; cur*=2)
    {
        if(cur & n)
        {
            for(int i=0 ; i<2 ; ++i)
            {
                for(int j=0 ; j<2 ; ++j)
                {
                    tmp[i][j] = 0;
                    for(int k=0 ; k<2 ; ++k)
                    {
                        tmp[i][j] += An[i][k]*A[k][j]%MOD;
                    }
                    tmp[i][j] %= MOD;
                }
            }
            for(int i=0 ; i<2 ; ++i)
            {
                for(int j=0 ; j<2 ; ++j)
                {
                    An[i][j] = tmp[i][j];
                }
            }
        }

        for(int i=0 ; i<2 ; ++i)
        {
            for(int j=0 ; j<2 ; ++j)
            {
                tmp[i][j] = 0;
                for(int k=0 ; k<2 ; ++k)
                {
                    tmp[i][j] += A[i][k]*A[k][j]%MOD;
                }
                tmp[i][j] %= MOD;
            }
        }
        for(int i=0 ; i<2 ; ++i)
        {
            for(int j=0 ; j<2 ; ++j)
            {
                A[i][j] = tmp[i][j];
            }
        }
    }
    cout << (An[0][0]*4+An[0][1]*1)%MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
