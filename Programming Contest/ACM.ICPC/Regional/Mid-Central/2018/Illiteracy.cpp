//
//  Illiteracy.cpp
//  2018 ICPC Mid-Central Regional
//
//  Created by twweeb on 2020/05/12.
//  Copyright © 2020 twweeb. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;

char rotate(char c){ return (c - 'A' + 1)%6 + 'A';}

string click_button(string str, int clicked)
{
    if (str[clicked] - 'A' == 0)
    {
        if (clicked-1 >= 0) str[clicked-1] = rotate(str[clicked-1]);
        if (clicked+1 <= 7) str[clicked+1] = rotate(str[clicked+1]);
    }
    else if (str[clicked] - 'B' == 0)
    {
        if (clicked != 7 && clicked !=0)
            str[clicked + 1] = str[clicked - 1];
    }
    else if (str[clicked] - 'C' == 0)
    {
        str[7-clicked] = rotate(str[7-clicked]);
    }
    else if (str[clicked] - 'D' == 0)
    {
        for (int i = (clicked <=3 ) ? 0 : 7; i != clicked; i += (clicked <= 3)? 1:-1)
        {
            str[i] = rotate(str[i]);
        }
    }
    else if (str[clicked] - 'E' == 0)
    {
        if (clicked != 7 && clicked != 0)
        {
            int y = min(7-clicked, clicked);
            str[clicked + y] = rotate(str[clicked + y]);
            str[clicked - y] = rotate(str[clicked - y]);
        }
    }
    else if (str[clicked] - 'F' == 0)
    {
        if (clicked % 2 == 0) str[clicked/2+4] = rotate(str[clicked/2+4]);
        else str[(clicked-1)/2] = rotate(str[(clicked-1)/2]);
    }
    return str;
}

int hash_string (string s)
{
    int h = 0;
    for (char c: s)
    {
        h += c - 'A';
        h *= 6;
    }
    return h;
}

int bfs(string init, string goal)
{
    map<string, int> step;
    queue<string> q;
    if (init.compare(goal) == 0) return 0;
    
    q.push(init); step[init] = 0;
    while (!q.empty())
    {
        string p = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            string c = click_button(p, i);
            if (c.compare(goal) == 0) return step[p] + 1;
            if (step.find(c) == step.end()) 
            {
                step[c] = step[p] + 1;
                q.push(c);
            }
        }
    }
    return -1;
}

int bfs_hash(string init, string goal) // Hashing Method
{
    set<int> seen;
    set<string> q;
    int step = 0, hashed;
    if (init.compare(goal) == 0) return 0;
    q.insert(init);
    while (true)
    {
        set<string> new_q;
        for (string p: q)
        {
            for (int i = 0; i < 8; ++i)
            {
                string c;
                c = click_button(p, i);
                if (c.compare(goal) == 0) return step + 1;

                hashed = hash_string(c);
                if (!seen.count(hashed))
                {
                    seen.insert(hashed);
                    new_q.insert(c);
                }
            }
        }
        q = new_q;
        step++;
    }
    return step;
}

void solve() {
    string init, goal;
    cin >> init >> goal;
    cout << bfs(init, goal) << '\n';
    //cout << bfs_hash(init, goal) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
