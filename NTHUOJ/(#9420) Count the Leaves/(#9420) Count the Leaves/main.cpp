//
//  main.cpp
//  (#9420) Count the Leaves
//
//  Created by Magic Bear on 2017/12/21.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>
#include<map>

using namespace std;

int main()
{
    int N;
    while(cin>>N)
    {
        if(N==0) break;
        map<int,int> par;
        for(int i=0 ; i<N ; i++){
            int a,b;
            cin >> a >> b;
            par[a] = 1;
        }
        int root;
        cin >> root;
        cout << N - par.size()+1 << endl;
    }
    return 0;
}

