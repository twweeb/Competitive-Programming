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

int n = 0, m = 0, limit_time = 0, clause_unassigned_elem[MAXM] = {0}, alert = 0;
bool var[MAXN], isAssign[MAXN], isTrue[MAXM];
vector<int> clause[MAXM], relatedClause_pos[MAXN], relatedClause_neg[MAXN];
set<int> unTrueClause, TrueClause;
chrono::steady_clock::time_point time_start;

int next_var() {
    int rclause = 0, var_name = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (isAssign[i]) continue;
        if (relatedClause_pos[i].size()+relatedClause_neg[i].size() > rclause) {
            var_name = i;
            rclause = relatedClause_pos[i].size() + relatedClause_neg[i].size();
        }
    }
    return var_name;
}

void print_clause(int top_k )
{
    for(int i = 150; i < m; ++i)
    {
        cout << "(Clause " << i << " is " << isTrue[i] << ") ";
        for(int j : clause[i]) cout << (isAssign[abs(j)] & (!(var[abs(j)]^(j>0)))) << " ";
        cout << endl;
    }
    cout << "TrueClause: ";
    for(auto i : TrueClause) cout << i << " ";
    cout << "\nunTrueClause: ";
    for(auto i : unTrueClause) cout << i << " ";
    cout << endl;
}

void cnt_unassigned_elem(int p, bool toAssign)
{
    if(toAssign)
    {
        for (int clauseID : relatedClause_pos[p]) clause_unassigned_elem[clauseID]--;
        for (int clauseID : relatedClause_neg[p]) clause_unassigned_elem[clauseID]--;
    }
    else
    {
        for (int clauseID : relatedClause_pos[p]) clause_unassigned_elem[clauseID]++;
        for (int clauseID : relatedClause_neg[p]) clause_unassigned_elem[clauseID]++;
    }
}

bool dfs(int cur)
{
    if (TrueClause.size() == m) return true;
    if (cur == -1) return false;
    if (isAssign[cur]) return dfs(next_var());

    isAssign[cur] = true;
    var[cur] = false;
    cnt_unassigned_elem(cur, true);
    bool isConflict = false, isDone = false, isForTrue = false, second_try = false;
    set<int> clause_set2true, var_set;

    CheckAgain:
    for (int clauseId : (isForTrue) ? relatedClause_pos[cur] : relatedClause_neg[cur])
    {
        if (isTrue[clauseId]) continue;
        isTrue[clauseId] = true;
        unTrueClause.erase(clauseId);
        TrueClause.insert(clauseId);
        clause_set2true.insert(clauseId);
    }
    for (int clauseId : (isForTrue) ? relatedClause_neg[cur] : relatedClause_pos[cur])
    {
        if (!isTrue[clauseId])
        {
            if (clause_unassigned_elem[clauseId] == 1)
            {
                int var_name;
                for (int elem : clause[clauseId]) 
                if(!isAssign[abs(elem)]) var_name = elem;

                isAssign[abs(var_name)] = true;
                cnt_unassigned_elem(abs(var_name), true);
                var_set.insert(abs(var_name));
                var[abs(var_name)] = (var_name > 0) ? true : false;
                isTrue[clauseId] = true;
                unTrueClause.erase(clauseId);
                TrueClause.insert(clauseId);
                clause_set2true.insert(clauseId);
                
                if (var_name > 0)
                {
                    for (int relateClauseID: relatedClause_neg[abs(var_name)])
                    {
                        if (!isTrue[relateClauseID] && clause_unassigned_elem[relateClauseID] == 0)
                        {
                            isConflict = true; break;
                        }  
                    }
                    if(!isConflict)
                    for (int relateClauseID: relatedClause_pos[abs(var_name)])
                    {
                        if (!isTrue[relateClauseID])
                        {
                            isTrue[relateClauseID] = true;
                            unTrueClause.erase(relateClauseID);
                            TrueClause.insert(relateClauseID);
                            clause_set2true.insert(relateClauseID);
                        }  
                    }
                }
                else
                {
                    for (int relateClauseID: relatedClause_pos[abs(var_name)])
                    {
                        if (!isTrue[relateClauseID] && clause_unassigned_elem[relateClauseID] == 0)
                        {
                            isConflict = true; break;
                        }  
                    }
                    if(!isConflict)
                    for (int relateClauseID: relatedClause_neg[abs(var_name)])
                    {
                        if (!isTrue[relateClauseID])
                        {
                            isTrue[relateClauseID] = true;
                            unTrueClause.erase(relateClauseID);
                            TrueClause.insert(relateClauseID);
                            clause_set2true.insert(relateClauseID);
                        }  
                    }
                }
            }
            else if (clause_unassigned_elem[clauseId] == 0 && !isTrue[clauseId]) isConflict = true;
            if (isConflict) break;
        }
    }
    if (!isConflict) 
    {
        isDone = dfs(next_var());
        if (isDone) return true;
    }
    
    for (int clauseId : clause_set2true) 
    {
        isTrue[clauseId] = false;
        unTrueClause.insert(clauseId);
        TrueClause.erase(clauseId);
    }
    for (int var_ass : var_set) 
    {
        isAssign[var_ass] = false;
        cnt_unassigned_elem(var_ass, false);
    }
    clause_set2true.clear(); var_set.clear();

    if (!isForTrue && (isConflict || !isDone))
    {
        isConflict = isDone = false;
        var[cur] = true;
        isForTrue = true;
        goto CheckAgain;
    }
    isAssign[cur] = false; cnt_unassigned_elem(cur, false);
    return false;
}

void solve() {
    string str = "";
    while (getline(cin, str))
    {
        if (str[0] - 'p' != 0) continue;
        stringstream ss(str);
        string tmp;
        ss >> tmp >> tmp >> n >> m;
        break;
    }
    for (int i = 0; i < n; ++i) isAssign[i] = var[i] = false;
    for (int i = 0; i < m; ++i)
    {
        isTrue[i] = false;
        int t;
        cin >> t;
        while (t != 0)
        {
            clause_unassigned_elem[i]++;
            if (t > 0) 
            {
                clause[i].push_back(t);
                relatedClause_pos[t].push_back(i);
            }
            else 
            {
                clause[i].push_back(t);
                relatedClause_neg[-t].push_back(i);
            }
            if (isAssign[abs(t)])
            {
                if ((t > 0 && var[abs(t)]) || (t < 0 && !var[abs(t)])) isTrue[i] = true;
                clause_unassigned_elem[i]--;
            }
            cin >> t;
        }
        if (clause_unassigned_elem[i] == 0 && !isTrue[i])
        {
            cout << "unsat\n";
            exit(0);
        }
        else if (clause_unassigned_elem[i] == 1 && !isTrue[i])
        {
            for (int z: clause[i]) 
            {
                if (isAssign[abs(z)]) continue;
                isAssign[abs(t)] = true;
                var[abs(z)] = t > 0;
                isTrue[i] = true;
                clause_unassigned_elem[i]--;
                if (z > 0) for(int clauseID : relatedClause_pos[z]) isTrue[clauseID] = true;
                else for(int clauseID : relatedClause_neg[-z]) isTrue[clauseID] = true;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if(isTrue[i]) TrueClause.insert(i);
        else unTrueClause.insert(i);
    }
    if (dfs(1)) cout << "sat\n";
    else cout << "unsat\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    time_start = chrono::steady_clock::now();
    solve();
}
