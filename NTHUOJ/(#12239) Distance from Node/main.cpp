//
//  main.cpp
//  (#12239) Distance from Node
//
//  Created by LeiHsiung on 2019/5/13.
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
    int getFar();
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
        distance[i] = 0;
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
                        distance[*itr] = distance[u] + max(u,*itr);
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

int Graph::getFar(){
    int max = -1,idx = 0;
    for(int i = 0; i< num_vertex;i++){
        if(isLeaf[i]){
            if(distance[i] > max){
                max = distance[i];
                idx = i;
            }
        }
    }
    return max;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, u = 0, v = 0;
    cin >> n;
    Graph g1(n);
    
    while(cin >> u){
        cin >> v;
        if(!cin.eof()){
            //cout << "hello" <<endl;
            g1.AddEdgeList(u, v);
            g1.AddEdgeList(v, u);
        }
        else{
            //cout << "hello" <<endl;
            g1.BFS(u);
            break;
        }
    }
    cout << g1.getFar() << endl;
    return 0;
}
