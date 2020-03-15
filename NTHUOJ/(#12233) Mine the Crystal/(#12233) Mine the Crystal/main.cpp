//
//  main.cpp
//  (#12233) Mine the Crystal
//
//  Created by LeiHsiung on 2019/5/13.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph{
private:
    int N, *ref,sum;
    int *pool;
    bool *isHead;
    vector< list<int> > adj;
public:
    Graph(int N):N(N){
        adj.resize(N);
        ref = new int[N];
        pool = new int[N];
        isHead = new bool[N];
        for(int i = 0; i< N; i++){
            ref[i] = 0;
            pool[i] = 0;
            isHead[i] = true;
            sum = 0;
        }
    };
    void AddEdgeList(int from, int to);
    void topoSortUtil(int v, bool visited[], stack<int> &Stack);
    void topoSort();
    int getSum();
};
int Graph::getSum(){
    return sum;
}
void Graph::AddEdgeList(int from, int to){
    adj[from].push_back(to);
    ++ref[to];
    isHead[to] = false;
}
void Graph::topoSortUtil(int v, bool visited[],stack<int> &Stack){
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topoSortUtil(*i, visited, Stack);
    Stack.push(v);
}
void Graph::topoSort(){
    int t = 0,cost = 0,maxP = 1000000;
    unsigned long size;
    stack<int> Stack;
    list<int>::iterator it;
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
    
    for (int i = 0; i < N; i++)
        if (visited[i] == false)
            topoSortUtil(i, visited, Stack);
    
    for (int i = 0; i < N; i++)
        if (isHead[i] == true){
            pool[i] = 1;
            cost++;
        }
    while (!Stack.empty())
    {
        size = adj[t = Stack.top()].size();
        for (it = adj[t].begin(); it != adj[t].end(); ++it){
            pool[*it] += pool[Stack.top()];
            pool[*it] = min(maxP,pool[*it]);
        }
        Stack.pop();
    }
    sum -= cost;
    for(int i = 0; i < N; i++){
        //cout << i << ": " << pool[i] <<endl;
        sum += pool[i];
    }
}

int main(){
    int n = 0, p = 0, q = 0, u = 0, v = 0;
    cin >> n;
    while(n--){
        cin >> p >> q;
        Graph dag(p);
        while(q--){
            cin >> u >> v;
            dag.AddEdgeList(u, v);
        }
        dag.topoSort();
        cout << dag.getSum() << endl;
    }
    return 0;
}
