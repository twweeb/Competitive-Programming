//
//  A.cpp
//  NCTU CPI Quiz 3 A.Ocean's Anti-11
//
//  Created by Lei Hsiung on 2020/05/01.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int fact(int n) {
    if (n == 0 || n == 1) return 1;
    else return n*fact(n-1);
}

int comb(int n, int k)
{
    return fact(n)/fact(k)/fact(n-k);
}

int mod(string num) 
{ 
    int ans = 0;
    for (int i = 0; i < num.length(); i++) 
         ans = (ans*10 + (int)num[i] - '0') % (1000000007); 
    return ans; 
}

int count_no11(int N)
{
    int cnt = 0, lim = (N%2 == 1) ? (N+1)/2 : N/2;
    for(int i = 0; i <= lim; ++ i)
    {
        if (i == 0) cnt += 1;
        else 
        {
            int p = comb(N-i+1, i);
            cnt += p;
        }
        cnt = mod(to_string(cnt));
    }
    return cnt;
}

void solve() {
    int nCases, N;
    cin >> nCases;
    while(nCases--)
    {
        cin >> N;
        cout << count_no11(N) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
