//
//  main.cpp
//  DAG Probability
//
//  Created by LeiHsiung on 2019/5/5.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph{
private:
    int N, *ref;
    double *probability;
    bool *isLeaf;
    vector< list<int> > adj;
public:
    Graph(int N):N(N){
        adj.resize(N);
        ref = new int[N];
        probability = new double[N];
        isLeaf = new bool[N];
        for(int i = 0; i< N; i++){
            ref[i] = 0;
            probability[i] = 0.0;
            isLeaf[i] = true;
        }
    };
    void AddEdgeList(int from, int to);
    void topoSortUtil(int v, bool visited[], stack<int> &Stack);
    void topoSort();
};
void Graph::AddEdgeList(int from, int to){
    adj[from].push_back(to);
    ++ref[to];
    isLeaf[from] = false;
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
    int t = 0;
    stack<int> Stack;
    list<int>::iterator it;
    double size,maxP = 0.0;
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
    
    for (int i = 0; i < N; i++)
        if (visited[i] == false)
            topoSortUtil(i, visited, Stack);

    probability[0] = 1.0;
    while (!Stack.empty())
    {
        size = adj[t = Stack.top()].size();
        for (it = adj[t].begin(); it != adj[t].end(); ++it)
            probability[*it] += probability[Stack.top()]* (1.0/size);
        Stack.pop();
        if(isLeaf[t]) maxP = max(maxP,probability[t]);
    }
    for(int i = 0; i < N;++i){
        if(isLeaf[i] && probability[i] == maxP)
            cout << "Pond " << i << ", probability: " << probability[i] <<endl;
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
    }
    return 0;
}
