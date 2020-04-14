//
//  sat.cpp
//  Applied Mathematical Logic Programming Assignment - Boolean Satisfiability Problem
//
//  Created by Lei Hsiung on 2020/04/13.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

#define MAXN 160
#define MAXM 1200

using namespace std;

vector<int> clause[MAXM], relatedClause[MAXN];
int n = 0, m = 0;
bool var[MAXN], isAssign[MAXN], isTrue[MAXM];

bool check()
{
    //cout << "------------------m: " << m << " n: " << n << "---------------" << endl;
    bool isSat = true;
    for (int i = 0; i < m; ++i) isSat &= isTrue[i];
    return isSat;
}

bool dfs(int cur)
{
    if(cur == n) return check();
    if(isAssign[cur]) return dfs(cur+1);

    isAssign[cur] = true;
    var[cur] = false;
    bool isConflict = false, isDone = false, isForTrue = false;;
    vector<int> set2true;

CheckAgain:
    for (int clauseId : relatedClause[cur])
    {
        if (isTrue[clauseId]) continue;
        for(int elem : clause[clauseId])
        {
            if(abs(elem) - 1 == abs(cur))
            {
                if(!isForTrue && elem < 0)
                {
                    isTrue[clauseId] = true;
                    set2true.push_back(clauseId);
                    break;
                }
                if(isForTrue && elem > 0)
                {
                    isTrue[clauseId] = true;
                    set2true.push_back(clauseId);
                    break;
                }
            }
        }
        if (!isTrue[clauseId])
        {
            int not_assign = 0, var_name;
            for (int elem : clause[clauseId])
            {
                if(!isAssign[abs(elem) - 1]) 
                {
                    not_assign++;
                    var_name = elem;
                }
            }
            if (not_assign == 1)
            {
                if (!isTrue[clauseId])
                {
                    isAssign[abs(var_name)-1] = true;
                    var[abs(var_name)-1] = (var_name > 0) ? true : false;
                    isTrue[clauseId] = true;
                    set2true.push_back(clauseId);
                }
            }
            else if (not_assign == 0 && !isTrue[clauseId]) isConflict = true;
        }
    }
    if (!isConflict) 
    {
        isDone = dfs(cur+1);
        if (isDone) return true;
    }

    if (!isForTrue && (isConflict || !isDone))
    {
        isConflict = isDone = false;
        for(int clauseId : set2true) isTrue[clauseId] = false;
        set2true.clear();
        var[cur] = true;
        isForTrue = true;
        goto CheckAgain;
    }
    if(isConflict) return false;
    isAssign[cur] = false;
    return false;
}

void solve() {
    string str = "";
    while(getline(cin, str))
    {
        if (str[0] - 'p' != 0) continue;
        stringstream ss(str);
        string in;
        for (int i = 0; i < 4; ++i)
        {
            ss >> in;
            if (i < 2) continue;
            else if (i == 2) n = stoi(in); // variable numbers
            else if (i == 3) m = stoi(in); // clause numbers
        }
        break;
    }
    for (int i = 0; i < m; ++i)
    {
        vector<int> tmp(n);
        for (int j = 0; j < n; ++j) tmp[j] = -1;
        int t;
        cin >> t;
        while (t != 0)
        {
            if (t > 0) 
            {
                clause[i].push_back(t);
                relatedClause[t-1].push_back(i);
            }
            else 
            {
                clause[i].push_back(t);
                relatedClause[-t-1].push_back(i);
            }
            cin >> t;
        }
    }
    for (int i = 0; i < n; ++i) isAssign[i] = var[i] = false;
    for (int i = 0; i < m; ++i) isTrue[i] = false;
    if (dfs(0)) cout << "sat\n";
    else cout << "unsat\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
