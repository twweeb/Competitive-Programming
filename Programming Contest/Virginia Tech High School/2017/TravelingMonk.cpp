//
//  TravelingMonk.cpp
//  2017 Virginia Tech High School Programming Contest
//  Concept: Binary Search
//
//  Created by Lei Hsiung on 2020/05/13.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

vector<pair<double,double> > _up, _down;
double inf = 1 << 29, mh;

double upHeight(double t)
{
    double q_h = 0.0, q_t = 0.0, p_h = 0.0, p_t = 0.0;
    for(pair<double, double>p : _up)
    {
        if(p.first >= t)
        {
            p_t = p.first; p_h = p.second;
            break;
        }
        q_t = p.first; q_h = p.second;
    }
    if(p_t == t) return p_h;
    return q_h + (p_h-q_h)*(t - q_t)/(p_t-q_t);
}

double downHeight(double t)
{
    double q_h = 0.0, q_t = 0.0, p_h = 0.0, p_t = 0.0;
    for(pair<double, double>p : _down)
    {
        if(p.first >= t)
        {
            p_t = p.first; p_h = p.second;
            break;
        }
        q_t = p.first; q_h = p.second;
    }
    if(p_t == t) return p_h;
    return q_h + (p_h-q_h)*(t - q_t)/(p_t-q_t);
}

bool feasible(double x)
{
    return upHeight(x) + downHeight(x) >= mh;
}

double binSearch(double left, double right)
{
    while (right - left > 1e-7)
    {
        if (feasible((left+right)/2)) right = (left+right)/2;
        else left = (left+right)/2;
    }
    return right;
}

void solve() {
    int up, down;
    double min_time = inf, h, t, prev_h, prev_t;
    cin >> up >> down;
    _up.push_back(make_pair(0.0,0.0)); _down.push_back(make_pair(0.0,0.0));
    prev_h = prev_t = 0;
    for (int i = 0; i < up; ++i)
    {
        cin >> h >> t;
        h += prev_h;
        t += prev_t;
        _up.push_back(make_pair(t, h));
        prev_h = h; prev_t = t;
    }
    mh = prev_h; min_time = prev_t; prev_t = prev_h = 0;
    for (int i = 0; i < down; ++i)
    {
        cin >> h >> t;
        h += prev_h;
        t += prev_t;
        _down.push_back(make_pair(t, h));
        prev_h = h; prev_t = t;
    }
    min_time = (min_time < prev_t) ? min_time : prev_t;
    cout << fixed << setprecision(6) << binSearch(-1, min_time+1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
