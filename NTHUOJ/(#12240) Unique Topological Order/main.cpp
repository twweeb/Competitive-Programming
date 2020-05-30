//
//  main.cpp
//  (#12240) Unique Topological Order
//
//  Created by LeiHsiung on 2019/5/5.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
private:
    int num_vertex;
    vector< list<int> > AdjList;
    int *ref;
public:
    Graph():num_vertex(0){};
    Graph(int N):num_vertex(N){
        AdjList.resize(num_vertex);
        ref = new int[num_vertex];
        for(int i = 0; i< num_vertex; i++) ref[i] = 0;
    };
    void AddEdgeList(int from, int to);
    void TopologicalOrdering();
};

void Graph::AddEdgeList(int from, int to){
    AdjList[from].push_back(to);
    ++ref[to];
}

void Graph::TopologicalOrdering(){
    for(int i = 0; i < num_vertex; ++i){
        int s = 0;
        while(s < num_vertex && (ref[s]>0 || ref[s] == -1)) ++s;
        if(s == num_vertex) break;
        
        ref [s] = -1;
        if(i != 0) cout << " ";
        cout << s;
        while(!AdjList[s].empty()){
            --ref[AdjList[s].back()];
            AdjList[s].pop_back();
        }
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0, p = 0, q = 0, u = 0, v = 0;
    cin >> n;

    while(n--){
        cin >> p >> q;
        Graph dag(p);
        while(q--){
            cin >> u >> v;
            dag.AddEdgeList(u, v);
        }
        dag.TopologicalOrdering();
    }
    return 0;
}
