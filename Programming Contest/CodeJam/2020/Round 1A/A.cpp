//
//  A.cpp
//  2020 Google Code Jam Round 1C A.Overexcited Fan
//
//  Created by Lei Hsiung on 2021/03/05.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

vector<string> split_by_star(string str)
{
    istringstream s(str);
    string segment;
    vector<string> tmp;
    while (getline(s, segment, '*')) tmp.push_back(segment);
    if (str[str.length()-1] - '*' == 0) tmp.push_back("");
    return tmp;
}

bool is_begin_with(string& str, string& pattern)
{
    if (pattern.empty()) return true;
    for (int i = 0; i < pattern.length(); ++i)
        if (str[i]-pattern[i] != 0) return false;
    return true;
}

bool is_end_with(string& str, string& pattern)
{
    if (pattern.empty()) return true;
    int str_len = str.length(), pattern_len = pattern.length();
    for (int i = 0; i < pattern_len; ++i)
        if (str[str_len-i-1]-pattern[pattern_len-i-1] != 0) return false;
    return true;
}

bool check_solved(vector<vector<string>>& conds, string& longest_pre, string& longest_post)
{
    for (auto split_str: conds)
    {
        if (!is_begin_with(longest_pre, split_str.front())) return false;
        if (!is_end_with(longest_post, split_str.back())) return false;
    }
    return true;
}

void case_solve()
{
    int cond_num;
    vector<vector<string>> conds;
    vector<string> pre, post;
    string tmp;
    cin >> cond_num;
    
    for (int j = 0; j < cond_num; ++j)
    {
        cin >> tmp;
        conds.push_back(split_by_star(tmp));
        pre.push_back(conds[j][0]);
        post.push_back(conds[j].back());
    }

    string longest_pre="", longest_post="";
    for (auto s: pre) if (s.length() > longest_pre.length()) longest_pre = s;
    for (auto s: post) if (s.length() > longest_post.length()) longest_post = s;

    bool solved = check_solved(conds, longest_pre, longest_post);

    if (solved)
    {
        string ans(longest_pre);
        for (auto split_str: conds)
            for (auto str_elem: split_str)
                ans += str_elem;
        ans += longest_post;
        cout << ans << '\n';
    }
    else cout << "*\n";
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
