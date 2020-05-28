//
//  B.cpp
//  Concept: Bidirectional Search (BFS), Bit Operation
//  NCTU CPI Midterm
//
//  Created by Lei Hsiung on 2020/05/24.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

long long FirePower = 0LL;
long long odd = (((1LL<<7)-1)<<56) + (((1LL<<7)-1)<<42) + (((1LL<<7)-1)<<28) + (((1LL<<7)-1)<<14) + (((1LL<<7)-1));
long long even = (((1LL<<7)-1)<<49) + (((1LL<<7)-1)<<35) + (((1LL<<7)-1)<<21) + (((1LL<<7)-1)<<7);

struct mat{
    long long val;
    mat(long long v) : val{v}{}
    mat op(int op){
        mat new_m(0LL);
        if (op == 0) new_m.val = val;
        else if (op == 1) new_m.val = (r2()<<21) + (r1()>>21) + r3();
        else if (op == 2) new_m.val = (r3()<<42) + r2() + (r1()>>42);
        else if (op == 3) new_m.val = r1() + (r3()<<21) + (r2()>>21);
        else if (op == 4) new_m.val = (c2()<<7) + (c1()>>7) + c3();
        else if (op == 5) new_m.val = (c3()<<14) + c2() + (c1()>>14);
        else if (op == 6) new_m.val = c1() + (c3()<<7) + (c2()>>7);

        return new_m;
    }
    long long r1() {return val&(((1LL<<21)-1)<<42);}
    long long r2() {return val&(((1LL<<21)-1)<<21);}
    long long r3() {return val&((1LL<<21)-1);}
    long long c1() {return val&((((1LL<<7)-1)<<56) + (((1LL<<7)-1)<<35) + (((1LL<<7)-1)<<14));}
    long long c2() {return val&((((1LL<<7)-1)<<49) + (((1LL<<7)-1)<<28) + (((1LL<<7)-1)<<7));}
    long long c3() {return val&((((1LL<<7)-1)<<42) + (((1LL<<7)-1)<<21) + ((1LL<<7)-1));}
};

bool cooked_oneMin(mat &cur, bool isAdd)
{
    long long curOdd = (cur.val&odd), curEven = (cur.val&even);
    if (isAdd)
    {
        curEven += (even & FirePower);
        curOdd += (odd & FirePower);
    }
    else
    {
        curEven -= (even & FirePower);
        curOdd -= (odd & FirePower);
    }
    if ((curOdd&even) != 0LL || (curEven&odd) != 0LL) return false;
    cur.val = curEven + curOdd;
    return true;
}

void show (mat& cur) //For Debug
{
    for (int i = 0; i < 9; ++i)
    {
        long long t = (cur.val>>((8-i)*7)) & ((1LL<<7)-1);
        cout << t << ' ';
        if (i%3 == 2) cout << '\n';
    }
}

void bfs (mat& cur, mat& goal)
{
    queue<mat> head, back;
    unordered_set<long long> hVisited, bVisited;
    head.push(cur); back.push(goal);
    hVisited.insert(cur.val);
    bVisited.insert(goal.val);

    int step = 1;
    while (true)
    {
        int p = head.size(), q = back.size();
        while (p--)
        {
            mat p = head.front();
            head.pop();
            if (!cooked_oneMin(p, true)) continue;
            //show(p);
            for (int j = 0; j < 7; ++j)
            {
                mat t = p.op(j);
                if (bVisited.find(t.val) != bVisited.end())
                {
                    cout << step << '\n';
                    return;
                }
                else if (hVisited.find(t.val) == hVisited.end())
                {
                    head.push(t);
                    hVisited.insert(t.val);
                }
            }
        }
        if (step++ == 15) break;
        while (q--)
        {
            mat p = back.front();
            back.pop();
            for (int j = 0; j < 7; ++j)
            {
                mat t = p.op(j);
                if (!cooked_oneMin(t, false)) continue; // For the backward, do cook after operation.

                if (hVisited.find(t.val) != hVisited.end())
                {
                    cout << step << '\n';
                    return;
                }
                else if (bVisited.find(t.val) == bVisited.end())
                {
                    back.push(t);
                    bVisited.insert(t.val);
                }
            }
        }
        ++step;
    }
    cout << "NA IS HARD, SO IS LIFE.\n";
}

void solve() {
    int n = 0;
    cin >> n;
    while (n--)
    {
        long long t = 0LL, g = 0LL;
        FirePower = 0LL;
        for (int i = 0; i < 9; ++i) 
        {
            cin >> t;
            FirePower <<= 7;
            FirePower += t;
        }
        for (int i = 0; i < 9; ++i) 
        {
            cin >> t;
            g <<= 7;
            g += t;
        }
        mat orig(0LL), goal(g);
        bfs(orig, goal);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
