//
//  main.cpp
//  TSP
//
//  Created by LeiHsiung on 2019/5/7.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <time.h>

using namespace std;

const int MAXN = 16;
const int INF = 0x3f3f3f3f;

int n, cost[MAXN][MAXN];
time_t t_start, t_end;

int dist, tmp[MAXN], ord[MAXN];
bool isBB, visit[MAXN];
void dfs(int cur, int cur_dist, int count)
{
    if(isBB)
    {
        if(dist <= cur_dist)
           return;
    }
    if(cur==0)
    {
        if(count==0)
        {
            tmp[count] = cur;
            for(int i=1; i<n ; ++i)
                if(!visit[i])
                    dfs(i, cur_dist+cost[cur][i], count+1);
        }
        if(count==n)
        {
            if(cur_dist<dist)
            {
                dist = cur_dist;
                for(int i=0 ; i<n ; ++i)
                    ord[i] = tmp[i];
            }
            return;
        }
    }
    else
    {
        visit[cur] = true;
        tmp[count] = cur;
        for(int i=0; i<n ; ++i)
            if(!visit[i])
                dfs(i, cur_dist+cost[cur][i], count+1);
        visit[cur] = false;
    }
}

void BF()
{
    t_start = clock();
    dist = INF;
    for(int i=0 ; i<n ; ++i)
        visit[i] = false;
    isBB = false;
    dfs(0, 0, 0);
    t_end = clock();
    double diff = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    ofstream output;
    output.open("BF.txt");
    output << "Solution : ";
    for(int i=0 ; i<n ; ++i)
        output << ord[i] << " - ";
    output << ord[0];
    output << "\nCost     : " << dist << "\nTime     : " << fixed << diff << " s";
}

void BB()
{
    t_start = clock();
    dist = INF;
    for(int i=0 ; i<n ; ++i)
        visit[i] = false;
    isBB = true;
    dfs(0, 0, 0);
    t_end = clock();
    double diff = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    ofstream output;
    output.open("BB.txt");
    output << "Solution : ";
    for(int i=0 ; i<n ; ++i)
        output << ord[i] << " - ";
    output << ord[0];
    output << "\nCost     : " << dist << "\nTime     : " << fixed << diff << " s";
}


void DP()
{
    t_start = clock();
    int dp[1<<MAXN][MAXN];
    pair<int,int> tr[1<<MAXN][MAXN];
    queue<pair<int,int> > Q;
    bool isQ[1<<MAXN][MAXN];
    for(int S=0 ; S<1<<n ; ++S)
        for(int v=0 ; v<n ; ++v)
        {
            if((1<<v)==S && v!=0)
            {
                dp[S][v] = cost[0][v];
                tr[S][v] = make_pair(S, v);
                Q.push(make_pair(S,v));
                isQ[S][v] = true;
            }
            else
            {
                dp[S][v] = INF;
                isQ[S][v] = false;
            }
        }
    
    while(!Q.empty())
    {
        int S = Q.front().first, v = Q.front().second;
        Q.pop();
        isQ[S][v] = false;
        for(int i=0 ; i<n ; ++i)
        {
            if(!((1<<i)&S))
            {
                int nextS = S | (1<<i);
                if(dp[S][v]+cost[v][i] < dp[nextS][i])
                {
                    dp[nextS][i] = dp[S][v]+cost[v][i];
                    tr[nextS][i] = make_pair(S, v);
                    if(!isQ[nextS][i])
                    {
                        Q.push(make_pair(nextS, i));
                        isQ[nextS][i] = true;
                    }
                }
            }
        }
    }
    
    vector<int> ord;
    int curS = (1<<n)-1, curV = 0;
    while(tr[curS][curV]!=make_pair(curS, curV))
    {
        ord.push_back(curV);
        pair<int,int> tmp = tr[curS][curV];
        curS = tmp.first;
        curV = tmp.second;
    }
    ord.push_back(curV);
    reverse(ord.begin(), ord.end());
    t_end = clock();
    double diff = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    
    ofstream out;
    out.open("DP.txt");
    out  << "Solution : " << "0";
    for(int i=0 ; i<ord.size() ; ++i)
        out << " - " << ord[i];
    out << "\nCost     : " << dp[(1<<n)-1][0] << "\nTime     : " << fixed << diff << " s";
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream input;
    input.open("input.txt");
    input >> n;
    for(int i=0 ; i<n ; ++i)
        for(int j=0; j<n ; ++j)
            input >> cost[i][j];

    BF(); // Brute Force Method
    BB(); // Branch and Bound Method
    // DP(); //DP is Dynamic Programming Method
    return 0;
}
