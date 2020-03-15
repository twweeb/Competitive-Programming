//
//  main.cpp
//  (#12165) Inversion Pair
//
//  Created by LeiHsiung on 2019/3/6.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int Max = 100000000;
int cnt = 0;

void Merge(std::vector<int> &Array, int front, int mid, int end){
    
    vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1),
    RightSub(Array.begin()+mid+1, Array.begin()+end+1);
    
    LeftSub.insert(LeftSub.end(), Max);
    RightSub.insert(RightSub.end(), Max);
    
    int idxLeft = 0, idxRight = 0;
    
    for (int i = front; i <= end; i++) {
        
        if (LeftSub[idxLeft] <= RightSub[idxRight] ) {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else{
            cnt += mid+1-front-idxLeft;
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(vector<int> &array, int front, int end){
    if (front < end) {
        int mid = (front+end)/2;
        MergeSort(array, front, mid);
        MergeSort(array, mid+1, end);
        Merge(array, front, mid, end);
    }
}

int main() {
    
    int num = 0,tmp = 0,n = 0;
        cin >> num;
        cnt = 0;
        tmp = 0;
        vector<int> array;
        
        for(int i = 0;i<num; i++){
            cin >> tmp;
            array.push_back(tmp);
        }
        
        MergeSort(array, 0, num-1);
        
        cout << cnt <<endl;
    return 0;
}
