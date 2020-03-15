//
//  main.cpp
//  Heap - Gas Station
//
//  Created by LeiHsiung on 2019/4/1.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[])
{
    int T = 0, N = 0, M = 0, remain = 0, times = 0;
    bool isPoss = true;
    ios_base::sync_with_stdio(false);
    cin >> T;
    while(T--)
    {
        queue<pair<int,int> > qu;
        priority_queue<int> gas;
        pair<int,int> e;
        cin >> N >> M;
        
        while(N--)
        {
            cin >> e.first >> e.second;
            qu.push(e);
        }
        for(int i = 0; i < M; i++)
        {
            
            if(!qu.empty())
            {
                e = qu.front();
                while(e.first == i){
                    gas.push(e.second);
                    qu.pop();
                    e = qu.front();
                }
            }
            if(remain == 0)
            {
                if(!gas.empty())
                {
                    remain += gas.top();
                    gas.pop();
                    times++;
                }
                else
                {
                    isPoss = false;
                    break;
                }
            }
            //cout << i << ": "<< "remain: "<< remain << "\ttimes: " << times <<endl;
            remain--;
        }
        if(isPoss)
            cout << "Yes " << times << endl;
        else
            cout << "No" << endl;
        isPoss = true;
        remain = times = 0;
    }
    return 0;
}
