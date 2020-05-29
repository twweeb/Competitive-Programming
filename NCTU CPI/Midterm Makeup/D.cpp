//
//  D.cpp
//  NCTU CPI Midterm Makeup
//
//  Created by Lei Hsiung on 2020/05/29.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q, setCnt = 0;
    cin >> n >> q;

    int idxInSet[10*n];
    map<int, int> setRep, inWhichSet;
    set<int> disjointSet[10*n];
    for(int i=1 ; i<=n ; ++i)
    {
        int k;
        cin >> k;
        if(inWhichSet.find(k)==inWhichSet.end())
        {
            idxInSet[i] = setCnt;
            inWhichSet[k] = setCnt;
            setRep[setCnt] = k;
            disjointSet[setCnt].insert(i);
            setCnt++;
        }
        else
        {
            idxInSet[i] = inWhichSet[k];
            disjointSet[inWhichSet[k]].insert(i);
        }
    }
    while(q--)
    {
        int op, v, p;
        cin >> op >> v >> p;
        if(op==2)
        {
            if(inWhichSet.find(p)!=inWhichSet.end()) // p exists
            {
                int id = inWhichSet[p];
                if(inWhichSet.find(v)!=inWhichSet.end())
                {
                    int Vid = inWhichSet[v];
                    if (disjointSet[Vid].size() < disjointSet[id].size())
                    {
                        for(auto &it : disjointSet[Vid])
                        {
                            disjointSet[id].insert(it);
                            idxInSet[it] = id;
                        }
                        disjointSet[Vid].clear();
                        //setRep.erase(Vid);
                        //inWhichSet.erase(v);
                    }
                    else
                    {
                        for(auto &it : disjointSet[Vid]) idxInSet[it] = id;
                        for(auto &it : disjointSet[id]) disjointSet[Vid].insert(it);
                        
                        disjointSet[id] = disjointSet[Vid];
                        disjointSet[Vid].clear();
                    }
                    
                }
            }
            else if(inWhichSet.find(v)!=inWhichSet.end())
            {
                int Vid = inWhichSet[v];
                setRep[Vid] = p;
                inWhichSet[p] = Vid;
                inWhichSet.erase(v);
            }
        }
        else if(op==3)
        {
            if(inWhichSet.find(p)==inWhichSet.end() || disjointSet[inWhichSet[p]].empty()) cout << "-1" << '\n';
            else
            {
                int id = inWhichSet[p];
                auto l_it = disjointSet[id].lower_bound(v);
                if(l_it == disjointSet[id].end()) cout << abs(*(--l_it)-v) << '\n';
                else
                {
                    int res = *l_it;
                    if(l_it!=disjointSet[id].begin())
                    {
                        int pre_res = *(--l_it);
                        cout << min(abs(res-v), abs(pre_res-v)) << '\n';
                    }
                    else cout << abs(res-v) << '\n';
                }
            }
        }
        else
        {
            int id = idxInSet[v];
            if(inWhichSet.find(p)==inWhichSet.end())
            {
                idxInSet[v] = setCnt;
                inWhichSet[p] = setCnt;
                setRep[setCnt] = p;
                disjointSet[setCnt].insert(v);
                setCnt++;
            }
            else
            {
                disjointSet[inWhichSet[p]].insert(v);
                disjointSet[id].erase(v);
                idxInSet[v] = inWhichSet[p];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
