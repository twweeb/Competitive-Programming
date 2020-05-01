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
set<int> unTrueClause, TrueClause, pureClause, unsatClause;

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

void print_clause(int top_k ) //For Debug
{
    for(int i = 0; i < top_k; ++i)
    {
        cout << "(Clause " << i << " is " << isTrue[i] << ") ";
        for (int j : clause[i]) cout << (isAssign[abs(j)] & (!(var[abs(j)]^(j>0)))) << " ";
        cout << endl;
    }
    cout << "TrueClause: ";
    for (auto i : TrueClause) cout << i << " ";
    cout << "\nunTrueClause: ";
    for (auto i : unTrueClause) cout << i << " ";
    cout << "\npureClause: ";
    for (auto i : pureClause) cout << i << " ";
    cout << "\nunsatClause: ";
    for (auto i : unsatClause) cout << i << " ";
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

void check_pureClause()
{
    for (int i = 0; i < m; ++i)
    {
        if (clause_unassigned_elem[i] == 0 && !isTrue[i]) unsatClause.insert(i);
        else unsatClause.erase(i);
        if (clause_unassigned_elem[i] == 1 && !isTrue[i]) pureClause.insert(i);
        else pureClause.erase(i);
    }
}

void resolution(int ConflicClauseID, int p)
{
    for (int clauseID: unsatClause)
    {
        for (int elem: clause[clauseID]) 
        {
            if (abs(elem) == p) continue;
            clause_unassigned_elem[m]++;
            if (elem > 0) 
            {
                clause[m].push_back(elem);
                relatedClause_pos[elem].push_back(m);
            }
            else 
            {
                clause[m].push_back(elem);
                relatedClause_neg[-elem].push_back(m);
            }
        }
        for (int elem: clause[ConflicClauseID]) 
        {
            if (abs(elem) == p) continue;
            clause_unassigned_elem[m]++;
            if (elem > 0) 
            {
                clause[m].push_back(elem);
                relatedClause_pos[elem].push_back(m);
            }
            else 
            {
                clause[m].push_back(elem);
                relatedClause_neg[-elem].push_back(m);
            }
        }
        unTrueClause.insert(m);
        m++;
    }
}

bool conflict_analysis(set<int>& clause_set2true, set<int>& var_set)
{
    int clauseID, var_name;
    check_pureClause();
    while (!pureClause.empty() && unsatClause.empty())
    {
        clauseID = *pureClause.begin();
        pureClause.erase(clauseID);
        for (int i : clause[clauseID]) 
        {
            if (!isAssign[abs(i)]) 
            {
                var_name = i;
                break;
            }
        }
        isAssign[abs(var_name)] = true;
        cnt_unassigned_elem(abs(var_name), true);
        var_set.insert(abs(var_name));
        var[abs(var_name)] = (var_name > 0) ? true : false;
        isTrue[clauseID] = true;
        unTrueClause.erase(clauseID);
        TrueClause.insert(clauseID);
        clause_set2true.insert(clauseID);

        for (int relateClauseID: (var_name > 0) ? relatedClause_pos[abs(var_name)] : relatedClause_neg[abs(var_name)])
        {
            if (!isTrue[relateClauseID])
            {
                isTrue[relateClauseID] = true;
                unTrueClause.erase(relateClauseID);
                TrueClause.insert(relateClauseID);
                clause_set2true.insert(relateClauseID);
                pureClause.erase(relateClauseID);
            }  
        }
        check_pureClause();
    }
    if (!unsatClause.empty()) 
    {
        resolution(clauseID, abs(var_name));
        return true; //Conflict
    }
    return false; //not Conflict
}

bool dfs(int cur)
{
    if (TrueClause.size() == m) return true;
    if (cur == -1 || !unsatClause.empty()) return false;
    if (isAssign[cur]) return dfs(next_var());

    bool isConflict = false, isDone = false, isSecondTry = false, curTry;
    curTry = relatedClause_pos[cur].size() > relatedClause_neg[cur].size();
    isAssign[cur] = true;
    var[cur] = curTry;
    cnt_unassigned_elem(cur, true);
    set<int> clause_set2true, var_set;

    CheckAgain:
    for (int clauseId : (curTry) ? relatedClause_pos[cur] : relatedClause_neg[cur])
    {
        if (isTrue[clauseId]) continue;
        isTrue[clauseId] = true;
        unTrueClause.erase(clauseId);
        TrueClause.insert(clauseId);
        clause_set2true.insert(clauseId);
    }
    isConflict = conflict_analysis(clause_set2true, var_set);
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
    check_pureClause();
    
    if (!isSecondTry && (isConflict || !isDone))
    {
        isConflict = isDone = false;
        curTry = !curTry;
        var[cur] = curTry;
        isSecondTry = true;
        goto CheckAgain;
    }
    isAssign[cur] = false; cnt_unassigned_elem(cur, false);
    return false;
}

void init() 
{
    string str = "";
    while (getline(cin, str))
    {
        if (str[0] - 'p' != 0) continue;
        stringstream ss(str);
        string tmp;
        ss >> tmp >> tmp >> n >> m;
        break;
    }
    for (int i = 1; i <= n; ++i) isAssign[i] = var[i] = false;
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
                isAssign[abs(z)] = true;
                cnt_unassigned_elem(abs(z), true);
                var[abs(z)] = z > 0;
                isTrue[i] = true;
                clause_unassigned_elem[i]--;
                if (z > 0) for(int clauseID : relatedClause_pos[z]) isTrue[clauseID] = true;
                else for(int clauseID : relatedClause_neg[-z]) isTrue[clauseID] = true;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (isTrue[i]) TrueClause.insert(i);
        else unTrueClause.insert(i);
        if (clause_unassigned_elem[i] == 1) pureClause.insert(i);
    }
    // pure literal assign
    for (int i = 1; i <= n; ++i)
    {
        if (relatedClause_pos[i].size() == 0 || relatedClause_neg[i].size() == 0)
        {
            isAssign[i] = true;
            cnt_unassigned_elem(i, true);
            var[i] = relatedClause_pos[i].size() > relatedClause_neg[i].size();
            for (int j: (var[i]) ? relatedClause_pos[i] : relatedClause_neg[i]) 
            {
                if (isTrue[j]) continue;
                isTrue[j] = true;
                TrueClause.insert(j);
                unTrueClause.erase(j);
            }
        }
    }
    check_pureClause();
}

void solve() {
    init();
    if (dfs(1)) cout << "sat\n";
    else cout << "unsat\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
