//
//  Append_Sort.cpp
//  2021 Google Code Jam Round 1A, Append Sort
//
//  Created by Lei Hsiung on 2021/04/10.
//  Copyright © 2021 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define INF 1<<30

bool is_small_than(string a, string b)
{
    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i]<b[i]) return true;
        else if (a[i]>b[i]) return false;
    }
    return false;
}

int extend(string &a, int op_cnt)
{
    for (int i = 0; i < op_cnt; ++i) a.append("0");
    return op_cnt;
}

string string_add_1(string a)
{
    for (int i = a.length()-1; i>=0; i--)
    {
        if (a[i]-'9'!=0) 
        {
            a[i] = a[i]+1;
            return a;
        }
        else a[i] = '0';
    }
    a.push_back('0');
    return a;
}

int add_one_in_a_to_b(string &a, string &b)
{
    int cnt = 0, i = 0;

    int tmp = b.length();
    b.append(string_add_1(a.substr(b.length(),a.length() - b.length())));
    cnt+= b.length()-tmp;
    
    return cnt;
}

int get_min_op(string& a, string& b)
{
    int cnt = 0;
    if (b.length()>a.length()) return cnt;
    else if (b.length()==a.length())
    {
        if (is_small_than(a,b)) return cnt;
        else
        {
            b.append("0");
            cnt ++;
            return cnt;
        }
    }
    else
    {
        for (int i = 0; i < b.length(); ++i)
        {
            if (a[i] > b[i]) 
            {
                cnt += extend(b, a.length()-b.length());
                cnt += get_min_op(a,b);
                return cnt;
            }
            else if (a[i] < b[i])
            {
                cnt += extend(b, a.length()-b.length());
                return cnt;
            }
        }
        cnt += add_one_in_a_to_b(a,b);
        return cnt;
    }
}

int count_op(int num)
{
    vector<string> seq;
    int cnt = 0;
    for (int i = 0; i < num; ++i)
    {
        string tmp;
        cin >> tmp;
        seq.push_back(tmp);
    }
    for (int i = 0; i< seq.size()-1; ++i) cnt += get_min_op(seq[i],seq[i+1]);
    
    return cnt;
}

void case_solve()
{
    int N;
    cin >> N;
    cout << count_op(N) << '\n';
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