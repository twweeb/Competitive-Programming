//
//  B.cpp
//  NCTU CPI Midterm Makeup
//
//  Created by Lei Hsiung on 2020/05/29.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

long long nCr (int n, int r) //r<=3
{
    long long t = (r==3)? (long long)n*(n-1)*(n-2) : (r==2)? (long long)n*(n-1): (long long)n;
    long long s = (r==3)? 6LL : (r==2)? 2LL : 1LL;
    return (r==3) ? t/s : (r==2)?t/r:(r==1)?t:1LL;
}

void solve() {
    int nCases = 0;
    cin >> nCases;
    while (nCases--)
    {
        int n, zeroNeed = 0, t = 0, c= 0;
        long long k, curRank = 0LL;
        cin >> n >> k;
        while (true)
        {
            t =  nCr(2+zeroNeed, 2);
            if (curRank + t >=k) break;
            else curRank += t;
            ++zeroNeed;
            //cout << t << endl;
        }
        cout << n-(zeroNeed+2) << ' ';
        c += n-(zeroNeed+2);
        k -= curRank;
        curRank = 0LL;
        zeroNeed = 0;
        while (true)
        {
            t =  nCr(1+zeroNeed, 1);
            if (curRank + t >=k) break;
            else curRank += t;
            ++zeroNeed;
        }
        cout << c + (n-c-(zeroNeed+1)) << ' ';
        c = c + (n-c-(zeroNeed+1));
        k -= curRank;
        cout << n-(k-1) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
