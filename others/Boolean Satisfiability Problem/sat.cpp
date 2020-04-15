//
//  sat.cpp
//  Applied Mathematical Logic Programming Assignment - Boolean Satisfiability Problem
//
//  Created by Lei Hsiung on 2020/04/13.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

#define MAXN 30000
#define MAXM 60000

using namespace std;

int n = 0, m = 0, limit_time = 0;
bool var[MAXN], isAssign[MAXN], isTrue[MAXM];
vector<int> clause[MAXM], relatedClause_pos[MAXN], relatedClause_neg[MAXN];

bool check()
{
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
    bool isConflict = false, isDone = false, isForTrue = false;
    vector<int> set2true, var_set2true;

CheckAgain:
    for (int clauseId : (isForTrue) ? relatedClause_pos[cur] : relatedClause_neg[cur])
    {
        if (isTrue[clauseId]) continue;
        isTrue[clauseId] = true;
        set2true.push_back(clauseId);
    }
    for (int clauseId : (isForTrue) ? relatedClause_neg[cur] : relatedClause_pos[cur])
    {
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
                isAssign[abs(var_name)-1] = true;
                var_set2true.push_back(abs(var_name)-1);
                var[abs(var_name)-1] = (var_name > 0) ? true : false;
                isTrue[clauseId] = true;
                set2true.push_back(clauseId);
                if (var_name > 0)
                {
                    for (int relateClauseID: relatedClause_pos[abs(var_name)-1])
                    {
                        if (!isTrue[relateClauseID])
                        {
                            isTrue[relateClauseID] = true;
                            set2true.push_back(relateClauseID);
                        }  
                    }
                }
                else
                {
                    for (int relateClauseID: relatedClause_neg[abs(var_name)-1])
                    {
                        if (!isTrue[relateClauseID])
                        {
                            isTrue[relateClauseID] = true;
                            set2true.push_back(relateClauseID);
                        }  
                    }
                }
            }
            else if (not_assign == 0 && !isTrue[clauseId]) 
            {
                isConflict = true;
                break;
            }
        }
    }
    if (!isConflict) 
    {
        isDone = dfs(cur+1);
        if (isDone) return true;
    }
    for (int clauseId : set2true) isTrue[clauseId] = false;
    for (int var_ass : var_set2true) isAssign[var_ass] = false;
    set2true.clear();
    var_set2true.clear();

    if (!isForTrue && (isConflict || !isDone))
    {
        isConflict = isDone = false;
        var[cur] = true;
        isForTrue = true;
        goto CheckAgain;
    }
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
                relatedClause_pos[t-1].push_back(i);
            }
            else 
            {
                clause[i].push_back(t);
                relatedClause_neg[-t-1].push_back(i);
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
