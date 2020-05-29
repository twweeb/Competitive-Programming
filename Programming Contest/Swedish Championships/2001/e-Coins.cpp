//
//  e-Coins.cpp
//  Swedish Championships 2001
//  Concept: BFS
//
//  Created by twweeb on 2020/05/12.
//  Copyright © 2020 twweeb. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

struct eCoin{
    int cValue;
    int itValue;
};

inline bool operator<(const eCoin& lhs, const eCoin& rhs)
{
  return lhs.cValue < rhs.cValue;
}

bool isPerfectSquare(int x) 
{
    double s = sqrt(x);
    return ((s - floor(s)) == 0); 
}

int eModulus(int conv, int it)
{
    int ans = pow(conv, 2) + pow(it, 2);
    if (isPerfectSquare(ans)) return sqrt(ans);
    else return 0;
}

void bfs(int coins, int goal_value)
{
    eCoin coin[coins], init;
    for (int i = 0; i < coins; ++i) cin >> coin[i].cValue >> coin[i].itValue;
    set<int> known_value;
    set<eCoin> pool;
    init.cValue = 0; init.itValue = 0;
    pool.insert(init);
    known_value.insert(0);

    int cnt = 0;
    while (!pool.empty())
    {
        set<eCoin> new_pool;
        for (eCoin p: pool)
        {
            for (int i = 0; i < coins; ++i)
            {
                int tmp = eModulus(p.cValue+coin[i].cValue, p.itValue+coin[i].itValue);
                if (tmp == goal_value) 
                {
                    cout << cnt + 1 << '\n';
                    return;
                }
                if (!known_value.count(tmp) && (tmp < goal_value))
                {
                    known_value.insert(tmp);
                    eCoin r;
                    r.cValue = p.cValue+coin[i].cValue;
                    r.itValue = p.itValue+coin[i].itValue;
                    new_pool.insert(r);
                }
            }
        }
        cnt++;
        pool.clear();
        pool = new_pool;
    }
    cout << "not possible\n";
}

void solve() 
{
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int coins = 0, goal_value = 0;
        cin >> coins >> goal_value;
        bfs(coins, goal_value);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
