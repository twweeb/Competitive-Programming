//
//  Moons_and_umbrellas.cpp
//  2021 Google Code Jam Qualification Round, Moons and umbrellas
//
//  Created by Lei Hsiung on 2021/03/26.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>
#define INF 1<<30

using namespace std;

int count_cost(string& str, int X, int Y)
{
    char last_char = str[0];
    int cost = 0;
    for (auto c: str)
    {
        if(last_char - c != 0)
        {
            if (c - 'J' == 0) cost+=X;
            else cost+=Y;
            last_char = c;
        }
    }
    return cost;
}

void fill_empty(string& str, vector<int>& empty_spaces, int X, int Y)
{
    int str_len = str.length();
    if (empty_spaces.size() % 2 == 1) cout << "Error!\n";

    for (int i = 0; i < empty_spaces.size(); i+=2)
    {
        int left = empty_spaces[i], right = empty_spaces[i+1];
        if (left == 0)
        {
            if (right+1 < str_len) str.replace(0,right+1,right+1,str[right+1]);
            else str.replace(0,str_len,str_len,'C');
            continue;
        }
        else if (right == str_len-1)
        {
            str.replace(left,right-left+1,right-left+1,str[left-1]);
            continue;
        }
        str.replace(left,right-left+1,right-left+1,str[left-1]);
    }

}

void case_solve()
{
    int X, Y;
    string str;
    cin >> X >> Y >> str;

    bool empty_status = false;
    int str_len = str.length();
    vector<int> empty_spaces;
    for (int i = 0; i < str_len; ++i)
    {
        if (str[i]-'?' == 0)
        {
            if (!empty_status)
            {
                empty_status = true;
                empty_spaces.push_back(i);
            }
        }
        else
        {
            if (empty_status)
            {
                empty_status = false;
                empty_spaces.push_back(i-1);
            }
        }
    }
    if (empty_status) empty_spaces.push_back(str_len-1);

    fill_empty(str, empty_spaces, X, Y);
    cout << count_cost(str, X, Y) << '\n';
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