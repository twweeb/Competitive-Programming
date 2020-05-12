//
//  CrackingTheSafe.cpp
//  2015 Virginia Tech High School Programming Contest
//
//  Created by twweeb on 2020/05/12.
//  Copyright © 2020 twweeb. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

string push_button(string cur, int btn)
{
    cur[btn] = '0' + (cur[btn] - '0' + 1) % 4;
    cur[(btn+3)%9] = '0' + (cur[(btn+3)%9] - '0' + 1) % 4;
    cur[(btn+6)%9] = '0' + (cur[(btn+6)%9] - '0' + 1) % 4;
    if(btn % 3 == 0)
    {
        cur[btn+1] = '0' + (cur[btn+1] - '0' + 1) % 4;
        cur[btn+2] = '0' + (cur[btn+2] - '0' + 1) % 4;
    }
    else if (btn % 3 == 1)
    {
        cur[btn+1] = '0' + (cur[btn+1] - '0' + 1) % 4;
        cur[btn-1] = '0' + (cur[btn-1] - '0' + 1) % 4;
    }
    else
    {
        cur[btn-1] = '0' + (cur[btn-1] - '0' + 1) % 4;
        cur[btn-2] = '0' + (cur[btn-2] - '0' + 1) % 4;
    }
    return cur;
}

int hashing(string s)
{
    int h = 0;
    for (char c: s)
    {
        h += c - '0';
        h *= 4;
    }
    return h;
}

int bfs(string init)
{
    set<int> seen;
    set<string> pool;
    string goal = "000000000";
    int step = 0;
    pool.insert(init);
    while(!pool.empty())
    {
        set<string> new_pool;
        for (string s: pool)
        {
            for (int i = 0; i < 9; ++i)
            {
                string after = push_button(s, i);
                if (after.compare(goal) == 0) return step + 1;
                int hashed = hashing(after);
                if (!seen.count(hashed))
                {
                    seen.insert(hashed);
                    new_pool.insert(after);
                }
            }
        }
        step ++;
        pool = new_pool;
    }
    return -1;
}

void solve() 
{
    string init;
    char c;
    for (int i = 0; i < 9; ++i) 
    {
        cin >> c;
        init.push_back(c);
    }
    
    cout << bfs(init) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
