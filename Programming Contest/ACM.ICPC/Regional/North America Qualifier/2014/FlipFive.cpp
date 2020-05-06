//
//  FlipFive.cpp
//  2014 ICPC North America Qualifier
//
//  Created by Lei Hsiung on 2020/05/02.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int min_step;

bool isSolved(string cur, string goal)
{
    bool istheSame = true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) istheSame &= (cur[3*i+j] - goal[3*i+j]) == 0;
    if (istheSame) return true;
    istheSame = true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) istheSame &= (cur[3*j+2-i] - goal[3*i+j]) == 0;
    if (istheSame) return true;
    istheSame = true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) istheSame &= (cur[8-3*i-j] - goal[3*i+j]) == 0;
    if (istheSame) return true;
    istheSame = true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) istheSame &= (cur[6-3*j+i] - goal[3*i+j]) == 0;
    if (istheSame) return true;
    return false;
}

char flip(char c)
{
    if (c - '.' == 0) return '*';
    else return '.';
}

string click(string s, int t)
{
    s[t] = flip(s[t]);
    if (t%3!=0 && t-1 >= 0) s[t-1] = flip(s[t-1]);
    if (t%3!=2 && t+1 <= 8) s[t+1] = flip(s[t+1]);
    if (t-3 >= 0) s[t-3] = flip(s[t-3]);
    if (t+3 <= 8) s[t+3] = flip(s[t+3]);
    return s;
}

void dfs(string goal, string cur, int depth, int step)
{
    if (isSolved(cur, goal)) 
    {
        min_step = min(step, min_step);
        return;
    }
    if (depth == 9) return;
    dfs(goal, click(cur, depth), depth+1, step+1);
    dfs(goal, cur, depth+1, step);
    return;
}

void solve() {
    int nCases;
    cin >> nCases;
    while (nCases--)
    {
        string goal = "", str;
        for (int i = 0; i < 3; ++i)
        {
            cin >> str;
            goal += str;
        }
        min_step = 1<<29;
        dfs(goal, ".........", 0, 0);
        cout << min_step <<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
