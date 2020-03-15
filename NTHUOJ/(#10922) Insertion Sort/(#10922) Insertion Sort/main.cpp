//
//  main.cpp
//  (#10922) Insertion Sort
//
//  Created by LeiHsiung on 2019/3/6.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
void insertion_sort(vector<int>& arr, int t)
{
    if(arr.size()==0)
        arr.push_back(t);
    else
    {
        size_t size = arr.size();
        int tmp = arr[size-1];
        arr.push_back(t);
        while(t < tmp)
        {
            cnt++;
            arr[size--] = tmp;
            if(size != 0)
                tmp = arr[size-1];
            else break;
        }
        arr[size] = t;
    }
}

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    while(N--)
    {
        int T = 0,tmp = 0;
        cin >> T;
        vector<int> arr;
        for(int i = 0; i < T; i++)
        {
            cin >> tmp;
            insertion_sort(arr,tmp);
        }
    }
    
    cout << cnt <<endl;
    return 0;
}
