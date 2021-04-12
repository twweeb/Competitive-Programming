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

vector<long long> primes_list;

long long count_score(map<long long, int> &group)
{
    long long score = 1;
    for (auto val=group.begin(); val!=group.end(); ++val)
        score *= pow(val->first, val->second);
    return score;
}

void print_res(map<long long, int>& decomp, int init_sum)
{
    cout << "mul_sum: " << init_sum << ", mul decomposition: ";
    if (!decomp.empty())
    {
        for (auto val=decomp.begin(); val!=decomp.end(); ++val)
            for (int i = 0; i < val->second; ++i) cout << val->first << " ";
    }
    else cout << "Unable to decompose.";
    cout << '\n';
}

void prime_decomp(map<long long, int>& decomp_res, long long add_sum, long long mul_sum)
{
    long long cur_prime = 0ll, decomp_mul = 0ll;
    for (int i = 0; i < primes_list.size(); ++i) 
    {
        cur_prime = primes_list[i];
        while (add_sum != 1 && add_sum%cur_prime == 0)
        {
            if (decomp_res.find(cur_prime)!=decomp_res.end()) ++ decomp_res[cur_prime];
            else decomp_res[cur_prime] = 1;
            add_sum /= cur_prime;
            decomp_mul += cur_prime;
        }
        if (add_sum == 1) break;
    }
    if (add_sum != 1 || mul_sum != decomp_mul) decomp_res.clear();
    // print_res((*decomp_res), mul_sum);
}

bool is_feasible(map<long long, int>& primes, map<long long, int>& decomp_of_mul_sum)
{
    for (auto prime=decomp_of_mul_sum.begin(); prime!=decomp_of_mul_sum.end(); ++prime)
    {
        if (primes.find(prime->first) != primes.end())
        {
            if (primes[prime->first] >= prime->second) continue;
            else return false; 
        }
        else return false;
    }
    return true;
}

void case_solve()
{
    int M;
    cin >> M;
    map<long long, int> primes;
    primes_list.clear();
    long long prime, sum = 0ll;
    int num;
    for (int i = 0; i < M; ++i)
    {
        cin >> prime >> num;
        primes[prime] = num;
        primes_list.push_back(prime);
        sum += prime*num;
    }

    long long score = 0, MAX_SCORE = 0;
    bool feasible = false;
    // cout << '\n';
    map<long long, int> decomp_of_mul_sum;
    for (long long mul_sum = 2ll; mul_sum < sum; ++mul_sum)
    {
        prime_decomp(decomp_of_mul_sum, sum-mul_sum, mul_sum);
        if (!decomp_of_mul_sum.empty())
        {
            feasible = is_feasible(primes, decomp_of_mul_sum);
            if (feasible)
            {
                score = count_score(decomp_of_mul_sum);
                // cout << "score: " << score << '\n';
                if (score > MAX_SCORE)  MAX_SCORE = score;
            }
            decomp_of_mul_sum.clear();
        }
        else continue;
        feasible = false;
    }
    cout << MAX_SCORE << '\n';
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