//
//  main.cpp
//  (#11923) All Pair Shortest Paths
//
//  Created by Magic Bear on 2018/5/17.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 110
#define INF 100000000

using namespace std;

int N;
int G[MAXN][MAXN]; // adj matrix
int T[MAXN][MAXN]; // transfrom state
int n[MAXN][MAXN]; // next

int main(int argc, const char * argv[]) {
    cin >> N;
    for(int i=0; i<N ; ++i)
    {
        for(int j=0 ; j<N ; ++j)
        {
            cin >> G[i][j];
            if(G[i][j])
            {
                T[i][j] = G[i][j];
                n[i][j] = j;
            }
            else
                T[i][j] = INF;
        }
    }
    for(int k=0 ; k<N ; ++k) // Floyd Warshall
    {
        for(int i=0 ; i<N ; ++i)
        {
            for(int j=0 ; j<N ; ++j)
            {
                if(T[i][k]+T[k][j] < T[i][j])
                {
                    T[i][j] = T[i][k]+T[k][j];
                    n[i][j] = n[i][k];
                }
                if(T[i][k]+T[k][j] == T[i][j])
                    n[i][j] = min(n[i][j],n[i][k]);
            }
        }
    }
    for(int i=0 ; i<N ; ++i)
    {
        for(int j=0 ; j<N ; ++j)
        {
            if(i!=j && T[i][j]!=INF)
            {
                cout << "Path(" << i << ',' << j << "):";
                cout << i;
                int cur = i;
                while (cur!=j) {
                    cur = n[cur][j];
                    cout << "->" << cur;
                }
                cout << endl;
                cout << "Cost:" << T[i][j] << endl;
            }
        }
    }
    return 0;
}
