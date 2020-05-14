//
//  Formosa843.cpp
//  City Skyline
//
//  Created by Lei Hsiung on 5/14/20.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void dnc(vector<vector<pair<int, int>>> &b, int s, int e, vector<pair<int, int>> &res)
{
    if (e - s == 1)
    {
        res = b[s];
        return;
    }

    int mid = s + (e-s)/2;
    vector<pair<int ,int>> sky1, sky2;
    dnc (b, s, mid, sky1);
    dnc (b, mid, e, sky2);
    int i = 0, j = 0;
    for (;i < sky1.size() && j < sky2.size();)
    {
        if (sky1[i].first < sky2[j].first)
        {
            int h = (j == 0) ? 0 : sky2[j-1].second;
            if (sky1[i].second > h) res.push_back(sky1[i]);
            else if (res.size() > 0 && res.back().second > h)
                res.push_back(make_pair(sky1[i].first, h));
            i++;
        }
        else if (sky1[i].first > sky2[j].first)
        {
            int h = (i == 0) ? 0 : sky1[i-1].second;
            if (sky2[j].second > h) res.push_back(sky2[j]);
            else if (res.size() > 0 && res.back().second > h)
                res.push_back(make_pair(sky2[j].first, h));
            j++;
        }
        else
        {
            int new_h = max (sky1[i].second, sky2[j].second),
                old_h = (res.size()) ? res.back().second : 0;
            if (old_h != new_h)
                res.push_back(make_pair(sky1[i].first, new_h));
            i++; j++;
        }
    }
    for (; i < sky1.size(); ++i) res.push_back(sky1[i]);
    for (; j < sky2.size(); ++j) res.push_back(sky2[j]);
}

long long area(vector<pair<int, int>> &v)
{
    long long a = 0ll;
    for (int i = 1; i <= v.size(); ++i)
        a += (long long) (v[i].first - v[i-1].first) * v[i-1].second;
    return a;
}

long long len(vector<pair<int, int>> &v)
{
    long long horizontal = 0ll, vertical = (long long)v[0].second;
    for (int i = 0; i < v.size() - 1; ++i)
        horizontal += (v[i].second == 0) ? 0 : (long long) (v[i+1].first - v[i].first);
    for (int i = 1; i < v.size(); ++i)
        vertical += (long long) abs(v[i].second - v[i-1].second);
    return horizontal + vertical;
}

void solve()
{
    int n = 0;
    cin >> n;
    vector<pair<int ,int>> skyline;
    vector<vector<pair<int ,int>>> building(n, vector<pair<int, int>>());
    for (int i = 0; i < n; ++i) 
    {
        int x, h, w;
        cin >> x >> h >> w;
        building[i].push_back(make_pair(x, h));
        building[i].push_back(make_pair(x+w, 0));
    }

    dnc (building, 0, n, skyline);
    cout << len(skyline) << ' ' << area(skyline) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}