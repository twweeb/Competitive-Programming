//
//  main.cpp
//  (#12235) Minimums around Node
//
//  Created by LeiHsiung on 2019/5/2.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph{
private:
    int num_vertex,upBound;
    vector< list<int> > AdjList;
    int *color,
    *distance,
    *predecessor;
    bool *isLeaf;
public:
    Graph():num_vertex(0){};
    Graph(int N):num_vertex(N){
        AdjList.resize(num_vertex);
        isLeaf = new bool[num_vertex];
        for(int i = 0; i < num_vertex; i++)
            isLeaf[i] = true;
    };
    void AddEdgeList(int from, int to);
    void BFS(int Start);
    int dist(int to);
    void setLeaf();
    int getupBound();
};

void Graph::AddEdgeList(int from, int to){
    AdjList[from].push_back(to);
}

void Graph::BFS(int Start){
    color = new int[num_vertex];
    predecessor = new int[num_vertex];
    distance = new int[num_vertex];
    
    for (int i = 0; i < num_vertex; i++) {
        color[i] = 0;
        predecessor[i] = -1;
        distance[i] = num_vertex+1;
    }
    
    queue<int> q;
    int i = Start;
    
    for (int j = 0; j < num_vertex; j++) {
        if (color[i] == 0) {
            color[i] = 1;
            distance[i] = 0;
            predecessor[i] = -1;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                for (list<int>::iterator itr = AdjList[u].begin();
                     itr != AdjList[u].end(); itr++) {
                    if (color[*itr] == 0) {
                        color[*itr] = 1;
                        distance[*itr] = distance[u] + 1;
                        predecessor[*itr] = u;
                        q.push(*itr);
                    }
                }
                q.pop();
                color[u] = 2;
            }
        }
        i = j;
    }
}

int Graph::dist(int to){
    for(int i = 0; i< num_vertex; i ++){
        if(distance[i] == to){
            return i+1;
        }
    }
    return 0;
}

void Graph::setLeaf(){
    int m = 0 , n = 1e6;
    for(int i = 0; i< num_vertex; i++){
        if(AdjList[i].size() != 1)
            isLeaf[i] = false;
        else
        {
            m = max(m,distance[i]);
            n = min(n,distance[i]);
        }
    }
    
    //cout << "m: " <<m <<" n: " <<n<< endl;
    upBound = m - n;
}


int Graph::getupBound(){
    return upBound;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, u = 0, v = 0, sum = 0;
    cin >> n;
    Graph g1(n);
    
    while(cin >> u){
        cin >> v;
        if(!cin.eof()){
            g1.AddEdgeList(u-1, v-1);
            g1.AddEdgeList(v-1, u-1);
        }
        else{
            g1.BFS(u-1);
            break;
        }
    }
    g1.setLeaf();
    for(int i = 0; i <= g1.getupBound(); i ++){
        //cout << i << ": " <<g1.dist(i) << endl;
        sum += g1.dist(i);
    }
    cout << sum << endl;
    return 0;
}
