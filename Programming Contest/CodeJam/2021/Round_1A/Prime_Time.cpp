//
//  Prime_Time.cpp
//  2021 Google Code Jam Round 1A, Prime Time
//
//  Created by Lei Hsiung on 2021/04/10.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define INF 1<<30
#define MAX_P 95
#define MAX_MUL_SUM 3026

long long primes_list[MAX_P], primes_num[MAX_P];
int M;

bool prime_decomp(long long score, long long mul_sum)
{
    long long cur_prime = 0ll, decomp_mul = 0ll, cnt = 0ll;
    bool early_break = false;
    for (int i = 0; i < M; ++i) 
    {
        cur_prime = primes_list[i];
        cnt = 0ll;
        while (score%cur_prime == 0)
        {
            ++cnt;
            if (cnt > primes_num[i]) return false;
            else score /= cur_prime;
        }

        decomp_mul += cur_prime*cnt;
        if (score == 1ll) break;
    }
    if (score != 1ll || mul_sum != decomp_mul) return false;
    else return true;
}

void case_solve()
{
    cin >> M;
    long long sum = 0ll;
    memset(primes_list, 0ll, M); memset(primes_num, 0ll, M);

    for (int i = 0; i < M; ++i)
    {
        cin >> primes_list[i] >> primes_num[i];
        sum += primes_list[i]*primes_num[i];
    }

    long long score = 0ll;
    for (long long mul_sum = 2ll; mul_sum < ((sum < MAX_MUL_SUM) ? sum : MAX_MUL_SUM); ++mul_sum)
    {
        if (prime_decomp(score = sum-mul_sum, mul_sum)) break;
        else score = 0ll;
    }
    cout << score << '\n';
}

void solve() {
    int nCases;
    cin >> nCases;
    for (int i = 1; i <= nCases; ++i)
    {
        cout << "Case #" << i << ": " ;
        case_solve();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
