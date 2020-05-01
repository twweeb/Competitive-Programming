//
//  R520.B.cpp
//  CodeForces Round #520 (Div. 2) B. Math
//
//  Created by Magic Bear on 2020/04/30.
//  Copyright © 2020 Magic Bear. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

int maxNearestPowerof2(int n) 
{ 
    int res = 0, cnt = 0; 
    for (int i = n; i >= 1; --i) 
    { 
        if ((i & (i-1)) == 0) 
        { 
            res = i; 
            break; 
        } 
    }
    res = (res == n) ? res : res*2;
    while (res != 1)
    {
        cnt++;
        res /= 2;
    }
    return cnt; 
} 

bool is_prime(int p)
{
    for(int i = 2; i <= sqrt(p); ++i)
    {
        if(p % i == 0) return false;
    }
    return true;
}

bool isPerfectSquareOfPrime(int n)
{
    if (pow((int)sqrt(n),2) == n)
    if (is_prime(sqrt(n))) return true;

    return false;
}

void analyze_factor(int n, vector<int>&prime_factor)
{
    int max_index = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (!is_prime(i)) continue;
        if (n % i == 0)
        {
            prime_factor.push_back(i);
            int cnt = 0;
            while(n % i == 0)
            {
                cnt++;
                n /= i;
            }
            max_index = max(max_index, cnt);
        }
    }
    prime_factor.push_back(max_index);
}

void solve() {
    int n, sqrt_time = 0, mul_time = 0, min_num = 1;
    cin >> n;
    if (n>1)
    {
        vector<int> prime_factor;
        analyze_factor(n, prime_factor);
        sqrt_time = maxNearestPowerof2(prime_factor[prime_factor.size()-1]);
        prime_factor.pop_back();
        for(int i : prime_factor) min_num*=i;
        mul_time = (pow(min_num,pow(2,sqrt_time)) == n) ? 0 : 1;
    }
    if (min_num == n) mul_time = 0;
    cout << min_num << " " << mul_time+sqrt_time <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
