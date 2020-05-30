//
//  main.cpp
//  (#12177) Heap K-difference
//
//  Created by LeiHsiung on 2019/3/11.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <queue> //priority_queue
#include <math.h>

using namespace std;

int N = 0;
int main() {
    int K = 0,sum = 0, diff = 0, kdiff = 0,tmp = 0;
    ios_base::sync_with_stdio(false);
    priority_queue<int, std::vector<int>,greater<int> > arr1,arr2;
    cin >> N;

    for(int i = 0; i <N; i++)
    {
        cin >> tmp;
        arr1.push(tmp);
    }
    for(int i = 0; i <N; i++)
    {
        cin >> tmp;
        arr2.push(tmp);
    }
    
    cin >> K;
    
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < K;j++)
        {
            sum = arr1.top()+arr2.top();
            diff = abs(arr1.top()-arr2.top());
            arr1.pop();
            arr2.pop();
            arr1.push(sum);
            arr2.push(sum);
        }
        kdiff += diff;
    }
    cout << kdiff <<endl;
    return 0;
}
